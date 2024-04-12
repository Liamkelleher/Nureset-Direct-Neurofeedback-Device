#include "treatment.h"

Treatment::Treatment()
{
    treatCancelled = false;
}

void Treatment::treatNodes()
{
<<<<<<< HEAD
    if(!treatCancelled)
=======
    emit captureWave(node);
    //apply 5 sec delay

    double dominantFrequency = calculateDominantFrequency(waveform); // before dominant
    qDebug() << "Before Dominant Frequency: " << dominantFrequency << " Hz";
    // emit signal before dominant freq calculated -> send to array in neurodevice
    emit beforeDominantFreq(dominantFrequency);

    // sim therapy - signal emitting to send feedback params: feedback freq
    simulateTherapy(dominantFrequency, node);

    captureNewWave(waveform);

    dominantFrequency = calculateDominantFrequency(waveform); // after dominant
    qDebug() << "After Dominant Frequency: " << dominantFrequency << " Hz";
    // calculate after dominant freq
    // emit after dominant freq -> send to array in neuro
    emit afterDominantFreq(dominantFrequency);
}

void Treatment::captureNewWave(Waveform& waveform)
{

    function alphaBand = waveform.getBand(BandType::ALPHA);
    function betaBand = waveform.getBand(BandType::BETA);
    function deltaBand = waveform.getBand(BandType::DELTA);
    function thetaBand = waveform.getBand(BandType::THETA);

    // Change these band's frequencies
    bool shouldAdd = QRandomGenerator::global()->bounded(2);
    double randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.02;
    alphaBand.frequency +=  0.1 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.02;
    betaBand.frequency +=  0.1 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.02;
    deltaBand.frequency +=  0.1 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    shouldAdd = QRandomGenerator::global()->bounded(2);
    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.02;
    thetaBand.frequency +=  0.1 + (shouldAdd ? -randomAdjustment : randomAdjustment);

    waveform.generateWave(); // new wave signal post round of therapy

}

void Treatment::simulateTherapy(double dominantFrequency, int node)
{
    double offset = 5;
    for (int round = 1; round <= 4; ++round)
>>>>>>> 126fcbf (added more)
    {
        QThread::msleep(3000);
        emit nodeTreated();
    }
}

void Treatment::cancelTreatment()
{
    treatCancelled = true;
}
