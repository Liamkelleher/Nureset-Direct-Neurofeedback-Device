#ifndef SESSION_H
#define SESSION_H

#include <QDateTime>
#include <QString>
#include <QTime>
#include <array>
#include <QVector>
#include <QElapsedTimer>
#include <defs.h>

class Session {
private:
    QDateTime dateTime;
    double beforeBaseline;
    double afterBaseline;
    QTime elapsedTime;

public:
    Session(QDateTime);
    Session(Session&);
    Session();
    ~Session();
    void startSession();
    void endSession(QTime);
    void updateBeforeBaseline(double value);
    void updateAfterBaseline(double value);
    double getBeforeBaseline();
    double getAfterBaseline();
    QTime getTimeElapsed();
    void setTimeElapsed(QTime);
    QDateTime getDateTime();
    QString toString() const;

    friend QDataStream& operator<<(QDataStream& out, const Session& session);
    friend QDataStream& operator>>(QDataStream& in, Session& session);
};

#endif // SESSION_H
