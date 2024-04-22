#include "sessionmanager.h"

SessionManager::SessionManager() : currentSession(nullptr), sessionLog(new SessionLog()) {}

SessionManager::~SessionManager() {
    delete sessionLog;
    if(currentSession) {
        delete currentSession;
    }
}
/*
 *
 * Discription:
 * Starts recording a session at given time
 *
 * Given:
 * QDateTime - startTime
 *
 * Returns:
 * None
 *
*/
void SessionManager::createSession(QDateTime dateTime) {
    currentSession = new Session(dateTime);
    currentSession->startSession();
}

/*
 *
 * Discription:
 * Ends a Session amd saves it to the log
 *
 * Given:
 * Qtime elapsed - the time that the session took
 * Bool save - save the session to log or not
 *
 * Returns:
 * None
 *
*/
void SessionManager::endSession(QTime elapsed, bool save) {
    if(currentSession) {
        currentSession->endSession(elapsed);
        saveSessionToLog(save);
        currentSession = nullptr;
    }
}
/*
 *
 * Discription:
 * If a session is active returns the Elapsed time otherwise returns 0
 *
 * Given:
 * None
 *
 * Returns:
 * QTime - time that is elapsed.
 *
*/
QTime SessionManager::getCurrentSessionElapsedTime() const {
    if(currentSession) {
        return currentSession->getTimeElapsed();
    }
    return QTime(0, 0);
}

/*
 *
 * Discription:
 * Saves the given reading to an active session as the pre-treatment baseline
 *
 * Given:
 * double - value of pre-treatment baseline.
 *
 * Returns:
 * None
 *
*/
void SessionManager::updateBeforeBaseline(double beforeValue) {
    if(currentSession) {
        currentSession->updateBeforeBaseline(beforeValue);
    }
}

/*
 *
 * Discription:
 * Saves the given reading to an active session as the post-treatment baseline.
 *
 * Given:
 * double - after treatment dominant frequency
 *
 * Returns:
 * None
 *
*/
void SessionManager::updateAfterBaseline(double afterValue) {
    if(currentSession) {
        currentSession->updateAfterBaseline(afterValue);
    }
}


/*
 *
 * Discription:
 * Saves average amplitued to the session log
 *
 * Given:
 * double - the given amplitued to save
 *
 * Returns:
 * None
 *
*/
void SessionManager::updateAvgAmp(double amp)
{
    if (currentSession)
    {
        currentSession->updateAvgAmp(amp);
    }
}

/*
 *
 * Discription:
 * Saves the given reading to an active session as the pre-treatment dominent frequency
 *
 * Given:
 * double - value of pre-treatment dominent frequency.
 *
 * Returns:
 * None
 *
*/
void SessionManager::addBeforeDF(QVector<double> df)
{
    if (currentSession)
    {
        currentSession->addToDF(true, df);
    }
}

/*
 *
 * Discription:
 * Saves the given reading to an active session as the post-treatment dominent frequency
 *
 * Given:
 * double - value of post-treatment dominent frequency.
 *
 * Returns:
 * None
 *
*/
void SessionManager::addAfterDF(QVector<double> df)
{
    if (currentSession)
    {
        currentSession->addToDF(false, df);
    }
}

/*
 *
 * Discription:
 * Returns the session logs of all recorded sessions
 *
 * Given:
 * None
 *
 * Returns:
 * Sessionlog - a pointer to all the session logs
 *
*/
SessionLog* SessionManager::getSessionLog() const {
    return sessionLog;
}


/*
 *
 * Discription:
 * When a session complets saves it to the logs
 *
 * Given:
 * Bool - save the session or not.
 *
 * Returns:
 * None
 *
*/
void SessionManager::saveSessionToLog(bool save) {
    if (currentSession) {
        if (save)
            sessionLog->addSession(currentSession);
    }
}
