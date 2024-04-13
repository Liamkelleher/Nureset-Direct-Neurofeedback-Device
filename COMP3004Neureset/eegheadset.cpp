#include "eegheadset.h"

EEGHeadset::EEGHeadset()
{    
    for (int i = 0; i < NUM_NODES; ++i)
    {
       double a_ampl = 20 + QRandomGenerator::global()->generateDouble() * 40;
       double a_freq = 8.0 + QRandomGenerator::global()->generateDouble() * 4.0;
       double b_ampl = 5 + QRandomGenerator::global()->generateDouble() * 25;
       double b_freq = 12.0 + QRandomGenerator::global()->generateDouble() * 18.0;
       double d_ampl = 20 + QRandomGenerator::global()->generateDouble() * 180;
       double d_freq = 1.0 + QRandomGenerator::global()->generateDouble() * 3.0;
       double t_ampl = 10 + QRandomGenerator::global()->generateDouble() * 90;
       double t_freq = 4.0 + QRandomGenerator::global()->generateDouble() * 4.0;
       nodes.push_back(new EEGNode(a_ampl, a_freq, b_ampl, b_freq, d_ampl, d_freq, t_ampl, t_freq));
    }
}

EEGHeadset::~EEGHeadset()
{
    for (EEGNode* node : nodes)
    {
        delete node;
    }
}

void EEGHeadset::captureAllWaves()
{
    for (EEGNode *node : nodes)
    {
         node->captureWave();
    }

}

EEGNode& EEGHeadset::operator[](int index)
{
    return *nodes.at(index);
}

QVector<EEGNode *> EEGHeadset::getNodes()
{
    return nodes;
}

void EEGHeadset::getInitialBaseline()
{
    QThread::msleep(5000);
    emit startAnalysis();
}

void EEGHeadset::clearNodes()
{
    for (EEGNode *node : nodes)
    {
        node->getWaveSignal()->clearWave();
    }
}
