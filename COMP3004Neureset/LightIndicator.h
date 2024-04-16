/*
 * LightIndicator.h
 * This class handles light indicator states on the Neureset Device
 *
 */

#ifndef LIGHTINDICATOR_H
#define LIGHTINDICATOR_H

#include <QPushButton>
#include <QMutex>
#include "defs.h"

class LightIndicator {
public:
    LightIndicator(QPushButton* button);
    void updateState(LightIndicatorState state);
    LightIndicatorState getState();

private:
    void updateColour(LightIndicatorState state);

    QPushButton* button;
    LightIndicatorState state;

};

#endif // LIGHTINDICATOR_H
