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

public slots:
    void applyTreatment(EEGHeadset* nodes);
    void cancelTreatment();

signals:
    void beforeDominantFreq(double beforeDominantFreq);
    void afterDominantFreq(double afterDominantFreq);
    void sendFeedback(double feedbackFreq);
    void captureAllWaves();
    void endAnalysis();

private:
    double calculateDominantFrequency(Waveform* waveform);
    void captureNewWave(Waveform* waveform);
    void simulateTherapy(double dominantFrequency);
    double calculateBasline(QVector<double> dominantFreqs);
    bool cancelled;
};

#endif // TREATMENT_H
