#include "neurodevicecontroller.h"

NeuroDeviceController::NeuroDeviceController(QListWidget* disLabel, QProgressBar* progLabel, QLabel* timerLabel, QDateTimeEdit* dteLabel, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd)
{
    deviceOn = false;

    contactLightIndicator = new LightIndicator(contactInd);
    treatmentLightIndicator = new LightIndicator(treatmentInd);
    contactLostLightIndicator = new LightIndicator(contactLostInd);

    display = new Display(disLabel, progLabel, timerLabel, dteLabel);

    connect(this, &NeuroDeviceController::upArrowButton, display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerButton, display, &Display::powerButton);

    display->moveToThread(&_DISthread);

    sessionManager = new SessionLoger;

    _DISthread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISthread.exit();
    _DISthread.wait();
}

void NeuroDeviceController::upArrowButtonPressed() { emit upArrowButton(); }
void NeuroDeviceController::downArrowButtonPressed() { emit downArrowButton(); }

void NeuroDeviceController::startButtonPressed()
{
    if(display->getCurrentMenuSelect() == 0)
    {
        treatmentLightIndicator->updateState(LightIndicatorState::TreatmentInProgress);
    }
    emit startButton();
}

void NeuroDeviceController::stopButtonPressed()
{
    treatmentLightIndicator->updateState(LightIndicatorState::Off);
    emit stopButton();
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
