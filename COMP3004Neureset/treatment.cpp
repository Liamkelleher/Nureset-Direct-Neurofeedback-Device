#include "treatment.h"

double Treatment::calculateDominantFrequency(Waveform& waveform)
{

    function alphaBand = waveform.getBand(BandType::ALPHA);
    function betaBand = waveform.getBand(BandType::BETA);
    function deltaBand = waveform.getBand(BandType::DELTA);
    function thetaBand = waveform.getBand(BandType::THETA);

    // calculate dominant freq using equation from specs:
    double totalWeighted = (pow(alphaBand.amplitude, 2) * alphaBand.frequency +
                            pow(betaBand.amplitude,2) * betaBand.frequency +
                            pow(deltaBand.amplitude,2) * deltaBand.frequency +
                            pow(thetaBand.amplitude, 2) * thetaBand.frequency);

    double totalAmplitude = (pow(alphaBand.amplitude, 2) + pow(betaBand.amplitude,2) +
                             pow(deltaBand.amplitude,2) + pow(thetaBand.amplitude, 2));

    return totalWeighted / totalAmplitude;
}

void Treatment::applyTreatment(Waveform& waveform, int node)
{
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
    {
        qDebug() << "Round "<< round << " of therapy";
        qDebug() << "Delivering 1 second feedback at 1/16 of "<< dominantFrequency + offset;
        emit sendFeedback((dominantFrequency + offset)/16, node);
    }
}


