#ifndef TREATMENT_H
#define TREATMENT_H

#include <QDebug>
#include <cmath>
#include <QThread>
#include <QRandomGenerator>
#include "waveform.h"
#include "eegheadset.h"
#include "defs.h"

class Treatment: public QObject {
    Q_OBJECT;

public:
    Treatment();
    void togglePauseTreatment(bool);

public slots:
    void applyTreatment(EEGHeadset* nodes);
    void cancelTreatment();
    void resumeTreatment(int, int);

signals:
    void beforeDominantFreq(double beforeDominantFreq);
    void afterDominantFreq(double afterDominantFreq);
    void sendFeedback(double feedbackFreq);
    void captureAllWaves();
    void endAnalysis();
    void toggleTreatmentLight(bool on);

private:
    double calculateDominantFrequency(Waveform* waveform);
    void captureNewWave(Waveform* waveform);
    void simulateTherapy(double dominantFrequency, int round);
    double calculateBasline(QVector<double> dominantFreqs);
    void calculateAfter();
    bool cancelled, paused;
    EEGHeadset* nodes;
    double domFreq;
};

#endif // TREATMENT_H
