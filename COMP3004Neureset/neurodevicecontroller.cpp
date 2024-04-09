#include "neurodevicecontroller.h"
#include <QDebug>

NeuroDeviceController::NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd)
{
    deviceOn = false;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    manager = new SessionManager();

    display = new Display(stackedWidget);

    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerButton, display, &Display::powerButton);
    connect(display, &Display::uploadSession, this, &NeuroDeviceController::uploadSession);

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
            treatmentLightIndicator->updateState(LightIndicatorState::TreatmentInProgress);
        }
        if (display->getCurrentMenuSelect() == 1)
        {
            qDebug() << "Selected Log Menu";
            display->populateSessionLogs(manager->getSessionLog());
        }
    }
    emit startButton(deviceOn);
}

void NeuroDeviceController::stopButtonPressed()
{
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
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

void NeuroDeviceController::menuButtonPressed() { emit menuButton(deviceOn); }

void NeuroDeviceController::uploadSession(int index)
{
    SessionLog *log = manager->getSessionLog();
    Session *session = &(*log)[index];
    emit uploadToPC(session);
}
