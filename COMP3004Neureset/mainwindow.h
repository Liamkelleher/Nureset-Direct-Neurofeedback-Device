#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include "neurodevicecontroller.h"

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

signals:
    void upArrowButtonPressed();
    void downArrowButtonPressed();
    void startButtonPressed();
    void stopButtonPressed();
    void powerButtonPressed();
    void menuButtonPressed();

private:
    Ui::MainWindow *ui;
    NeuroDeviceController nDC;
    QThread _NDCthread;

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;

};
#endif // MAINWINDOW_H
