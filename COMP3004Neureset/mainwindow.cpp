#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    contactLightIndicator = new LightIndicator(ui->contactLight);
    treatmentLightIndicator = new LightIndicator(ui->treatmentLight);
    contactLostLightIndicator = new LightIndicator(ui->contactLostLight);

    nDC.setupNDC(ui->display, ui->sessionProgressBar, ui->timeElapsed, ui->dateTimeEdit);

    connect(this, &MainWindow::upArrowButtonPressed, &nDC, &NeuroDeviceController::upArrowButtonPressed);
    connect(this, &MainWindow::downArrowButtonPressed, &nDC, &NeuroDeviceController::downArrowButtonPressed);
    connect(this, &MainWindow::startButtonPressed, &nDC, &NeuroDeviceController::startButtonPressed);
    connect(this, &MainWindow::stopButtonPressed, &nDC, &NeuroDeviceController::stopButtonPressed);
    connect(this, &MainWindow::menuButtonPressed, &nDC, &NeuroDeviceController::menuButtonPressed);
    connect(this, &MainWindow::powerButtonPressed, &nDC, &NeuroDeviceController::powerButtonPressed);

    //moves the ndc to a new thread
    nDC.moveToThread(&_NDCthread);

    _NDCthread.start();
}

MainWindow::~MainWindow()
{
    _NDCthread.exit();
    _NDCthread.wait();
    delete ui;
}

void MainWindow::on_upArrowButton_clicked() { emit upArrowButtonPressed(); }
void MainWindow::on_downArrowButton_clicked() { emit downArrowButtonPressed(); }
void MainWindow::on_startButton_clicked() { emit startButtonPressed(); }
void MainWindow::on_stopButton_clicked() { emit stopButtonPressed(); }
void MainWindow::on_powerButton_clicked() { emit powerButtonPressed(); }
void MainWindow::on_menuButton_clicked() { emit menuButtonPressed(); }


void MainWindow::on_batteryUseButton_clicked()
{
    ui->batteryCharge->setValue(ui->batteryCharge->value() - 10);
}

void MainWindow::on_batteryFullButton_clicked()
{
    ui->batteryCharge->setValue(ui->batteryCharge->maximum());
}

void MainWindow::on_batteryEmptyButton_clicked()
{
    ui->batteryCharge->setValue(ui->batteryCharge->minimum());
}
