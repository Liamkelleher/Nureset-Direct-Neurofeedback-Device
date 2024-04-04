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
    if (state == LightIndicatorState::Off) {
        QString styleSheet = QString(R"(
           QPushButton {
                border-radius: 10px;
                background-color: %1;
                border: 1px solid #555;
                })").arg(LightIndicatorColors::OFF_COLOUR);

                button->setStyleSheet(styleSheet);
    } else {
        QString styleTemplate = R"(
            QPushButton {
                border-radius: 10px;
                background: qradialgradient(
                    cx: 0.5, cy: 0.5,
                    radius: 1,
                    fx: 0.5, fy: 0.5,
                    stop: 0.2 %2,
                    stop: 0.8 %1);
                }
            )";

        QString innerColour;
        QString outerColour;

        if (state == LightIndicatorState::ContactEstablished )
        {
            innerColour = LightIndicatorColors::CONTACT_ON_COLOUR;
            outerColour = LightIndicatorColors::CONTACT_ON_COLOUR2;
        }
        else if (state == LightIndicatorState::TreatmentInProgress)
        {
            innerColour = LightIndicatorColors::TREATMENT_ON_COLOUR;
            outerColour = LightIndicatorColors::TREATMENT_ON_COLOUR2;
        }
        else if (state == LightIndicatorState::ContactLost)
        {
            innerColour = LightIndicatorColors::CONTACT_LOST_COLOUR;
            outerColour = LightIndicatorColors::CONTACT_LOST_COLOUR2;
        }

        // Set the stylesheet based on the color
        button->setStyleSheet(styleTemplate.arg(outerColour, innerColour));
    }
}


LightIndicatorState LightIndicator::getState() {
    return state;
}
