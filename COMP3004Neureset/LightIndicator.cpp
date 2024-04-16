// LightIndicator.cpp
#include "LightIndicator.h"

LightIndicator::LightIndicator(QPushButton* button) : button(button), state(LightIndicatorState::Off) {
    updateColour(LightIndicatorState::Off);
}

void LightIndicator::updateState(LightIndicatorState newState) {
    state = newState;

    switch (state) {
        case LightIndicatorState::Off:
            updateColour(state);
            break;
        case LightIndicatorState::ContactEstablished:
            updateColour(state);
            break;
        case LightIndicatorState::TreatmentInProgress:
            updateColour(state);
            break;
        case LightIndicatorState::ContactLost:
            updateColour(state);
            break;
    }
}

void LightIndicator::updateColour(LightIndicatorState state)
{
    QMutex mutex;
    if (state == LightIndicatorState::Off) {
        QString styleSheet = QString(
            "QPushButton {"
            "   border-radius: 10px;"
            "   background-color: %1;"
            "   border: 1px solid #555;"
            "}"
        ).arg(LightIndicatorColors::OFF_COLOUR);
        mutex.lock();
        button->setStyleSheet(styleSheet);
        mutex.unlock();
    } else {
        QString styleTemplate = QString(
            "QPushButton {"
            "   border-radius: 10px;"
            "   background: qradialgradient("
            "       cx: 0.5, cy: 0.5,"
            "       radius: 1,"
            "       fx: 0.5, fy: 0.5,"
            "       stop: 0.2 %1,"
            "       stop: 0.8 %2"
            "   );"
            "}"
        );

        QString innerColour, outerColour;
        if (state == LightIndicatorState::ContactEstablished) {
            innerColour = LightIndicatorColors::CONTACT_ON_COLOUR2;
            outerColour = LightIndicatorColors::CONTACT_ON_COLOUR;
        } else if (state == LightIndicatorState::TreatmentInProgress) {
            innerColour = LightIndicatorColors::TREATMENT_ON_COLOUR2;
            outerColour = LightIndicatorColors::TREATMENT_ON_COLOUR;
        } else if (state == LightIndicatorState::ContactLost) {
            innerColour = LightIndicatorColors::CONTACT_LOST_COLOUR2;
            outerColour = LightIndicatorColors::CONTACT_LOST_COLOUR;
        }

        QString finalStyleSheet = styleTemplate.arg(innerColour, outerColour);
        button->setStyleSheet(finalStyleSheet);
    }
}


LightIndicatorState LightIndicator::getState() {
    return state;
}
