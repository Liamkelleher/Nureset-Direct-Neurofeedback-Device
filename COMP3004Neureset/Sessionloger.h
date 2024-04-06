#ifndef SESSIONLOGER_H
#define SESSIONLOGER_H

#include "sessionlog.h"
#include <iostream>

class SessionLoger
{
public:
    SessionLoger();
    void startSession(int time,int date); //saves the baseline of a session
    void addReading(int sensor, float readings); //saves the baseline of a node
    void endSessionSuccess(int time,int date); // ends the session
    session* getSessions(int session);
    int getSessionCount();

private:
    bool running;
    int sessionCount;
    session * sessions[];



};

#endif // SESSIONLOGER_H
