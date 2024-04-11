#include "sessionmanager.h"

SessionManager::SessionManager() : currentSession(nullptr), sessionLog(new SessionLog()) {}

SessionManager::~SessionManager() {
    delete sessionLog;
    if(currentSession) {
        delete currentSession;
    }
}

void SessionManager::createSession(QDateTime dateTime) {
    currentSession = new Session(dateTime);
    currentSession->startSession();
}

void SessionManager::endSession(QTime elapsed) {
    if(currentSession) {
        currentSession->endSession(elapsed);
        saveSessionToLog();
        currentSession = nullptr;
    }
}

QTime SessionManager::getCurrentSessionElapsedTime() const {
    if(currentSession) {
        return currentSession->getTimeElapsed();
    }
    return QTime(0, 0);
}

void SessionManager::updateBeforeBaseline(double beforeValue) {
    if(currentSession) {
        currentSession->updateBeforeBaseline(beforeValue);
    }
}

void SessionManager::updateAfterBaseline(double afterValue) {
    if(currentSession) {
        currentSession->updateAfterBaseline(afterValue);
    }
}

SessionLog* SessionManager::getSessionLog() const {
    return sessionLog;
}

void SessionManager::saveSessionToLog() {
    if (currentSession) {
        sessionLog->addSession(currentSession);
    }
}
