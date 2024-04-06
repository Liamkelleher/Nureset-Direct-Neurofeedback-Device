#ifndef NEURODEVICECONTROLLER_H
#define NEURODEVICECONTROLLER_H

#include <QThread>
#include "display.h"
#include "LightIndicator.h"
#include "Sessionloger.h"


class NeuroDeviceController: public QObject
{
    Q_OBJECT

public:
    NeuroDeviceController(QListWidget* disLabel, QProgressBar* progLabel, QLabel* timerLabel, QDateTimeEdit* dteLabel, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd);
    ~NeuroDeviceController();

public slots:
    void upArrowButtonPressed();
    void downArrowButtonPressed();
    void startButtonPressed();
    void stopButtonPressed();
    void powerButtonPressed();
    void menuButtonPressed();

signals:
    void upArrowButton();
    void downArrowButton();
    void startButton();
    void stopButton();
    void powerButton(bool deviceOn);
    void menuButton(bool deviceOn);

private:
    Display *display;
    QThread _DISthread;
    bool deviceOn;

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;

    // Declare SessionLoger
    SessionLoger *sessionManager;
};

#endif // NEURODEVICECONTROLLER_H
