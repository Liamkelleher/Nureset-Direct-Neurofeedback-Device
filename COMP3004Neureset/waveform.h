#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <cmath>
#include "defs.h" // for functionDataType

class Waveform {
public:
    functionDataType alphaBand;
    functionDataType betaBand;
    functionDataType deltaBand;
    functionDataType thetaBand;
    functionDataType eegReading;

    Waveform(functionDataType alpha, functionDataType beta, functionDataType delta, functionDataType theta);
    void calculateAllWaves(int numberOfPoints, double timeInterval);
    void calculateEEGReading();
};

#endif // WAVEFORM_H
