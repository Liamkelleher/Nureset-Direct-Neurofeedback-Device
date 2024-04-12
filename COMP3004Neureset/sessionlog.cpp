#include "sessionlog.h"

SessionLog::SessionLog() {
    readFromFile();
}

SessionLog::~SessionLog() {
    for(Session* session : sessions) {
        delete session;
    }
}

void SessionLog::addSession(Session* session) {
    sessions.append(session);
    writeToFile(session);
}

Session& SessionLog::operator[](int index) {
    return *sessions.at(index);
}

int SessionLog::count() const {
    return sessions.size();
}

void SessionLog::writeToFile(Session *session)
{
    QFile file(LOGS_FILE);
    if (!file.open(QIODevice::Append)) {
        qDebug() << "Cannot open or create file for writing:" << LOGS_FILE;
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);
    out << *session;
    file.close();
    qDebug() << "Session appended to file successfully.";

}

void SessionLog::readFromFile()
{
    QFile file(LOGS_FILE);
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_15);
        sessions.clear();
        Session session;
        while (!in.atEnd()) {
            in >> session;
            sessions.append(new Session(session));
        }
        file.close();
        qDebug() << "Sessions read from file successfully.";
}
