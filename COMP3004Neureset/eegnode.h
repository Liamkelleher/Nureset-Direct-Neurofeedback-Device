#ifndef EEGNODE_H
#define EEGNODE_H

#include <QVector>
#include <cmath>
#include <QDebug>

class EEGNode
{
public:
    EEGNode();

    QVector<double> generateWaveSignal();

private:
    QVector<double> sinFunction;
};

#endif // EEGNODE_H
