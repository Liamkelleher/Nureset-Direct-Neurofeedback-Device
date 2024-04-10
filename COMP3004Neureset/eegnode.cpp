#include "eegnode.h"

EEGNode::EEGNode() {}

QVector<double> EEGNode::generateWaveSignal()
{
    const double pi = std::acos(-1);
    const int numSteps = 100;

    for (int i = 0; i <= numSteps; ++i) {
        double x = i * 0.01;
        double value = 0.2 * std::sin(18 * pi * x) +
                       0.2 * std::sin(26 * pi * x) +
                       0.2 * std::sin(3 * pi * x);
        sinFunction.push_back(value);
    }
    return sinFunction;
}
