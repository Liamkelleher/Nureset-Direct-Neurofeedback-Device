#include "neurodevicecontroller.h"

NeuroDeviceController::NeuroDeviceController()
{
    deviceOn = false;

    connect(this, &NeuroDeviceController::upArrowButton, &display, &Display::upArrowButton);
    connect(this, &NeuroDeviceController::downArrowButton, &display, &Display::downArrowButton);
    connect(this, &NeuroDeviceController::startButton, &display, &Display::startButton);
    connect(this, &NeuroDeviceController::stopButton, &display, &Display::stopButton);
    connect(this, &NeuroDeviceController::menuButton, &display, &Display::menuButton);
    connect(this, &NeuroDeviceController::powerButton, &display, &Display::powerButton);

    display.moveToThread(&_DISthread);

    _DISthread.start();
}

NeuroDeviceController::~NeuroDeviceController()
{
    _DISthread.exit();
    _DISthread.wait();
}

void NeuroDeviceController::setupNDC(QListWidget *disLabel, QProgressBar *progLabel, QLabel *timerLabel, QDateTimeEdit *dteLabel)
{
    display.setupDisplay(disLabel, progLabel, timerLabel, dteLabel);
}

void NeuroDeviceController::upArrowButtonPressed() { emit upArrowButton(); }
void NeuroDeviceController::downArrowButtonPressed() { emit downArrowButton(); }
void NeuroDeviceController::startButtonPressed() { emit startButton(); }
void NeuroDeviceController::stopButtonPressed() { emit stopButton(); }

void NeuroDeviceController::powerButtonPressed()
{
    emit powerButton(deviceOn);

    if(deviceOn)
    {
        //Shutdown Protocols

        deviceOn = false;
    }

    else
    {
        //Bootup Protocols

        deviceOn = true;
    }


}

void NeuroDeviceController::menuButtonPressed() { emit menuButton(deviceOn); }
