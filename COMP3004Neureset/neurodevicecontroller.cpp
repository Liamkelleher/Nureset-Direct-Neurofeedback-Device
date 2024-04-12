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

<<<<<<< HEAD
    connect(this, &NeuroDeviceController::getBaseLine, headset, &EEGHeadset::getBaseLine);
    connect(headset, &EEGHeadset::returnBaseLine, this, &NeuroDeviceController::returnBaseLine);

    connect(this, &NeuroDeviceController::getTreatedBaseLine, headset, &EEGHeadset::getTreatedBaseLine);
    connect(headset, &EEGHeadset::returnTreatedBaseLine, this, &NeuroDeviceController::returnTreatedBaseLine);

<<<<<<< HEAD
    connect(this, &NeuroDeviceController::treatNodes, treatment, &Treatment::treatNodes);
    connect(treatment, &Treatment::nodeTreated, this, &NeuroDeviceController::nodeTreated);
=======
    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominants);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::nodeTreated);
=======
    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominant);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::addAfterDominant);
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
    connect(treatment, &Treatment::sendFeedback, this, &NeuroDeviceController::getFeedbackFreq);
    connect(treatment, &Treatment::captureAllWaves, this, &NeuroDeviceController::captureAllWaves);
    connect(this, &NeuroDeviceController::applyTreatment, treatment, &Treatment::applyTreatment);

<<<<<<< HEAD
>>>>>>> 126fcbf (added more)
=======
    connect(this, &NeuroDeviceController::getInitialBaseline, headset, &EEGHeadset::getInitialBaseline);
    connect(headset, &EEGHeadset::startAnalysis, this, &NeuroDeviceController::startAnalysis);
    connect(treatment, &Treatment::endAnalysis, this, &NeuroDeviceController::endAnalysis);
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
void NeuroDeviceController::getFeedbackFreq(double feedbackFreq, int node){emit forwardFeedback(feedbackFreq, node);}
=======
=======
double NeuroDeviceController::calculateBasline(QVector<double> dominantFreqs)
=======
double NeuroDeviceController::calculateBasline(QVector<double>* dominantFreqs)
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
{
    double sumOfNodes = 0;

   for (int i = 0; i < NUM_NODES; ++i)
   {
       sumOfNodes += dominantFreqs->at(i);
   }

   return sumOfNodes / NUM_NODES;
}

<<<<<<< HEAD
>>>>>>> d450c75 (baseline calcs)
void NeuroDeviceController::getFeedbackFreq(double feedbackFreq, int node)
=======
void NeuroDeviceController::getFeedbackFreq(double feedbackFreq)
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
{
    nodeTreated();
    headset->forwardFeedback(feedbackFreq);
}
>>>>>>> fbd85c6 (did more stuff)

void NeuroDeviceController::captureAllWaves()
{
    headset->captureAllWaves();
}

void NeuroDeviceController::addBeforeDominant(double freq)
{
    manager->updateBeforeBaseline(freq);
}

<<<<<<< HEAD
>>>>>>> 126fcbf (added more)
void NeuroDeviceController::returnBaseLine()
=======
void NeuroDeviceController::addAfterDominant(double freq)
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    //emit treatNodes(headset->operator[](i));
    emit treatNodes();
    qDebug() << "Treating Node: 1";
=======
=======
    // calculate avg baseline before
    double beforeBaseline = calculateBasline(beforeDominantFreqs);
    manager->updateBeforeBaseline(beforeBaseline);
=======
void NeuroDeviceController::startAnalysis()
{
    if (!sesActive || sesPaused) { return; }

    progBar->setValue(progBar->value() + 30);
    if (!checkBatteryLevel(15))
        return;
    batCharge->setValue(batCharge->value() - 15);
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

>>>>>>> d450c75 (baseline calcs)
    for (int i = 0; i < NUM_NODES; ++i)
    {
        (*headset)[i].captureWave();
    }

<<<<<<< HEAD
<<<<<<< HEAD
    // calculate avg baseline
>>>>>>> 126fcbf (added more)
=======
>>>>>>> d450c75 (baseline calcs)
=======
    updateGraph(&(*headset)[dropdown->currentIndex()]);
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

    emit applyTreatment(headset);
    curStep = 1;
}

void NeuroDeviceController::nodeTreated()
{
    if (!sesActive || sesPaused) { return; }

    numNodesTreated += 1;

    progBar->setValue(progBar->value() + 10);
<<<<<<< HEAD
    batCharge->setValue(batCharge->value() - 5);

    if (batCharge->value() - 5 <= 0)
    {
        batCharge->setValue(batCharge->minimum());
        powerOff();
        treatment->cancelTreatment();
=======
    if (!checkBatteryLevel(5))
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
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
    }

    //Shutdown Protocols
    contactLightIndicator->updateState(LightIndicatorState::Off);
    treatmentLightIndicator->updateState(LightIndicatorState::Off);

    emit powerOffDisplay();

    deviceOn = false;
    sesActive = false;
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
<<<<<<< HEAD
        emit updateGraph(&(*headset)[index]);
=======
        updateGraph(&(*headset)[index]);
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
    }

    //Otherwise keep graph blank
}
