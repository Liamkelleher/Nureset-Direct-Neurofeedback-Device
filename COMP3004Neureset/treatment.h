#ifndef TREATMENT_H
#define TREATMENT_H

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

signals:
<<<<<<< HEAD
    void nodeTreated();
=======
    void beforeDominantFreq(double beforeDominantFreq);
    void afterDominantFreq(double afterDominantFreq);
    void sendFeedback(double feedbackFreq, int node);
    void captureWave(int node);
>>>>>>> 126fcbf (added more)

private:
<<<<<<< HEAD
    bool treatCancelled;

=======
    double calculateDominantFrequency(Waveform* waveform);
    void captureNewWave(Waveform* waveform);
    void simulateTherapy(double dominantFrequency, int node);
>>>>>>> fbd85c6 (did more stuff)
};

#endif // TREATMENT_H
