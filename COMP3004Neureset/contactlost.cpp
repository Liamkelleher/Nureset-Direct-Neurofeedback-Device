#include "contactlost.h"

ContactLost::ContactLost() {}

void ContactLost::setContactState(bool state) { contactState = state; }
void ContactLost::setPausedState(bool state) { pausedState = state; }

void ContactLost::contactWarning()
{
    int counter = 0;

    while(contactState)
    {
        emit toggleContactLostLight(false);
        qDebug() << "BEEP";
        QThread::msleep(500);
        emit toggleContactLostLight(true);
        QThread::msleep(500);
        counter++;

        if (counter >= 30)
        {
            contactState = false;
            emit sessionExpired();
        }
    }

    emit toggleContactLostLight(false);
}

void ContactLost::pausedWarning()
{
    int counter = 0;

    while(pausedState)
    {
        QThread::msleep(1000);
        counter++;

        if (counter >= 30)
        {
            pausedState = false;
            emit sessionExpired();
        }
    }
}
