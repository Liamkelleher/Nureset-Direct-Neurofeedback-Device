#include "Sessionloger.h"

SessionLoger::SessionLoger()
{
    sessionCount = 0;
    running = false;

    //used for testing remove once complete
    /*
    startSession(10,1);
    addReading(0,1);
    addReading(0,2);
    endSessionSuccess(11,1);
    startSession(12,1);
    startSession(13,1);
    std::cout << "Session count: " << sessionCount <<std::endl;
    */


}

// saves the baseline of a session
// takes time in minutes and a date (figure out format)
void SessionLoger::startSession(int time,int date){

    if (running){
        sessionCount++;
        std::cout << "Session ended prematurly" << std::endl;
    }
    sessions[sessionCount] = new session;
    if (sessions[sessionCount] == nullptr){
        std::cout << "error: mem_allocation:17" << std::endl;
    }
    sessions[sessionCount]->date = date;
    sessions[sessionCount]->startime = time;
    std::cout << "Session started:  " << sessions[sessionCount]->date << "  :  " << sessions[sessionCount]->startime << std::endl;
    running = true;
}

// saves the baseline of a node
// takes a valid sensor (range starts at 0)
void SessionLoger::addReading(int sensor, float readings){
    if (sessions[sessionCount]->reading[sensor].readings[0] == 0){
        sessions[sessionCount]->reading[sensor].readings[0] = readings;
        //std::cout << "Added to first reading" << std::endl;
    } else if (sessions[sessionCount]->reading[sensor].readings[1] == 0) {
        sessions[sessionCount]->reading[sensor].readings[1] = readings;
        //std::cout << "Added to second reading" << std::endl;
    } else{
        std::cout << "Error both readings added" << std::endl;
    }

}

// ends the session
// takes time in minutes and a date (figure out format)
void SessionLoger::endSessionSuccess(int time,int date){
    if (sessions[sessionCount]->date == date){
        sessions[sessionCount]->duration = time - sessions[sessionCount]->startime;
        //std::cout << "Session ended on date" << std::endl;
    } else {
        sessions[sessionCount]->duration = (time + 24*60) - sessions[sessionCount]->startime; // add 24*60 minutes to current time if rolled over to new day
        //std::cout << "Session after date" << std::endl;
    }


    sessionCount++;
    running = false;

}

// returns pointer to session if in range or nullptr otherwise
session* SessionLoger::getSessions(int session){
    if( session <= sessionCount){
        return sessions[session];
    }else {
        return nullptr;
    }
}

// returns session count, its saved internaly as one less for easy array access
int SessionLoger::getSessionCount(){
    return sessionCount+1;
}
