#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "sessionlog.h"
#include "Session.h"
#include <QTime>

class SessionManager {
private:
    Session* currentSession;
    SessionLog* sessionLog;
    void saveSessionToLog(bool);

public:
    SessionManager();
    ~SessionManager();
    void createSession(QDateTime);
    void endSession(QTime, bool);
    QTime getCurrentSessionElapsedTime() const;
    void updateBeforeBaseline(double);
    void updateAfterBaseline(double);
    SessionLog* getSessionLog() const;
};

#endif // SESSIONMANAGER_H
