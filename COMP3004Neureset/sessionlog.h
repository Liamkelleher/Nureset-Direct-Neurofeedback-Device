#ifndef SESSIONLOG_H
#define SESSIONLOG_H

#endif // SESSIONLOG_H
#define EEG_NODE_COUNT 7

struct EEGnode{
    float readings[2] = {0,0};
};

struct session{
    int startime = 0;
    int duration = 0;
    int date = 0;
    EEGnode reading[EEG_NODE_COUNT];
};
