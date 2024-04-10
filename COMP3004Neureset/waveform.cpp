#include "waveform.h"

Waveform::Waveform(functionDataType alpha, functionDataType beta, functionDataType delta, functionDataType theta)
    : alphaBand(alpha), betaBand(beta), deltaBand(delta), thetaBand(theta) {
    calculateEEGReading(); // Initial calculation for eegReading based on the initial bands
}

// Generate a waveform
void Waveform::calculateAllWaves(int numberOfPoints, double timeInterval) {
    alphaBand.calculateWave(numberOfPoints, timeInterval);
    betaBand.calculateWave(numberOfPoints, timeInterval);
    deltaBand.calculateWave(numberOfPoints, timeInterval);
    thetaBand.calculateWave(numberOfPoints, timeInterval);

    calculateEEGReading(); // calculate eegReading after updating the waves
}

void Waveform::calculateEEGReading() {
    eegReading.amplitude = alphaBand.amplitude + betaBand.amplitude +
                           deltaBand.amplitude + thetaBand.amplitude;
    eegReading.frequency = (alphaBand.frequency + betaBand.frequency +
                            deltaBand.frequency + thetaBand.frequency) / 4.0;
}
