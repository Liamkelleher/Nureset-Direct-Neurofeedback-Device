#ifndef DISPLAY_H
#define DISPLAY_H

#include <QListWidget>
#include <QProgressBar>
#include <QLabel>
#include <QDateTimeEdit>
#include <QElapsedTimer>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QStackedWidget>
#include "sessionlog.h"

class Display: public QObject
{
    Q_OBJECT

public:
    Display(QStackedWidget* stackedWidget);
    int getCurrentMenuSelect();
    void populateSessionLogs(SessionLog *);
    void updateTimer(qint64);

public slots:
    void upArrowButton(bool deviceOn);
    void downArrowButton(bool deviceOn);
    void startButton(bool deviceOn);
    void stopButton(bool deviceOn);
    void powerButton(bool deviceOn);
    void menuButton(bool deviceOn);

signals:
    void uploadSession(int);

private:
    QStackedWidget* stackedWidget;
    QElapsedTimer sesTimer;
    bool hidden, sesActive;
};

#endif // DISPLAY_H
