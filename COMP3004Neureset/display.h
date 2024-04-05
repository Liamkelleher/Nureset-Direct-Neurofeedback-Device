#ifndef DISPLAY_H
#define DISPLAY_H

#include <QListWidget>
#include <QProgressBar>
#include <QLabel>
#include <QDateTimeEdit>
#include <QElapsedTimer>
#include <QList>

class Display: public QObject
{
    Q_OBJECT

public:
    Display(QListWidget* disLabel, QProgressBar* progLabel, QLabel* timerLabel, QDateTimeEdit* dteLabel);

    int getCurrentMenuSelect();

public slots:
    void upArrowButton();
    void downArrowButton();
    void startButton();
    void stopButton();
    void powerButton(bool deviceOn);
    void menuButton(bool deviceOn);

private:
    void createMenuList();

    QListWidget *dis;
    QProgressBar *progBar;
    QLabel *timerDis;
    QDateTimeEdit *dTE;
    QListWidgetItem *sesNew, *sesLog, *tnd;
    QList<QListWidgetItem *> menuList = {sesNew, sesLog, tnd};
    QElapsedTimer sesTimer;
    bool hidden, sesActive;
};

#endif // DISPLAY_H
