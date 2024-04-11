#ifndef DISPLAY_H
#define DISPLAY_H

#include <QListWidget>
#include <QProgressBar>
#include <QLabel>
#include <QDateTimeEdit>
#include <QElapsedTimer>
#include <QList>
#include <QDebug>
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
    void upArrowButton();
    void downArrowButton();
    void startButton();
    void stopButton();
    void powerOnDisplay();
    void powerOffDisplay();
    void menuButton();

signals:
    void uploadSession(int);
    void updateDateTime(QDateTime);

private:
    QStackedWidget* stackedWidget;
    QElapsedTimer sesTimer;
};

#endif // DISPLAY_H
