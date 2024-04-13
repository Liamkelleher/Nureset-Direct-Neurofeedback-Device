#include "neurodevicecontroller.h"
#include <QDebug>

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge, QComboBox* dropdown)
{
    deviceOn = false;
    sesActive = false;
    sesPaused = false;
    connection = true;
    sessionCreated = false;
    roundsCompleted = 0;
    currStep = 0;
    isExpired = false;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    manager = new SessionManager();

    display = new Display(stackedWidget);

    headset = new EEGHeadset();

    this->dropdown = dropdown;

    deviceTime = QDateTime::currentDateTime();

    timer = new QTimer(this);
    elTimer = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUiTimer()));
    savedTime = 0;

    progBar = progressBar;
    batCharge = batteryCharge;

    treatment = new Treatment();

    contactLost = new ContactLost();

    connect(this, &NeuroDeviceController::setValueBat, batCharge, &QProgressBar::setValue);
    connect(this, &NeuroDeviceController::setValueProg, progBar, &QProgressBar::setValue);
    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerOffDisplay, display, &Display::powerOffDisplay);
    connect(this, &NeuroDeviceController::powerOnDisplay, display, &Display::powerOnDisplay);
    connect(display, &Display::uploadSession, this, &NeuroDeviceController::uploadSession);
    connect(display, &Display::updateDateTime, this, &NeuroDeviceController::setDateTime);
    connect(this, &NeuroDeviceController::sessionComplete, display, &Display::sessionComplete);
    connect(this, &NeuroDeviceController::applyTreatment, treatment, &Treatment::applyTreatment);
    connect(this, &NeuroDeviceController::togglePause, treatment, &Treatment::togglePauseTreatment);
    connect(this, &NeuroDeviceController::resumeTreatment, treatment, &Treatment::resumeTreatment);
    connect(treatment, &Treatment::beforeDominantFreq, this, &NeuroDeviceController::addBeforeDominant);
    connect(treatment, &Treatment::afterDominantFreq, this, &NeuroDeviceController::addAfterDominant);
    connect(treatment, &Treatment::sendFeedback, this, &NeuroDeviceController::getFeedbackFreq);
    connect(treatment, &Treatment::captureAllWaves, this, &NeuroDeviceController::captureAllWaves);
    connect(treatment, &Treatment::endAnalysis, this, &NeuroDeviceController::endAnalysis);
    connect(treatment, &Treatment::toggleTreatmentLight, this, &NeuroDeviceController::toggleTreatmentLight);
    connect(this, &NeuroDeviceController::getInitialBaseline, headset, &EEGHeadset::getInitialBaseline);
    connect(headset, &EEGHeadset::startAnalysis, this, &NeuroDeviceController::startAnalysis);
    connect(this, &NeuroDeviceController::pausedWarning, contactLost, &ContactLost::pausedWarning);
    connect(this, &NeuroDeviceController::contactWarning, contactLost, &ContactLost::contactWarning);
    connect(contactLost, &ContactLost::toggleContactLostLight, this, &NeuroDeviceController::toggleContactLostLight);
    connect(contactLost, &ContactLost::sessionExpired, this, &NeuroDeviceController::sessionExpired);

    display->moveToThread(&_DISThread);
    headset->moveToThread(&_HeadSetThread);
    treatment->moveToThread(&_TreatThread);
    contactLost->moveToThread(&_CLThread);

    _DISThread.start();
    _HeadSetThread.start();
    _TreatThread.start();
    _CLThread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISThread.exit();
    _DISThread.wait();

    _HeadSetThread.exit();
    _HeadSetThread.wait();

    _TreatThread.exit();
    _TreatThread.wait();

    _CLThread.exit();
    _CLThread.wait();
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
            if (!connection)
            {
                qDebug() << "\n\nINFO: Cannot start session. Please re-establish connection.\n\n";
                emit menuButton();
            }
            if (!sesActive && connection)
            {
                contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);
                startSession();
            }
        }

        if (display->getCurrentMenuSelect() == 1)
        {
            display->populateSessionLogs(manager->getSessionLog());
        }

        if (sesActive && sesPaused && connection)
        {
            resumeSession();
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

void NeuroDeviceController::getFeedbackFreq()
{
    nodeTreated();
}

void NeuroDeviceController::captureAllWaves() { headset->captureAllWaves(); }

void NeuroDeviceController::addBeforeDominant(double freq) { manager->updateBeforeBaseline(freq); }
void NeuroDeviceController::addAfterDominant(double freq) { manager->updateAfterBaseline(freq); }

bool NeuroDeviceController::checkBatteryLevel(int btDrain)
{
    if (batCharge->value() - btDrain <= 0)
    {
        qDebug() << "\nINFO: Device battery has died";
        updateBattery(batCharge->minimum());
        powerOff();
        return false;
    }
    if (batCharge->value() - 30 <= 0)
    {
        qDebug() << "WARNING: Battery is low";
    }
    return true;
}

void NeuroDeviceController::updateProgressBar(int value)
{
    int increment = (value - progBar->value()) / 10;

    // The QTimer's timeout signal will call the lambda function
    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, [this, value, increment, timer]() {
        // Increment the progress bar's value
        int newValue = progBar->value() + increment;

        // Ensure the new value does not exceed the final value
        if ((increment > 0 && newValue > value) ||
            (increment < 0 && newValue < value)) {
            newValue = value;
        }

        // Update the progress bar and check if we've reached the final value
        emit setValueProg(newValue);
        if (newValue == value) {
            timer->stop();
            timer->deleteLater();

            if (newValue == progBar->maximum())
            {
                sesActive = false;
                emit sessionComplete();

            }
        }
    });
}

void NeuroDeviceController::updateBattery(int value)
{
    int currentValue = batCharge->value();

    int increment = (value - currentValue) / 10;
    if (increment == 0) {
        increment = (value != currentValue) ? (value > currentValue ? 1 : -1) : 0;
    }

    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, [this, timer, value, increment]() mutable {
        int newValue = batCharge->value() + increment;

        if ((increment > 0 && newValue >= value) || (increment < 0 && newValue <= value)) {
            newValue = value;
            emit setValueBat(newValue);
            timer->stop();
            timer->deleteLater();
        } else {
            emit setValueBat(newValue);
        }
    });
}

void NeuroDeviceController::startAnalysis()
{
    if (!sesActive || sesPaused) { return; }
    updateProgressBar(progBar->value() + 30);
    if (!checkBatteryLevel(15))
        return;
    updateBattery(batCharge->value() - 15);

    for (int i = 0; i < NUM_NODES; ++i)
    {
        (*headset)[i].captureWave();
    }

    emit updateGraph(&(*headset)[dropdown->currentIndex()]);
    emit applyTreatment(headset);
    ++currStep;
}

void NeuroDeviceController::nodeTreated()
{
    if (!sesActive || sesPaused) { return; }

    roundsCompleted += 1;
    updateProgressBar((progBar->value() + 10));
    if (!checkBatteryLevel(5))
        return;
    updateBattery(batCharge->value() - 5);
    emit updateGraph(&(*headset)[dropdown->currentIndex()]);

    if (roundsCompleted == 4)
    {
        ++currStep;
    }
}

void NeuroDeviceController::endAnalysis()
{
    if (!sesActive || sesPaused) { return; }
    qDebug() << "INFO: Therapy has finished\n\n";
    updateProgressBar(progBar->value() + (progBar->maximum() - progBar->value()));
    if (!checkBatteryLevel(15))
        return;
    updateBattery(batCharge->value() - 15);
    QTimer::singleShot(3000, this, SLOT(endSession()));
}

void NeuroDeviceController::stopButtonPressed()
{
    if (deviceOn && sesActive)
    {
        qDebug() << "\n\nINFO: Therapy has been cancelled\n\n";
        endSession();
        sesActive = false;
        emit stopButton();
        treatment->cancelTreatment();
        treatmentLightIndicator->updateState(LightIndicatorState::Off);
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

    treatment->cancelTreatment();

    emit powerOffDisplay();

    connection = true;
    sesPaused = false;
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
    currStep = 0;
    roundsCompleted = 0;
    display->updateTimer(0);
    emit setValueProg(0);
    emit updateGraph(nullptr);
    headset->clearNodes();
    resetTimer();
    manager->createSession(deviceTime);
    isExpired = false;
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));
    elTimer->start();
    ++currStep;
    qDebug() << "\n\nINFO: Therapy has started\n";
    qDebug() << "TREATMENT: Processing input wave signals";
    emit getInitialBaseline();
}

void NeuroDeviceController::endSession()
{
    roundsCompleted = 0;
    currStep = 0;
    qint64 finalTime = savedTime;
    if (!sesPaused)
        finalTime += elTimer->elapsed();
    manager->endSession(QTime(0,0).addMSecs(static_cast<int>(finalTime)), !isExpired);
    isExpired = false;
    sesActive = false;
    sesPaused = true;
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
    contactLightIndicator->updateState(LightIndicatorState::Off);
    resetTimer();
    emit setValueProg(progBar->minimum());
    display->updateTimer(0);
    emit menuButton();
}

void NeuroDeviceController::pauseSession()
{
    if (sesPaused)
        return;
    if (sesActive)
    {
        if (connection)
        {
            contactLost->setPausedState(true);
            treatment->togglePauseTreatment(true);
            emit pausedWarning();
        } else {
            treatment->togglePauseTreatment(true);
        }
        qDebug() << "INFO: Therapy paused";
        sesPaused = true;
        savedTime += elTimer->elapsed();
        QMetaObject::invokeMethod(timer, "stop", Qt::QueuedConnection);
        elTimer->invalidate();
    }
}

void NeuroDeviceController::resumeSession()
{
    if (!sesPaused)
        return;
    sesPaused = false;
    contactLost->setPausedState(false);
    treatment->togglePauseTreatment(false);

    if (!elTimer->isValid())
    {
        elTimer->restart();
    }
    QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000));

    switch (currStep){
        case 1:
        // restart analysis from begining
            qDebug() << "\nINFO: Restarting treatment\n";
            qDebug() << "TREATMENT: Processing input wave signals";
            emit getInitialBaseline();
            break;
        case 2:
        // resume to current round
            qDebug() << "INFO: Resuming treatment at round " << roundsCompleted + 1 << "\n";
            switch(roundsCompleted)
            {
            case 0:
                emit resumeTreatment(currStep, roundsCompleted + 1);
                break;
            case 1:
                emit resumeTreatment(currStep, roundsCompleted + 1);
                break;
            case 2:
                emit resumeTreatment(currStep, roundsCompleted + 1);
                break;
            case 3:
                emit resumeTreatment(currStep, roundsCompleted + 1);
                break;

            }
            break;
        case 3:
        // restart after baseline calculation
            qDebug("\nINFO: Resuming treatment at after baseline calculation\n");
            emit resumeTreatment(currStep, -1);
            break;
        default:
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
        emit updateGraph(&(*headset)[index]);
    }
}

void NeuroDeviceController::toggleTreatmentLight(bool on)
{
    if (on && sesActive && !sesPaused)
    {
        treatmentLightIndicator->updateState(LightIndicatorState::TreatmentInProgress);
    }
    else
    {
        treatmentLightIndicator->updateState(LightIndicatorState::Off);
    }
}

void NeuroDeviceController::toggleContactLostLight(bool on)
{
    if (on)
    {
        contactLostLightIndicator->updateState(LightIndicatorState::ContactLost);
    }

    else
    {
        contactLostLightIndicator->updateState(LightIndicatorState::Off);
    }
}

void NeuroDeviceController::terminateConnection()
{
    if (connection == true && deviceOn)
    {
        qDebug() << "";
        connection = false;
        contactLost->setContactState(true);
        if (sesActive && !sesPaused)
        {
            pauseSession();
        }
        emit contactWarning();
    }
}

void NeuroDeviceController::establishConnection()
{
    if (connection == false && deviceOn)
    {
        connection = true;
        contactLost->setContactState(false);
        if (sesActive && sesPaused)
            resumeSession();
    }
}

void NeuroDeviceController::sessionExpired()
{
    qDebug() << "\n\nINFO: Session Expired, device turned off.\n\n";
    isExpired = true;
    powerOff();
}
