#include "eegheadset.h"

EEGHeadset::EEGHeadset()
{
    for (int i = 0; i < NUM_NODES; ++i)
    {
        nodes.push_back(new EEGNode());
    }
}

EEGHeadset::~EEGHeadset()
{
    for (EEGNode* node : nodes)
    {
        delete node;
    }
}

void EEGHeadset::captureWaves()
{
    for (EEGNode* node : nodes)
    {
        node->generateWaveSignal();
        //QTimer::singleShot(5000, this, [node](){ node->generateWaveSignal(); });
    }
}

EEGNode& EEGHeadset::operator[](int index)
{
    return *nodes.at(index);
}
