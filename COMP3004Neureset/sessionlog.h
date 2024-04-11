#ifndef SESSIONLOG_H
#define SESSIONLOG_H

#include "Session.h"
#include "defs.h"
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QDataStream>

class SessionLog {
private:
    QVector<Session*> sessions;
    void writeToFile(Session *);
    void readFromFile();

public:
    SessionLog();
    ~SessionLog();
    void addSession(Session* session);
    Session& operator[](int index);
    int count() const;
};

#endif // SESSIONLOG_H
