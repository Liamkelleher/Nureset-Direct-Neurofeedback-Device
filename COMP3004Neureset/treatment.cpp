#include "treatment.h"

<<<<<<< HEAD
<<<<<<< HEAD
Treatment::Treatment()
{
    treatCancelled = false;
}

void Treatment::treatNodes()
=======
=======
Treatment::Treatment() : cancelled(false) {}

>>>>>>> b73866d (added treatment logic, timing, and battery checks)
double Treatment::calculateDominantFrequency(Waveform* waveform)
{
    function* alphaBand = waveform->getBand(BandType::ALPHA);
    function* betaBand = waveform->getBand(BandType::BETA);
    function* deltaBand = waveform->getBand(BandType::DELTA);
    function* thetaBand = waveform->getBand(BandType::THETA);

    // calculate dominant freq using equation from specs:
    double totalWeighted = (pow(alphaBand->amplitude, 2) * alphaBand->frequency +
                            pow(betaBand->amplitude, 2) * betaBand->frequency +
                            pow(deltaBand->amplitude, 2) * deltaBand->frequency +
                            pow(thetaBand->amplitude, 2) * thetaBand->frequency);

    double totalAmplitude = (pow(alphaBand->amplitude, 2) + pow(betaBand->amplitude, 2) +
                             pow(deltaBand->amplitude, 2) + pow(thetaBand->amplitude, 2));

    return totalWeighted / totalAmplitude;
}

<<<<<<< HEAD
void Treatment::applyTreatment(Waveform* waveform, int node)
>>>>>>> fbd85c6 (did more stuff)
{
<<<<<<< HEAD
    if(!treatCancelled)
=======
    emit captureWave(node);
    //apply 5 sec delay
=======
void Treatment::applyTreatment(EEGHeadset* nodes)
{
    cancelled = false;
    emit captureAllWaves();
>>>>>>> b73866d (added treatment logic, timing, and battery checks)

    QVector<double> dominantFreq;
    for (EEGNode *node : nodes->getNodes())
    {
        double dominant = calculateDominantFrequency(node->getWaveSignal());
        dominantFreq.push_back(dominant); // before dominant
        qDebug() << "Before Dominant Frequency: " << dominant << " Hz";
    }
    // calculate baseline
    double beforeBaseline = calculateBasline(dominantFreq);
    emit beforeDominantFreq(beforeBaseline);

    // sim therapy - signal emitting to send feedback params: feedback freq
    simulateTherapy(beforeBaseline);

    for (EEGNode *node : nodes->getNodes())
    {
        captureNewWave(node->getWaveSignal());
    }
    qDebug() << "Analyzing Response Wave ";
    // ADD 5 SECOND DELAY FOR ANALYSIS
    QThread::msleep(5000);
    if (!cancelled) {
        dominantFreq.clear();
        for (EEGNode *node : nodes->getNodes())
        {
            double dominant = calculateDominantFrequency(node->getWaveSignal());
            dominantFreq.push_back(dominant); // before dominant
            qDebug() << "After Dominant Frequency: " << dominant << " Hz";
        }
        double afterBaseline = calculateBasline(dominantFreq);
        emit afterDominantFreq(afterBaseline);
        emit endAnalysis();
    }
}

void Treatment::captureNewWave(Waveform* waveform)
{
    function* alphaBand = waveform->getBand(BandType::ALPHA);
    function* betaBand = waveform->getBand(BandType::BETA);
    function* deltaBand = waveform->getBand(BandType::DELTA);
    function* thetaBand = waveform->getBand(BandType::THETA);

    // Change these band's frequencies
    bool shouldAdd = QRandomGenerator::global()->bounded(2);
    double randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.3;
    alphaBand->frequency +=  0.5 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.3;
    betaBand->frequency +=  0.5 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.3;
    deltaBand->frequency +=  0.5 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.3;
    thetaBand->frequency +=  0.5 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    waveform->generateWave();
}

void Treatment::simulateTherapy(double dominantFrequency)
{
    if (cancelled)
        return;
    double offset = 5;
    for (int round = 1; round <= 4; ++round)
>>>>>>> 126fcbf (added more)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        QThread::msleep(3000);
        emit nodeTreated();
=======
=======
        if (cancelled)
            return;
>>>>>>> b73866d (added treatment logic, timing, and battery checks)
        qDebug() << "Round "<< round << " of therapy";
        qDebug() << "Analyzing Final Wave";
        // ADD 5 SECOND DELAY HERE FOR RE-ANALYSIS
        QThread::msleep(5000);
        if (cancelled)
            return;
        qDebug() << "Delivering 1 second feedback at 1/16 of " << dominantFrequency + offset;
        // ADD 1000 ms DELAY HERE FOR 1/16 FEEDBACK
        QThread::msleep(1000);
        if (cancelled)
            return;
        emit sendFeedback((dominantFrequency + offset)/16);
        offset += 5;
>>>>>>> 0a2175b (baseline calcs)
    }
}

void Treatment::cancelTreatment()
{
<<<<<<< HEAD
    treatCancelled = true;
}
=======
    cancelled = true;
}

double Treatment::calculateBasline(QVector<double> dominantFreqs)
{
    double sumOfNodes = 0;

   for (int i = 0; i < NUM_NODES; ++i)
   {
       sumOfNodes += dominantFreqs.at(i);
   }

   return sumOfNodes / NUM_NODES;
}

>>>>>>> b73866d (added treatment logic, timing, and battery checks)
