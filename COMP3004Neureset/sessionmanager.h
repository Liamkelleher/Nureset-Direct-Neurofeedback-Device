#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "sessionlog.h"
#include "Session.h"
#include <QTime>

class SessionManager {
private:
    Session* currentSession;
    SessionLog* sessionLog;
    void saveSessionToLog();

public:
    SessionManager();
    ~SessionManager();
    void createSession(QDateTime);
    void endSession();
    void pauseSession();
    void resumeSession();
    bool isSessionPaused();
    QTime getCurrentSessionElapsedTime() const;
    void updateBeforeBaseline(int, float);
    void updateAfterBaseline(int, float);
    SessionLog* getSessionLog() const;
};

#endif // SESSIONMANAGER_H
