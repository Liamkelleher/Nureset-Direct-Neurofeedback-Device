#ifndef DEFS_H
#define DEFS_H

#include <QString>
#include <QVector>
#include <cmath>

#define NUM_NODES 7

namespace LightIndicatorColors {
    const QString CONTACT_ON_COLOUR = "rgba(0, 150, 255, 1)"; // Blue inner
    const QString CONTACT_ON_COLOUR2 = "rgba(0, 50, 150, 1)"; // Blue outer

    const QString TREATMENT_ON_COLOUR = "rgba(80, 200, 120, 1)"; // Green inner
    const QString TREATMENT_ON_COLOUR2 = "rgba(0, 100, 0, 1)"; // Green outer

    const QString CONTACT_LOST_COLOUR = "rgba(238, 75, 43, 1)"; // Red inner
    const QString CONTACT_LOST_COLOUR2 = "rgba(130, 0, 0, 1)"; // Red outer

    const QString OFF_COLOUR = "rgb(169, 169, 169)"; // Grey
}

// Enum to represent the different states of the light indicator
enum class LightIndicatorState {
    Off,
    ContactEstablished, // Blue light
    TreatmentInProgress, // Green light
    ContactLost, // Red light
};

struct functionDataType {
    double amplitude;
    double frequency;
    QVector<double> values;

    functionDataType(double amp = 0.0, double freq = 0.0) : amplitude(amp), frequency(freq) {}

    void calculateWave(int numberOfPoints, double timeInterval) {
        values.clear(); // Clear existing values
        for (int i = 0; i < numberOfPoints; ++i) {
            double t = i * timeInterval;
            double waveValue = amplitude * std::sin(2 * M_PI * frequency * t);
            values.push_back(waveValue);
        }
    }
};

#endif // DEFS_H
