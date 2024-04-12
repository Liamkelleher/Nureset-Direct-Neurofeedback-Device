#ifndef NEURODEVICECONTROLLER_H
#define NEURODEVICECONTROLLER_H

#include <QThread>
#include <QStackedWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QMetaObject>
#include <QProgressBar>
#include <QComboBox>
#include "display.h"
#include "sessionmanager.h"
#include "eegheadset.h"
#include "LightIndicator.h"
#include "treatment.h"
#include "contactlost.h"


class NeuroDeviceController: public QObject
{
    Q_OBJECT

public:
    NeuroDeviceController(QStackedWidget* stackedWidget, QPushButton* contactInd, QPushButton* treatmentInd, QPushButton* contactLostInd, QProgressBar* progressBar, QProgressBar* batteryCharge, QComboBox* dropdown);
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
    void setDateTime(QDateTime);
    void nodeDisplayChanged(int index);
    void addBeforeDominant(double freqs);
    void addAfterDominant(double freqs);
    void getFeedbackFreq(double feedbackFreq);
    void captureAllWaves();
    void startAnalysis();
    void endAnalysis();   
    void toggleTreatmentLight(bool on);
    void toggleContactLostLight(bool on);
    void terminateConnection();
    void establishConnection();
    void sessionExpired();

signals:
    void upArrowButton();
    void downArrowButton();
    void startButton();
    void stopButton();
    void powerOnDisplay();
    void powerOffDisplay();
    void menuButton();
    void uploadToPC(Session *);
    void updateGraph(EEGNode *);
    void applyTreatment(EEGHeadset *);
    void getInitialBaseline();
    void contactWarning();
    void pausedWarning();

private:
    Display *display;
    QThread _DISThread, _HeadSetThread, _TreatThread, _CLThread;
    bool deviceOn, sesActive, sesPaused, connection, sessionCreated;
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
    QComboBox *dropdown;

    ContactLost* contactLost;

    void resetTimer();
    void powerOff();
    double calculateBasline(QVector<double>* dominantFreqs);
    void nodeTreated();
    bool checkBatteryLevel(int);
};

#endif // NEURODEVICECONTROLLER_H
