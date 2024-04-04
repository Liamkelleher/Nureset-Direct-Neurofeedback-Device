#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QElapsedTimer>
#include <QList>
#include <QtDebug>

#include "LightIndicator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_upArrowButton_clicked();

    void on_downArrowButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_powerButton_clicked();

    void on_menuButton_clicked();

    void on_batteryUseButton_clicked();

    void on_batteryFullButton_clicked();

    void on_batteryEmptyButton_clicked();

private:
    void createMenuList();

    Ui::MainWindow *ui;
    QListWidgetItem *sesNew, *sesLog, *tnd;
    QList<QListWidgetItem *> menuList = {sesNew, sesLog, tnd};
    //populated from session log class
    QList<QListWidgetItem *> sessionLogList = {};
    QElapsedTimer sesTimer;
    bool hidden, sesActive, deviceOn;

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;

};
#endif // MAINWINDOW_H
