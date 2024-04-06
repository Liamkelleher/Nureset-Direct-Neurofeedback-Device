#include "Session.h"

Session::Session() : dateTime(QDateTime::currentDateTime())
{
    // Resize vectors to hold all 21 EEG nodes
    beforeBaselines.resize(21);
    afterBaselines.resize(21);
}

Session::~Session() {}

void Session::startSession()
{
    // start date and time
    dateTime = QDateTime::currentDateTime();
    // Start measuring elapsed time
    timer.start();
    isPaused = false;
}

void Session::pauseSession() {
    if (!isPaused)
    {
        // Update the elapsed time so far and pause
        cumulativeTimeElapsed += timer.elapsed();
        isPaused = true;
    }
}

void Session::resumeSession()
{
    if (isPaused) {
            timer.start(); // Reset the timer
            isPaused = false;
        }
}

void Session::endSession()
{
    // calculate total elapsed time
    if (!isPaused)
    {
        // if no pauses in session, cumulativeTimeElapsed will be set to regular timer
        cumulativeTimeElapsed += timer.elapsed();
    }

    // convert to Qtime object
    timeElapsed = QTime(0, 0).addMSecs(cumulativeTimeElapsed);
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

bool Session::getIsPaused() const
{
    return isPaused;
}

QString Session::toString() const
{
    return dateTime.toString("dd.MM.yyyy hh:mm:ss") + " | Elapsed Time: " + timeElapsed.toString();
}
