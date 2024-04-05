#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include "neurodevicecontroller.h"
<<<<<<< HEAD

#include "LightIndicator.h"
=======
>>>>>>> f901a30b42bfe466c146658843bb2d9f91ed55e0

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
<<<<<<< HEAD

    // Declare LightIndicator instances
    LightIndicator *contactLightIndicator;
    LightIndicator *treatmentLightIndicator;
    LightIndicator *contactLostLightIndicator;
=======
>>>>>>> f901a30b42bfe466c146658843bb2d9f91ed55e0

};
#endif // MAINWINDOW_H
