#ifndef DEFS_H
#define DEFS_H

#include <QString>

namespace LightIndicatorColors {
    const QString CONTACT_ON_COLOUR = "rgba(0, 0, 255, 1)"; // Blue inner
    const QString CONTACT_ON_COLOUR2 = "rgba(0, 0, 50, 1)"; // Blue outer

    const QString TREATMENT_ON_COLOUR = "rgba(0, 255, 0, 1)"; // Green inner
    const QString TREATMENT_ON_COLOUR2 = "rgba(0, 50, 0, 1)"; // Green outer

    const QString CONTACT_LOST_COLOUR = "rgba(255, 0, 0, 1)"; // Red inner
    const QString CONTACT_LOST_COLOUR2 = "rgba(50, 0, 0, 1)"; // Red outer

    const QString OFF_COLOUR = "rgb(169, 169, 169)"; // Grey
}

// Enum to represent the different states of the light indicator
enum class LightIndicatorState {
    Off,
    ContactEstablished, // Blue light
    TreatmentInProgress, // Green light
    ContactLost, // Red light
};

#endif // DEFS_H
