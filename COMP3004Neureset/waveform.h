#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <cmath>
#include "defs.h"

class Waveform {
public:
    Waveform(double, double, double, double, double, double, double, double);
    void generateWave();
    function getBand(BandType);
    QVector<double> getWaveSignal();

private:
    function alphaBand;
    function betaBand;
    function deltaBand;
    function thetaBand;
    function eegReading;
};

#endif // WAVEFORM_H
