#ifndef SESSION_H
#define SESSION_H

#include <QDateTime>
#include <QString>
#include <QTime>
#include <QDataStream>
#include <QVector>
#include <QDebug>
#include <QElapsedTimer>
#include "defs.h"

class Session {
private:
    QDateTime dateTime;
    double beforeBaseline;
    double afterBaseline;
    double avgAmplitude;
    QTime elapsedTime;
    QVector<double> beforeDFs;
    QVector<double> afterDFs;

public:
    Session(QDateTime);
    Session(Session&);
    Session();
    ~Session();
    void startSession();
    void endSession(QTime);
    void updateBeforeBaseline(double value);
    void updateAfterBaseline(double value);
    void updateAvgAmp(double);
    void addToDF(bool, QVector<double>);
    double getBeforeBaseline();
    double getAfterBaseline();
    double getAvgAmpl();
    QVector<double> getBeforeDFs();
    QVector<double> getAfterDFs();
    QTime getTimeElapsed();
    void setTimeElapsed(QTime);
    QDateTime getDateTime();
    QString toString() const;

    friend QDataStream& operator<<(QDataStream& out, const Session& session);
    friend QDataStream& operator>>(QDataStream& in, Session& session);
};

#endif // SESSION_H
