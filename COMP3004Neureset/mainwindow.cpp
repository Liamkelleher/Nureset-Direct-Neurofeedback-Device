#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < NUM_NODES; ++i)
    {
        ui->nodeDropDown->addItem("Node " + QString::number(i+1));
    }

    nDC = new NeuroDeviceController(ui->stackedWidget, ui->contactLight, ui->treatmentLight, ui->contactLostLight, ui->progressBar, ui->batteryCharge, ui->nodeDropDown);
    pcdevice = new PCDevice(ui->pcDeviceWidget);

    pcdevice->toggleComponents(false);

    ui->EEGGraph->addGraph();
    ui->EEGGraph->xAxis->setRange(0, 5);
    ui->EEGGraph->yAxis->setRange(-500, 500);
    ui->EEGGraph->xAxis->setLabel("Time (seconds)");
    ui->EEGGraph->yAxis->setLabel("Voltage (μV)");
    ui->EEGGraph->axisRect()->setupFullAxesBox(false);
    ui->EEGGraph->setBackground(Qt::NoBrush); // Makes the plot's background transparent
    ui->EEGGraph->axisRect()->setBackground(Qt::NoBrush); // Makes the canvas background transparent
    QPen plotPen(QColor(0, 0, 255));
    plotPen.setWidthF(1.5);
    ui->EEGGraph->graph()->setPen(plotPen);
    ui->EEGGraph->xAxis->setLabelFont(QFont("sans", 12));
    ui->EEGGraph->yAxis->setLabelFont(QFont("sans", 12));
    QPen gridPen(QColor(200, 200, 200), 0, Qt::DashLine);
    ui->EEGGraph->xAxis->grid()->setPen(gridPen);
    ui->EEGGraph->yAxis->grid()->setPen(gridPen);

    connect(this, &MainWindow::upArrowButtonPressed, nDC, &NeuroDeviceController::upArrowButtonPressed);
    connect(this, &MainWindow::downArrowButtonPressed, nDC, &NeuroDeviceController::downArrowButtonPressed);

    connect(this, &MainWindow::startButtonPressed, nDC, &NeuroDeviceController::startButtonPressed);
    connect(this, &MainWindow::stopButtonPressed, nDC, &NeuroDeviceController::stopButtonPressed);
    connect(this, &MainWindow::pauseButtonPressed, nDC, &NeuroDeviceController::pauseSession);

    connect(this, &MainWindow::menuButtonPressed, nDC, &NeuroDeviceController::menuButtonPressed);
    connect(this, &MainWindow::powerButtonPressed, nDC, &NeuroDeviceController::powerButtonPressed);

    connect(this, &MainWindow::nodeDisplayChanged, nDC, &NeuroDeviceController::nodeDisplayChanged);

    connect(this, &MainWindow::terminateConnection, nDC, &NeuroDeviceController::terminateConnection);
    connect(this, &MainWindow::establishConnection, nDC, &NeuroDeviceController::establishConnection);

    connect(nDC, &NeuroDeviceController::uploadToPC, this, &MainWindow::uploadSession);
    connect(nDC, &NeuroDeviceController::updateGraph, this, &MainWindow::updateGraph);

    //moves the ndc to a new thread
    nDC->moveToThread(&_NDCthread);

    _NDCthread.start();
}

MainWindow::~MainWindow()
{
    _NDCthread.exit();
    _NDCthread.wait();
    delete ui;
    delete pcdevice;
    delete nDC;
}

void MainWindow::on_upArrowButton_clicked() { emit upArrowButtonPressed(); }
void MainWindow::on_downArrowButton_clicked() { emit downArrowButtonPressed(); }

void MainWindow::on_startButton_clicked() { emit startButtonPressed(); }
void MainWindow::on_stopButton_clicked() { emit stopButtonPressed(); }
void MainWindow::on_pauseButton_pressed(){ emit pauseButtonPressed(); }

void MainWindow::on_powerButton_clicked() { emit powerButtonPressed(); }
void MainWindow::on_menuButton_clicked() { emit menuButtonPressed(); }

void MainWindow::on_nodeDropDown_currentIndexChanged(int index) { emit nodeDisplayChanged(index); }

void MainWindow::on_terminateConnection_clicked() { emit terminateConnection(); }
void MainWindow::on_establishConnection_clicked() { emit establishConnection(); }

void MainWindow::on_batteryUseButton_clicked() { ui->batteryCharge->setValue(ui->batteryCharge->value() - 20); }
void MainWindow::on_batteryFullButton_clicked() { ui->batteryCharge->setValue(ui->batteryCharge->maximum()); }
void MainWindow::on_batteryEmptyButton_clicked() { ui->batteryCharge->setValue(ui->batteryCharge->minimum()); }

void MainWindow::uploadSession(Session* session) { pcdevice->uploadToPC(session); }

void MainWindow::updateGraph(EEGNode* node)
{
    if (node == nullptr)
    {
        ui->EEGGraph->graph()->setData({}, {});  // Clear the data
        ui->EEGGraph->replot();
        return;
    }
    QVector<double> x(GRAPH_STEPS + 1);
    for (int i = 0; i < GRAPH_STEPS + 1; ++i)
    {
        x[i] = STEP * i;
    }
    QVector<double> wave = node->getWaveSignal()->getWaveSignal();
    if (!wave.isEmpty())
    {
        ui->EEGGraph->graph()->setData(x, wave);
        ui->EEGGraph->replot();
    }
}

void MainWindow::on_pcClearData_clicked()
{
    pcdevice->clear();
}

