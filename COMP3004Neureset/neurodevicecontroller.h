#ifndef NEURODEVICECONTROLLER_H
#define NEURODEVICECONTROLLER_H

#include <QThread>
#include "display.h"


class NeuroDeviceController: public QObject
{
    Q_OBJECT

public:
    NeuroDeviceController();
    ~NeuroDeviceController();

    void setupNDC(QListWidget *disLabel, QProgressBar *progLabel, QLabel *timerLabel, QDateTimeEdit *dteLabel);

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
    Display display;
    QThread _DISthread;
    bool deviceOn;
};

#endif // NEURODEVICECONTROLLER_H
