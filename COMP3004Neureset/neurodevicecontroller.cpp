#include "neurodevicecontroller.h"
#include <QDebug>

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge, QComboBox* dropdown)
{
    deviceOn = false;
    sesActive = false;
    sesPaused = false;

    numNodesTreated = 0;
    curStep = 0;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    manager = new SessionManager();

    display = new Display(stackedWidget);

    headset = new EEGHeadset();

    this->dropdown = dropdown;

    deviceTime = QDateTime::currentDateTime();

    timer = new QTimer();
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

    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominant);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::addAfterDominant);
    connect(treatment, &Treatment::sendFeedback, this, &NeuroDeviceController::getFeedbackFreq);
    connect(treatment, &Treatment::captureAllWaves, this, &NeuroDeviceController::captureAllWaves);
    connect(this, &NeuroDeviceController::applyTreatment, treatment, &Treatment::applyTreatment);

    connect(this, &NeuroDeviceController::getInitialBaseline, headset, &EEGHeadset::getInitialBaseline);
    connect(headset, &EEGHeadset::startAnalysis, this, &NeuroDeviceController::startAnalysis);
    connect(treatment, &Treatment::endAnalysis, this, &NeuroDeviceController::endAnalysis);

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
            }
            if (sesActive && sesPaused)
            {
                resumeSession();
            }
        }

        if (display->getCurrentMenuSelect() == 1)
        {
            qDebug() << "Selected Log Menu";
            display->populateSessionLogs(manager->getSessionLog());
        }
    }
}

double NeuroDeviceController::calculateBasline(QVector<double>* dominantFreqs)
{
    double sumOfNodes = 0;

   for (int i = 0; i < NUM_NODES; ++i)
   {
       sumOfNodes += dominantFreqs->at(i);
   }

   return sumOfNodes / NUM_NODES;
}

void NeuroDeviceController::getFeedbackFreq(double feedbackFreq)
{
    nodeTreated();
    headset->forwardFeedback(feedbackFreq);
}

void NeuroDeviceController::captureAllWaves()
{
    headset->captureAllWaves();
}

void NeuroDeviceController::addBeforeDominant(double freq)
{
    manager->updateBeforeBaseline(freq);
}

void NeuroDeviceController::addAfterDominant(double freq)
{
    manager->updateAfterBaseline(freq);
}

bool NeuroDeviceController::checkBatteryLevel(int btDrain)
{
    if (batCharge->value() - btDrain <= 0)
    {
        batCharge->setValue(batCharge->minimum());
        powerOff();
        return false;
    }
    if (batCharge->value() - 30 <= 0)
    {
        qDebug() << "WARNING: Battery is low";
    }
    return true;
}

void NeuroDeviceController::startAnalysis()
{
    if (!sesActive || sesPaused) { return; }

    progBar->setValue(progBar->value() + 30);
    if (!checkBatteryLevel(15))
        return;
    batCharge->setValue(batCharge->value() - 15);

    for (int i = 0; i < NUM_NODES; ++i)
    {
        (*headset)[i].captureWave();
    }

    updateGraph(&(*headset)[dropdown->currentIndex()]);

    emit applyTreatment(headset);
    curStep = 1;
}

void NeuroDeviceController::nodeTreated()
{
    if (!sesActive || sesPaused) { return; }

    numNodesTreated += 1;

    progBar->setValue(progBar->value() + 10);
    if (!checkBatteryLevel(5))
        return;
    batCharge->setValue(batCharge->value() - 5);

    if (numNodesTreated == NUM_NODES)
    {
        curStep = 2;
        endAnalysis();
    }
}

void NeuroDeviceController::endAnalysis()
{
    if (!sesActive || sesPaused) { return; }

    progBar->setValue(progBar->value() + 30);
    if (!checkBatteryLevel(15))
        return;
    batCharge->setValue(batCharge->value() - 15);

    endSession();
}

void NeuroDeviceController::stopButtonPressed()
{
    if (deviceOn && sesActive)
    {
        endSession();
        treatmentLightIndicator->updateState(LightIndicatorState::Off);
        sesActive = false;
        emit stopButton();
        treatment->cancelTreatment();
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
    updateGraph(nullptr);
    headset->clearNodes();
    resetTimer();
    manager->createSession(deviceTime);
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));
    elTimer->start();
    emit getInitialBaseline();
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
    emit menuButton();
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
            break;

        case 1:
            if (numNodesTreated == NUM_NODES)
            {
                curStep = 2;
            }

            else
            {
                qDebug() << "Restart Treating Node:" << numNodesTreated + 1;
            }
            break;

        case 2:
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
    pausedTime = 0;
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
    if (deviceOn)
    {
        updateGraph(&(*headset)[index]);
    }

    //Otherwise keep graph blank
}
