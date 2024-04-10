#include "waveform.h"

Waveform::Waveform(double a_ampl, double a_freq, double b_ampl, double b_freq,double d_ampl, double d_freq,double t_ampl, double t_freq)
{
    alphaBand.amplitude = a_ampl;
    alphaBand.frequency = a_freq;
    betaBand.amplitude = b_ampl;
    betaBand.frequency = b_freq;
    deltaBand.amplitude = d_ampl;
    deltaBand.frequency = d_freq;
    thetaBand.amplitude = t_ampl;
    thetaBand.frequency = t_freq;

    alphaBand.calculateWave();
    betaBand.calculateWave();
    deltaBand.calculateWave();
    thetaBand.calculateWave();
}

void Waveform::generateWave()
{
    for (int i = 0; i <= GRAPH_STEPS; ++i) {
        double x = i * STEP;
        double value = alphaBand.amplitude * std::sin(2 * alphaBand.frequency * M_PI * x) +
                       betaBand.amplitude * std::sin(2 * betaBand.frequency * M_PI * x) +
                       deltaBand.amplitude * std::sin(2 * deltaBand.frequency * M_PI * x) +
                       thetaBand.amplitude * std::sin(2 * thetaBand.frequency * M_PI * x);
        eegReading.values.push_back(value);
    }
}

function Waveform::getBand(BandType type)
{
    switch (type)
    {
        case BandType::ALPHA:
            return alphaBand;
        case BandType::BETA:
            return betaBand;
        case BandType::DELTA:
            return deltaBand;
        case BandType::THETA:
            return thetaBand;
    }
    return function();
}

QVector<double> Waveform::getWaveSignal()
{
    return eegReading.values;
}
