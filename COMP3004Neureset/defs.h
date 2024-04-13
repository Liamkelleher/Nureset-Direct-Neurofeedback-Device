#ifndef DEFS_H
#define DEFS_H

#include <QString>
#include <QVector>
#include <cmath>

#define NUM_NODES 7
#define GRAPH_STEPS 500
#define STEP 0.01
#define EXPIRE_TIME 30
#define LOGS_FILE "sessionlog.dat"

enum BandType {
    ALPHA,
    BETA,
    DELTA,
    THETA
};

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

struct function {
    double amplitude;
    double frequency;
    QVector<double> values;

    function(double amp = 0.0, double freq = 0.0) : amplitude(amp), frequency(freq) {}

    void calculateWave() {
        values.clear();
        for (int i = 0; i < GRAPH_STEPS; ++i) {
            double x = i * STEP;
            double waveValue = amplitude * std::sin(2 * frequency * M_PI * x);
            values.push_back(waveValue);
        }
    }
};

#endif // DEFS_H
