#ifndef EEGNODE_H
#define EEGNODE_H

#include <QVector>
#include <cmath>
#include <QDebug>

class EEGNode : public QObject
{
    Q_OBJECT
public:
    EEGNode();

    QVector<double> generateWaveSignal();
    QVector<double> getWaveSignal();

private:
    QVector<double> sinFunction;
};

#endif // EEGNODE_H
