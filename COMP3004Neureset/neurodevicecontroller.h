#ifndef NEURODEVICECONTROLLER_H
#define NEURODEVICECONTROLLER_H

#include <QThread>
#include <QStackedWidget>
#include "display.h"
#include "sessionmanager.h"
#include "LightIndicator.h"


class NeuroDeviceController: public QObject
{
    Q_OBJECT

public:
    NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd);
    ~NeuroDeviceController();

public slots:
    void upArrowButtonPressed();
    void downArrowButtonPressed();
    void startButtonPressed();
    void stopButtonPressed();
    void powerButtonPressed();
    void menuButtonPressed();
    void uploadSession(int);

signals:
    void upArrowButton(bool deviceOn);
    void downArrowButton(bool deviceOn);
    void startButton(bool deviceOn);
    void stopButton(bool deviceOn);
    void powerButton(bool deviceOn);
    void menuButton(bool deviceOn);
    void uploadToPC(Session *);

private:
    Display *display;
    QThread _DISthread;
    bool deviceOn;

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;

    SessionManager *manager;
};

#endif // NEURODEVICECONTROLLER_H
