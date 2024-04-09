#include "Session.h"

Session::Session(QDateTime dateTime) : dateTime(dateTime)
{
    beforeBaselines.resize(NUM_NODES);
    afterBaselines.resize(NUM_NODES);
}

Session::~Session() {}

void Session::startSession()
{
    elapsedTime = QTime(0,0);
}

void Session::endSession(QTime elapsed)
{
    this->elapsedTime = elapsed;
}

void Session::updateBeforeBaseline(int node, float value)
{
    if(node >= 0 && node < beforeBaselines.size())
    {
        beforeBaselines[node] = value;
    }
}

void Session::updateAfterBaseline(int node, float value)
{
    if(node >= 0 && node < afterBaselines.size())
    {
        afterBaselines[node] = value;
    }
}

QTime Session::getTimeElapsed()
{
    return elapsedTime;
}

void Session::setTimeElapsed(QTime newTime)
{
    this->elapsedTime = newTime;
}

QVector<float> Session::getBeforeBaselines()
{
    return beforeBaselines;
}

QVector<float> Session::getAfterBaselines()
{
    return afterBaselines;
}

QDateTime Session::getDateTime()
{
    return dateTime;
}

QString Session::toString() const
{
    return "Date: " + dateTime.toString("dd.MM.yyyy hh:mm:ss");
}
