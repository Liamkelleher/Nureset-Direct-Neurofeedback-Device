#ifndef SESSION_H
#define SESSION_H

#include <QDateTime>
#include <QString>
#include <QTime>
#include <array>
#include <QVector>
#include <QElapsedTimer>
#include <defs.h>

class Session {
private:
    QDateTime dateTime;
    QElapsedTimer elapsedTime;
    qint64 accumulatedTime;
    QVector<float> beforeBaselines;
    QVector<float> afterBaselines;
    bool isPaused;

public:
    Session(QDateTime);
    ~Session();
    void startSession();
    void endSession();
    void pauseSession();
    void resumeSession();
    void updateBeforeBaseline(int node, float value);
    void updateAfterBaseline(int node, float value);
    QVector<float> getBeforeBaselines();
    QVector<float> getAfterBaselines();
    QTime getTimeElapsed();
    bool getIsPaused() const;
    QString toString() const;
};

#endif // SESSION_H
