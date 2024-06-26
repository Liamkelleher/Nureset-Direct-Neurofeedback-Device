#include "eegnode.h"

EEGNode::EEGNode(double a_ampl, double a_freq, double b_ampl, double b_freq,double d_ampl, double d_freq,double t_ampl, double t_freq)
{
   wave = new Waveform(a_ampl, a_freq, b_ampl, b_freq, d_ampl, d_freq, t_ampl, t_freq);
}

EEGNode::~EEGNode()
{
    delete wave;
}

Waveform* EEGNode::getWaveSignal()
{
    return wave;
}

void EEGNode::captureWave()
{
    wave->generateWave();
}
