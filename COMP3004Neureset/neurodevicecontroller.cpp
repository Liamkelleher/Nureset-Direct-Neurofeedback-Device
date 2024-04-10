#include "neurodevicecontroller.h"
#include <QDebug>

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd)
{
    deviceOn = false;
    sesActive = false;
    sesPaused = true;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    manager = new SessionManager();

    display = new Display(stackedWidget);

    deviceTime = QDateTime::currentDateTime();

    timer = new QTimer();
    elTimer = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateUiTimer()));
    savedTime = 0;

    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerButton, display, &Display::powerButton);
    connect(display, &Display::uploadSession, this, &NeuroDeviceController::uploadSession);
    connect(display, &Display::updateDateTime, this, &NeuroDeviceController::setDateTime);

    display->moveToThread(&_DISthread);

    _DISthread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISthread.exit();
    _DISthread.wait();
}

void NeuroDeviceController::upArrowButtonPressed() { emit upArrowButton(deviceOn); }
void NeuroDeviceController::downArrowButtonPressed() { emit downArrowButton(deviceOn); }

void NeuroDeviceController::startButtonPressed()
{
    if (deviceOn)
    {
        if (display->getCurrentMenuSelect() == 0)
        {
            if (!sesActive)
                startSession();
        }
        if (display->getCurrentMenuSelect() == 1)
        {
            display->populateSessionLogs(manager->getSessionLog());
        }
        if (sesActive && sesPaused)
        {
            resumeSession();
        }
    }
    emit startButton(deviceOn);
}

void NeuroDeviceController::stopButtonPressed()
{
    if (sesActive)
        endSession();
    emit stopButton(deviceOn);
}

void NeuroDeviceController::powerButtonPressed()
{
    emit powerButton(deviceOn);

    if(deviceOn)
    {
        //Shutdown Protocols
        contactLightIndicator->updateState(LightIndicatorState::Off);
        treatmentLightIndicator->updateState(LightIndicatorState::Off);

        deviceOn = false;
    }

    else
    {
        //Bootup Protocols
        contactLightIndicator->updateState(LightIndicatorState::ContactEstablished);

        deviceOn = true;
    }


}

void NeuroDeviceController::menuButtonPressed()
{
    if (!sesActive)
        emit menuButton(deviceOn);
    else
        qDebug() << "Session currently active, cannot go back to main menu.";
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
    qint64 finalTime = savedTime;
    if (!sesPaused)
        finalTime += elTimer->elapsed();
    manager->endSession(QTime(0,0).addMSecs(static_cast<int>(finalTime)));
    sesActive = false;
    sesPaused = true;
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
    resetTimer();
    display->updateTimer(0);
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
