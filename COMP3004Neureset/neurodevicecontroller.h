#ifndef NEURODEVICECONTROLLER_H
#define NEURODEVICECONTROLLER_H

#include <QThread>
#include <QStackedWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QMetaObject>
#include <QProgressBar>
#include "display.h"
#include "sessionmanager.h"
#include "eegheadset.h"
#include "LightIndicator.h"
#include "treatment.h"


class NeuroDeviceController: public QObject
{
    Q_OBJECT

public:
    NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge);
    ~NeuroDeviceController();

    void startSession();
    void endSession();
    void resumeSession();

public slots:
    void upArrowButtonPressed();
    void downArrowButtonPressed();
    void startButtonPressed();
    void stopButtonPressed();
    void powerButtonPressed();
    void menuButtonPressed();
    void uploadSession(int);
    void updateUiTimer();
    void pauseSession();
    void returnBaseLine();
    void nodeTreated(double freq);
    void returnTreatedBaseLine();
    void setDateTime(QDateTime);
    void nodeDisplayChanged(int index);
<<<<<<< HEAD
=======
    void addBeforeDominants(double freqs);
    void getFeedbackFreq(double feedbackFreq, int node);
    void captureWave(int node);
>>>>>>> 126fcbf (added more)

signals:
    void upArrowButton();
    void downArrowButton();
    void startButton();
    void stopButton();
    void powerOnDisplay();
    void powerOffDisplay();
    void menuButton();
    void getBaseLine();
    void getTreatedBaseLine();
    void uploadToPC(Session *);
    void updateGraph(EEGNode*);

private:
    Display *display;
    QThread _DISThread, _HeadSetThread, _TreatThread;
    bool deviceOn, sesActive, sesPaused;
    int numNodesTreated, curStep;

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;

    SessionManager *manager;

    EEGHeadset *headset;
    QDateTime deviceTime;
    QTimer* timer;
    QElapsedTimer *elTimer;
    qint64 savedTime;
    qint64 pausedTime;

    QProgressBar *progBar, *batCharge;
    Treatment* treatment;

    void resetTimer();
    void powerOff();
};

#endif // NEURODEVICECONTROLLER_H
