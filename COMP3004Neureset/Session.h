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
    QVector<float> beforeBaselines;
    QVector<float> afterBaselines;
    QTime elapsedTime;

public:
    Session(QDateTime);
    ~Session();
    void startSession();
    void endSession(QTime);
    void updateBeforeBaseline(int node, float value);
    void updateAfterBaseline(int node, float value);
    QVector<float> getBeforeBaselines();
    QVector<float> getAfterBaselines();
    QTime getTimeElapsed();
    void setTimeElapsed(QTime);
    QDateTime getDateTime();
    QString toString() const;
};

#endif // SESSION_H
