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

void SessionManager::endSession() {
    if(currentSession) {
        currentSession->endSession();
        saveSessionToLog();
        currentSession = nullptr;
    }
}

void SessionManager::pauseSession() {
    if (currentSession) {
        currentSession->pauseSession();
    }
}

void SessionManager::resumeSession() {
    if (currentSession) {
        currentSession->resumeSession();
    }
}

bool SessionManager::isSessionPaused() {
    if (currentSession) {
        return currentSession->getIsPaused();
    }
    return false;
}

QTime SessionManager::getCurrentSessionElapsedTime() const {
    if(currentSession) {
        return currentSession->getTimeElapsed();
    }
    return QTime(0, 0);
}

void SessionManager::updateBeforeBaseline(int nodeNum, float beforeValue) {
    if(currentSession) {
        currentSession->updateBeforeBaseline(nodeNum, beforeValue);
    }
}

void SessionManager::updateAfterBaseline(int nodeNum, float afterValue) {
    if(currentSession) {
        currentSession->updateAfterBaseline(nodeNum, afterValue);
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
