#ifndef TREATMENT_H
#define TREATMENT_H

#include <QDebug>
#include <cmath>
#include <QRandomGenerator>
#include "waveform.h"
#include "defs.h"

class Treatment: public QObject {
    Q_OBJECT;
public:
    void applyTreatment(Waveform& waveform, int node);

signals:
    void nodeTreated(double newDominant);
    void beforeDominantFreq(double beforeDominantFreq);
    void afterDominantFreq(double afterDominantFreq);
    void sendFeedback(double feedbackFreq, int node);

private:
    double calculateDominantFrequency(Waveform& waveform);
    void captureNewWave(Waveform& waveform);
    void simulateTherapy(double dominantFrequency, int node);
};

#endif // TREATMENT_H
