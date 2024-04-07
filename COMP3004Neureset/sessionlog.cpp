#include "sessionlog.h"

SessionLog::SessionLog() {}

SessionLog::~SessionLog() {
    for(Session* session : sessions) {
        delete session;
    }
}

void SessionLog::addSession(Session* session) {
    sessions.append(session);
}

Session& SessionLog::operator[](int index) {
    return *sessions.at(index);
}

int SessionLog::count() const {
    return sessions.size();
}
