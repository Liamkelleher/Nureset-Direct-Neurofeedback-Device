#include "Session.h"

Session::Session(QDateTime dateTime) : dateTime(dateTime), beforeBaseline(0.0), afterBaseline(0.0) {}

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
