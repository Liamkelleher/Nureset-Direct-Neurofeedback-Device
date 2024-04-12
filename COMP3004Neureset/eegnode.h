#ifndef EEGNODE_H
#define EEGNODE_H

#include <QDebug>
#include "waveform.h"
#include "defs.h"

class EEGNode : public QObject
{
    Q_OBJECT
public:
    EEGNode(double, double, double, double, double, double, double, double);

    void captureWave();
    Waveform* getWaveSignal();

private:
    Waveform* wave;
};

#endif // EEGNODE_H
