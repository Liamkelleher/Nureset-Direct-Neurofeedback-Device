#include "sessionlog.h"

SessionLog::SessionLog() {
    readFromFile();
}

SessionLog::~SessionLog() {
    for(Session* session : sessions) {
        delete session;
    }
}
/*
 *
 * Description:
 * This adds a session to the current sessions and calls the Write function to save it persistantly
 *
 * Given:
 * Session - pointer to a session to record
 *
 * Returns:
 * None
 *
*/
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

/*
 *
 * Description:
 * This saves session to a log for persistance
 *
 * Given:
 * Session - pointer to a session to record
 *
 * Returns:
 * None
 *
*/
void SessionLog::writeToFile(Session *session)
{
    QFile file(LOGS_FILE);
    if (!file.open(QIODevice::Append)) {
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);
    out << *session;
    file.close();
}

/*
 *
 * Description:
 * On startup this loads past session from a log and saves them to current history
 *
 * Given:
 * None
 *
 * Returns:
 * None
 *
*/
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
}
