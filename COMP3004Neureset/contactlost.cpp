#include "contactlost.h"

ContactLost::ContactLost() {}

void ContactLost::setContactState(bool state) { contactState = state; }
void ContactLost::setPausedState(bool state) { pausedState = state; }

//Determins when the session has expired after contact with the EEG headset is lost
void ContactLost::contactWarning()
{
    int counter = 0;

    while(contactState)
    {
        emit toggleContactLostLight(false);
        qDebug() << "AUDIO: BEEP";
        QThread::msleep(500);
        emit toggleContactLostLight(true);
        QThread::msleep(500);
        counter++;

        if (counter >= EXPIRE_TIME)
        {
            contactState = false;
            emit sessionExpired();
        }
    }

    emit toggleContactLostLight(false);
}

//Determins when the session has expired after a session is paused
void ContactLost::pausedWarning()
{
    int counter = 0;

    while(pausedState)
    {
        QThread::msleep(1000);
        counter++;

        if (counter >= EXPIRE_TIME)
        {
            pausedState = false;
            emit sessionExpired();
        }
    }
}
