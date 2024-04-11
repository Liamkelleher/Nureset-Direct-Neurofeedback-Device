#include "Session.h"

Session::Session(QDateTime dateTime) : dateTime(dateTime), beforeBaseline(0.0), afterBaseline(0.0) {}

Session::Session(Session& sessionCopy)
{
    this->dateTime = sessionCopy.dateTime;
    this->beforeBaseline = sessionCopy.beforeBaseline;
    this->afterBaseline = sessionCopy.afterBaseline;
    this->elapsedTime = sessionCopy.elapsedTime;
}

Session::Session() : dateTime(QDateTime()), beforeBaseline(0.0), afterBaseline(0.0), elapsedTime(QTime()) {}

Session::~Session() {}

void Session::startSession()
{
    elapsedTime = QTime(0,0);
}

void Session::endSession(QTime elapsed)
{
    this->elapsedTime = elapsed;
}

void Session::updateBeforeBaseline(double value)
{
    beforeBaseline = value;
}

void Session::updateAfterBaseline(double value)
{
    afterBaseline = value;
}

QTime Session::getTimeElapsed()
{
    return elapsedTime;
}

void Session::setTimeElapsed(QTime newTime)
{
    this->elapsedTime = newTime;
}

double Session::getBeforeBaseline()
{
    return beforeBaseline;
}

double Session::getAfterBaseline()
{
    return afterBaseline;
}

QDateTime Session::getDateTime()
{
    return dateTime;
}

QString Session::toString() const
{
    return "Date: " + dateTime.toString("dd.MM.yyyy hh:mm:ss");
}

QDataStream &operator<<(QDataStream &out, const Session &session) {
    out << session.dateTime;
    out << QString::number(session.beforeBaseline);
    out << QString::number(session.afterBaseline);
    out << session.elapsedTime.toString("mm:ss");
    return out;
}

QDataStream &operator>>(QDataStream &in, Session &session) {
    QString beforeBaselineStr, afterBaselineStr, timeString;

    in >> session.dateTime;
    in >> beforeBaselineStr;
    in >> afterBaselineStr;
    in >> timeString;

    session.beforeBaseline = beforeBaselineStr.toDouble();
    session.afterBaseline = afterBaselineStr.toDouble();
    session.elapsedTime = QTime::fromString(timeString, "mm:ss");

    return in;
}
