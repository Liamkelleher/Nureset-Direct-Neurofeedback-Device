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

    double avgAmplitude  = 0;
    for (EEGNode *node : nodes->getNodes())
    {
        avgAmplitude += (node->getWaveSignal()->getBand(BandType::ALPHA)->amplitude +
        node->getWaveSignal()->getBand(BandType::BETA)->amplitude  +
        node->getWaveSignal()->getBand(BandType::DELTA)->amplitude +
        node->getWaveSignal()->getBand(BandType::THETA)->amplitude)/4;
    }
    avgAmplitude = avgAmplitude / NUM_NODES;
    emit avgAmp(avgAmplitude);

    QVector<double> dominantFreq;
    for (EEGNode *node : nodes->getNodes())
    {
        double dominant = calculateDominantFrequency(node->getWaveSignal());
        dominantFreq.push_back(dominant); // before dominant
    }
    qDebug() << "TREATMENT: Calculating dominant frequency before therapy\n";
    // calculate baseline
    emit beforeDominantFreq(dominantFreq);
    double beforeBaseline = calculateBasline(dominantFreq);
    domFreq = beforeBaseline;
    emit beforeBase(beforeBaseline);

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
    double randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.1 * 4;
    alphaBand->frequency += (shouldAdd ? 1 : -1) * (randomAdjustment);

    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.1 * 18;
    betaBand->frequency += (shouldAdd ? 1 : -1) * (randomAdjustment);

    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.1 * 3;
    deltaBand->frequency += (shouldAdd ? 1 : -1) * (randomAdjustment);

    randomAdjustment = QRandomGenerator::global()->generateDouble() * 0.1 * 4;
    thetaBand->frequency += (shouldAdd ? 1 : -1) * (randomAdjustment);


    waveform->generateWave();
}

void Treatment::simulateTherapy(double dominantFrequency, int round)
{
    if (cancelled || paused)
    {
        emit toggleTreatmentLight(false);
        return;
    }
    double offset = 5 * round;
    for (int i = round; i <= 4; ++i)
    {
        if (cancelled || paused)
        {
            emit toggleTreatmentLight(false);
            return;
        }

        qDebug() << "TREATMENT: Round "<< i << " of therapy";

        qDebug() << "TREATMENT: Delivering 1 second feedback at 1/16 of " << dominantFrequency + offset << "Hz (" << (dominantFrequency + offset)/16 << ")";
        // ADD 1000 ms DELAY HERE FOR 1/16 FEEDBACK
        emit toggleTreatmentLight(false);
        QThread::msleep(1000);
        emit toggleTreatmentLight(true);
        if (cancelled || paused)
            return;

        // ADD 5 SECOND DELAY HERE FOR RE-ANALYSIS
        qDebug() << "TREATMENT: Processing input wave signals\n";
        for (int i = 0; i < 5; i++)
        {
            emit toggleTreatmentLight(false);
            QThread::msleep(500);
            if (cancelled || paused)
            {
                emit toggleTreatmentLight(false);
                return;
            }
            emit toggleTreatmentLight(true);
            QThread::msleep(500);
            emit toggleTreatmentLight(false);
        }
        for (EEGNode *node : nodes->getNodes())
        {
            captureNewWave(node->getWaveSignal());
        }
        if (cancelled || paused)
        {
            emit toggleTreatmentLight(false);
            return;
        }

        emit sendFeedback();
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
    qDebug() << "TREATMENT: Processing input wave signals";
    // ADD 5 SECOND DELAY FOR ANALYSIS
    QThread::msleep(5000);
    if (cancelled || paused)
        return;
    qDebug() << "TREATMENT: Calculating dominant frequency after therapy\n";
    QVector<double> dominantFreq;
    for (EEGNode *node : nodes->getNodes())
    {
        double dominant = calculateDominantFrequency(node->getWaveSignal());
        dominantFreq.push_back(dominant); // before dominant
    }
    emit afterDominantFreq(dominantFreq);
    double afterBaseline = calculateBasline(dominantFreq);
    emit afterBase(afterBaseline);
    emit endAnalysis();
}

void Treatment::resumeTreatment(int step, int round)
{

    switch (step)
    {
        case 2:
            simulateTherapy(domFreq, round);
            if (cancelled || paused)
                return;
            for (EEGNode *node : nodes->getNodes())
            {
                captureNewWave(node->getWaveSignal());
            }
            calculateAfter();
            break;
        case 3:
            if (cancelled || paused)
                return;
            calculateAfter();
            break;
        default:
            break;
    }

}

