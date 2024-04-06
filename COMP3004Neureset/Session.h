#ifndef SESSION_H
#define SESSION_H

#include <QDateTime>
#include <QString>
#include <QTime>
#include <array>
#include <QVector>
#include <QElapsedTimer>

#include "sessionmanager.h"

class Session {
private:
    QDateTime dateTime;
    QTime timeElapsed;
    qint64 cumulativeTimeElapsed; // for when pausing/resuming
    QVector<float> beforeBaselines;
    QVector<float> afterBaselines;
    bool isPaused;
    QElapsedTimer timer;

public:
    Session();
    ~Session();
    void startSession();
    void endSession();
    void pauseSession();
    void resumeSession();
    void updateBeforeBaseline(int node, float value);
    void updateAfterBaseline(int node, float value);
    bool getIsPaused() const;
    QString toString() const;
};

#endif // SESSION_H
