#ifndef CONTACTLOST_H
#define CONTACTLOST_H

#include <QObject>
#include <QThread>
#include <QtDebug>

class ContactLost: public QObject
{
    Q_OBJECT

public:
    ContactLost();

    void setContactState(bool state);
    void setPausedState(bool state);

public slots:
    void contactWarning();
    void pausedWarning();

signals:
    void sessionExpired();
    void toggleContactLostLight(bool on);

private:
    bool contactState, pausedState;
};

#endif // CONTACTLOST_H
