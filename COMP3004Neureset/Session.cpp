#include "Session.h"

Session::Session(QDateTime dateTime) : dateTime(dateTime), accumulatedTime(0), isPaused(false)
{
    beforeBaselines.resize(NUM_NODES);
    afterBaselines.resize(NUM_NODES);
}

Session::~Session() {}

void Session::startSession()
{
    elapsedTime.start();
}

void Session::pauseSession() {
    if (!isPaused) {
            accumulatedTime += elapsedTime.elapsed();
            elapsedTime.invalidate();
            isPaused = true;
    }
}

void Session::resumeSession()
{
    if (isPaused) {
           elapsedTime.start();
           isPaused = false;
    }
}

void Session::endSession()
{
    if (!isPaused) {
        accumulatedTime += elapsedTime.elapsed();
    }
    elapsedTime.invalidate();
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
    if (elapsedTime.isValid()) {
        return QTime(0, 0).addMSecs(accumulatedTime + elapsedTime.elapsed());
    }
    return QTime(0, 0).addMSecs(accumulatedTime);
}

bool Session::getIsPaused() const
{
    return isPaused;
}

QVector<float> Session::getBeforeBaselines()
{
    return beforeBaselines;
}

QVector<float> Session::getAfterBaselines()
{
    return afterBaselines;
}

QString Session::toString() const
{
    return "Date: " + dateTime.toString("dd.MM.yyyy hh:mm:ss");
}
