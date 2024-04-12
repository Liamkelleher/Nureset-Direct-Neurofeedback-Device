#include "neurodevicecontroller.h"
#include <QDebug>

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge)
{
    deviceOn = false;
    sesActive = false;
    sesPaused = true;

    numNodesTreated = 0;
    curStep = 0;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    manager = new SessionManager();

    display = new Display(stackedWidget);

    headset = new EEGHeadset();

    deviceTime = QDateTime::currentDateTime();

    timer = new QTimer(this);
    elTimer = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUiTimer()));
    savedTime = 0;

    progBar = progressBar;
    batCharge = batteryCharge;

    treatment = new Treatment();

    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerOffDisplay, display, &Display::powerOffDisplay);
    connect(this, &NeuroDeviceController::powerOnDisplay, display, &Display::powerOnDisplay);

    connect(this, &NeuroDeviceController::getBaseLine, headset, &EEGHeadset::getBaseLine);
    connect(headset, &EEGHeadset::returnBaseLine, this, &NeuroDeviceController::returnBaseLine);

    connect(this, &NeuroDeviceController::getTreatedBaseLine, headset, &EEGHeadset::getTreatedBaseLine);
    connect(headset, &EEGHeadset::returnTreatedBaseLine, this, &NeuroDeviceController::returnTreatedBaseLine);

//    connect(this, &NeuroDeviceController::treatNodes, treatment, &Treatment::treatNodes);
    connect(treatment, &Treatment::nodeTreated, this, &NeuroDeviceController::nodeTreated);
    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominants);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::addAfterDominants);
    connect(treatment, &Treatment::sendFeedback, this, &NeuroDeviceController::getFeedbackFreq);


    connect(display, &Display::uploadSession, this, &NeuroDeviceController::uploadSession);
    connect(display, &Display::updateDateTime, this, &NeuroDeviceController::setDateTime);

    display->moveToThread(&_DISThread);
    headset->moveToThread(&_HeadSetThread);
    treatment->moveToThread(&_TreatThread);

    _DISThread.start();
    _HeadSetThread.start();
    _TreatThread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISThread.exit();
    _DISThread.wait();

    _HeadSetThread.exit();
    _HeadSetThread.wait();

    _TreatThread.exit();
    _TreatThread.wait();
}

void NeuroDeviceController::upArrowButtonPressed() { if (deviceOn) { emit upArrowButton(); } }
void NeuroDeviceController::downArrowButtonPressed() { if (deviceOn) { emit downArrowButton(); } }

void NeuroDeviceController::startButtonPressed()
{
    if (deviceOn)
    {
        emit startButton();

        if (display->getCurrentMenuSelect() == 0)
        {
            if (!sesActive)
            {
                startSession();
                treatmentLightIndicator->updateState(LightIndicatorState::TreatmentInProgress);
                sesActive = true;

                emit getBaseLine();
                qDebug() << "Getting Baseline";

            }
        }

        if (display->getCurrentMenuSelect() == 1)
        {
            qDebug() << "Selected Log Menu";
            display->populateSessionLogs(manager->getSessionLog());
        }

        if (sesActive && sesPaused)
        {
            resumeSession();
        }
    }
}

void NeuroDeviceController::getFeedbackFreq(double feedbackFreq, int node){emit forwardFeedback(feedbackFreq, node);}

void NeuroDeviceController::addBeforeDominants(double freq)
{
    beforeDominantFreqs.push_back(freq);
}

void NeuroDeviceController::addAfterDominants(double freq)
{
    afterDominantFreqs.push_back(freq);
}

void NeuroDeviceController::returnBaseLine()
{
    if (!sesActive || sesPaused) { return; }

    progBar->setValue(progBar->value() + 15);
    batCharge->setValue(batCharge->value() - 7);

    if (batCharge->value() - 7 <= 0)
    {
        batCharge->setValue(batCharge->minimum());
        powerOff();
        return;
    }

    //collect all the nodes and call treatment on all of them

    //emit treatNodes(headset->operator[](i));
//    emit treatNodes();
    qDebug() << "Treating Node: 1";

    curStep = 1;
}

void NeuroDeviceController::nodeTreated()
{
    if (!sesActive || sesPaused) { return; }

    numNodesTreated += 1;
    qDebug() << "Node Treated";

    progBar->setValue(progBar->value() + 10);
    batCharge->setValue(batCharge->value() - 5);

    if (batCharge->value() - 5 <= 0)
    {
        batCharge->setValue(batCharge->minimum());
        powerOff();
        return;
    }

    if (numNodesTreated == NUM_NODES)
    {
        emit getTreatedBaseLine();
        qDebug() << "Getting Treated Baseline";

        curStep = 2;
    }

    else
    {
        //emit treatNodes(headset->operator[](i));
        emit treatNodes();
        qDebug() << "Treating Node:" << numNodesTreated + 1;
    }
}

void NeuroDeviceController::returnTreatedBaseLine()
{
    if (!sesActive || sesPaused) { return; }

    progBar->setValue(progBar->value() + 15);
    batCharge->setValue(batCharge->value() - 8);

    if (batCharge->value() - 8 <= 0)
    {
        batCharge->setValue(batCharge->minimum());
        powerOff();
        return;
    }

    endSession();
    qDebug() << "Session Complete";
}

void NeuroDeviceController::stopButtonPressed()
{
    if (deviceOn && sesActive)
    {
        endSession();
        emit stopButton();

        treatmentLightIndicator->updateState(LightIndicatorState::Off);
        emit stopButton();
        sesActive = false;
    }
}

void NeuroDeviceController::powerButtonPressed()
{
    if (batCharge->value() <= 0) { return; }

    if(deviceOn)
    {
        powerOff();
    }

    else
    {
        //Bootup Protocols
        contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);

        emit powerOnDisplay();

        deviceOn = true;
    }
}

void NeuroDeviceController::powerOff()
{
    if(sesActive)
    {
        endSession();
        sesActive = false;
    }

    //Shutdown Protocols
    contactLightIndicator->updateState(LightIndicatorState::Off);
    treatmentLightIndicator->updateState(LightIndicatorState::Off);

    emit powerOffDisplay();

    deviceOn = false;
}

void NeuroDeviceController::menuButtonPressed()
{
    if (deviceOn && !sesActive)
    {
        emit menuButton();
    }

    else
    {
        qDebug() << "Session currently active, cannot go back to main menu.";
    }
}

void NeuroDeviceController::uploadSession(int index)
{
    SessionLog *log = manager->getSessionLog();
    Session *session = &(*log)[index];
    emit uploadToPC(session);
}

void NeuroDeviceController::startSession()
{
    sesActive = true;
    sesPaused = false;
    resetTimer();
    manager->createSession(deviceTime);
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));
    elTimer->start();
}

void NeuroDeviceController::endSession()
{
    curStep = 0;
    numNodesTreated = 0;

    qint64 finalTime = savedTime;
    if (!sesPaused)
        finalTime += elTimer->elapsed();
    manager->endSession(QTime(0,0).addMSecs(static_cast<int>(finalTime)));
    sesActive = false;
    sesPaused = true;
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
    resetTimer();
    progBar->setValue(progBar->minimum());
    display->updateTimer(0);
    display->menuButton();
}

void NeuroDeviceController::pauseSession()
{
    if (sesActive)
    {
        sesPaused = true;
        savedTime += elTimer->elapsed();
        QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection);
        elTimer->invalidate();
    }
}

void NeuroDeviceController::resumeSession()
{
    sesPaused = false;
    if (!elTimer->isValid())
    {
        elTimer->restart();
    }
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));

    switch(curStep)
    {
        case 0:
            emit returnBaseLine();
            qDebug() << "Restart With Baseline";
            break;

        case 1:
            if (numNodesTreated == NUM_NODES)
            {
                emit getTreatedBaseLine();
                qDebug() << "Getting Treated Baseline";

                curStep = 2;
            }

            else
            {
                //emit treatNodes(headset->operator[](i));
                emit treatNodes();
                qDebug() << "Restart Treating Node:" << numNodesTreated + 1;
            }
            break;

        case 2:
            emit returnTreatedBaseLine();
            qDebug() << "Restart With Treated Baseline";
            break;
    }

}

void NeuroDeviceController::resetTimer()
{
    if (timer->isActive()) {
        QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection); // Ensures timer is stopped before resetting
    }

    elTimer->invalidate();
    savedTime = 0;
}


void NeuroDeviceController::updateUiTimer()
{
    qint64 msecsElapsed = savedTime + elTimer->elapsed();
    display->updateTimer(msecsElapsed);
}

void NeuroDeviceController::setDateTime(QDateTime newDateTime)
{
    this->deviceTime = newDateTime;
}

void NeuroDeviceController::nodeDisplayChanged(int index)
{
    if (sesActive)
    {
        //Update graph
    }

    //Otherwise keep graph blank
}
