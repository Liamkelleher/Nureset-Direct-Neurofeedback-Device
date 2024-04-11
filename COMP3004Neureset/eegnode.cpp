#include "eegnode.h"

EEGNode::EEGNode(double a_ampl, double a_freq, double b_ampl, double b_freq,double d_ampl, double d_freq,double t_ampl, double t_freq)
            : wave(a_ampl, a_freq, b_ampl, b_freq, d_ampl, d_freq, t_ampl, t_freq)
{}

Waveform EEGNode::getWaveSignal()
{
    return wave;
}

void EEGNode::updateWaveSignal(QVector<double> newSignal)
{
    wave.setWaveSignal(newSignal);
}

void EEGNode::captureWave()
{
    wave.generateWave();
}
