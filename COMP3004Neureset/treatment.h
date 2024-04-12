#ifndef TREATMENT_H
#define TREATMENT_H

<<<<<<< HEAD
#include <QObject>
#include <QThread>

class Treatment: public QObject
{
    Q_OBJECT

public:
<<<<<<< HEAD
    Treatment();

    void cancelTreatment();

public slots:
    void treatNodes();
=======
    void applyTreatment(Waveform* waveform, int node);
>>>>>>> fbd85c6 (did more stuff)
=======
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
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

signals:
<<<<<<< HEAD
    void nodeTreated();
=======
    void beforeDominantFreq(double beforeDominantFreq);
    void afterDominantFreq(double afterDominantFreq);
<<<<<<< HEAD
    void sendFeedback(double feedbackFreq, int node);
    void captureWave(int node);
>>>>>>> 126fcbf (added more)
=======
    void sendFeedback(double feedbackFreq);
    void captureAllWaves();
    void endAnalysis();
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

private:
<<<<<<< HEAD
    bool treatCancelled;

=======
    double calculateDominantFrequency(Waveform* waveform);
    void captureNewWave(Waveform* waveform);
<<<<<<< HEAD
    void simulateTherapy(double dominantFrequency, int node);
>>>>>>> fbd85c6 (did more stuff)
=======
    void simulateTherapy(double dominantFrequency);
    double calculateBasline(QVector<double> dominantFreqs);
    bool cancelled;
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
};

#endif // TREATMENT_H
