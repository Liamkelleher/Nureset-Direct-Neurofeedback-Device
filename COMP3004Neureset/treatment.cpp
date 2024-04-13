#include "treatment.h"

Treatment::Treatment() : cancelled(false), paused(false), domFreq(0) {}

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

void Treatment::applyTreatment(EEGHeadset* headset)
{
    nodes = headset;
    cancelled = false;
    domFreq = 0;
    paused = false;
    emit captureAllWaves();

    QVector<double> dominantFreq;
    for (EEGNode *node : nodes->getNodes())
    {
        double dominant = calculateDominantFrequency(node->getWaveSignal());
        dominantFreq.push_back(dominant); // before dominant
        qDebug() << "Before Dominant Frequency: " << dominant << " Hz";
    }
    // calculate baseline
    double beforeBaseline = calculateBasline(dominantFreq);
    domFreq = beforeBaseline;
    emit beforeDominantFreq(beforeBaseline);

    // sim therapy - signal emitting to send feedback params: feedback freq
    simulateTherapy(beforeBaseline, 1);

    if (cancelled || paused)
        return;
    for (EEGNode *node : nodes->getNodes())
    {
        captureNewWave(node->getWaveSignal());
    }
    calculateAfter();
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

void Treatment::simulateTherapy(double dominantFrequency, int round)
{
    if (cancelled || paused)
    {
        emit toggleTreatmentLight(false);
        return;
    }
    double offset = 5;
    for (int i = round; i <= 4; ++i)
    {
        if (cancelled || paused)
        {
            emit toggleTreatmentLight(false);
            return;
        }

        qDebug() << "Round "<< i << " of therapy";
        qDebug() << "Re-Analyzing Wave";
        // ADD 5 SECOND DELAY HERE FOR RE-ANALYSIS
        for (int i = 0; i < 5; i++)
        {
            emit toggleTreatmentLight(false);
            QThread::msleep(500);
            emit toggleTreatmentLight(true);
            QThread::msleep(500);
        }
        if (cancelled || paused)
        {
            emit toggleTreatmentLight(false);
            return;
        }

        qDebug() << "Delivering 1 second feedback at 1/16 of " << dominantFrequency + offset;
        // ADD 1000 ms DELAY HERE FOR 1/16 FEEDBACK
        emit toggleTreatmentLight(false);
        QThread::msleep(1000);
        emit toggleTreatmentLight(true);
        if (cancelled || paused)
            return;
        emit sendFeedback((dominantFrequency + offset)/16);
        offset += 5;
    }
}

void Treatment::cancelTreatment()
{
    cancelled = true;
    domFreq = 0;
}

void Treatment::togglePauseTreatment(bool pause)
{
    paused = pause;
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

void Treatment::calculateAfter()
{
    qDebug() << "Analyzing Response Wave ";
    // ADD 5 SECOND DELAY FOR ANALYSIS
    QThread::msleep(5000);
    if (cancelled || paused)
        return;
    QVector<double> dominantFreq;
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

void Treatment::resumeTreatment(int step, int round)
{

    switch (step)
    {
        case 2:
            simulateTherapy(domFreq, round);
            for (EEGNode *node : nodes->getNodes())
            {
                captureNewWave(node->getWaveSignal());
            }
            calculateAfter();
            break;
        case 3:
            calculateAfter();
            break;
        default:
            break;
    }

}

