#include "treatment.h"

Treatment::Treatment() : cancelled(false), paused(false), domFreq(0) {}

/*
 *
 * Discription:
 * Calculates the Dominant frequency from a waveform
 *
 * Given:
 * Waveform - a wave to be analyzed
 *
 * Returns:
 * Double - the Dominant frequency from a wave
 *
*/
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

/*
 *
 * Discription:
 * Main treatment function that gets all the calulated waveinformation from a headset and
 * calculates and applys a treatment.
 *
 * Given:
 * EEGHeadset - headset to treat/get info
 *
 * Returns:
 * None
 *
*/
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

/*
 *
 * Discription:
 * Captures a wave from a EEG node
 *
 * Given:
 * Waveform - pointer to a waveform from a EEG node
 *
 * Returns:
 * None
 *
*/
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

/*
 *
 * Discription:
 * Calculates and simulates therapy on a patient. Also handles the session light and console output for treatment
 *
 * Given:
 * double - dominant Frequency from a EEG node
 * int - the round of therapy
 *
 * Returns:
 * None
 *
*/
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
/*
 *
 * Discription:
 * Cancels treatment
 *
 * Given:
 * None
 *
 * Returns:
 * None
 *
*/
void Treatment::cancelTreatment()
{
    cancelled = true;
    domFreq = 0;
}
/*
 *
 * Discription:
 * Pauses treatment
 *
 * Given:
 * None
 *
 * Returns:
 * None
 *
*/
void Treatment::togglePauseTreatment(bool pause)
{
    paused = pause;
}
/*
 *
 * Discription:
 * Calculates treatment baseline for each node
 *
 * Given:
 * QVector<double> - an array of dominant frequency for each node
 *
 * Returns:
 * double - the baseline: sum of all dominante frequencys avraged out.
 *
*/
double Treatment::calculateBasline(QVector<double> dominantFreqs)
{
    double sumOfNodes = 0;

   for (int i = 0; i < NUM_NODES; ++i)
   {
       sumOfNodes += dominantFreqs.at(i);
   }

   return sumOfNodes / NUM_NODES;
}

/*
 *
 * Discription:
 * Calculates post-treatment dominante frequency for each node and overall baseline.
 * Gets the node waves after treatment and calulates new dominant and baselines.
 *
 * Given:
 * None
 *
 * Returns:
 * None
 *
*/
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

/*
 *
 * Discription:
 * starts therepy back after pause based on where it was paused.
 *
 * Given:
 * int - the treatment step that was paused
 * int - the round in that step that was paused (indicates which node treatment stoped at)
 *
 * Returns:
 * None
 *
*/
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

