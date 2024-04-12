#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <cmath>
#include "defs.h"

class Waveform {
public:
    Waveform(double, double, double, double, double, double, double, double);
    ~Waveform();
    void generateWave();
    function* getBand(BandType);
    QVector<double> getWaveSignal();
    void setWaveSignal(QVector<double>);
    void clearWave();

private:
    function* alphaBand;
    function* betaBand;
    function* deltaBand;
    function* thetaBand;
    function* eegReading;
};

#endif // WAVEFORM_H
