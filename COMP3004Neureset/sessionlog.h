#ifndef SESSIONLOG_H
#define SESSIONLOG_H

#include "Session.h"
#include <QVector>

class SessionLog {
private:
    QVector<Session*> sessions;

public:
    SessionLog();
    ~SessionLog();
    void addSession(Session* session);
    Session& operator[](int index);
    int count() const;
};

#endif // SESSIONLOG_H
