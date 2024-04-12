#ifndef TREATMENT_H
#define TREATMENT_H

#include <QObject>
#include <QThread>

class Treatment: public QObject
{
    Q_OBJECT

public:
    Treatment();

    void cancelTreatment();

public slots:
    void treatNodes();

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
    bool treatCancelled;

};

#endif // TREATMENT_H
