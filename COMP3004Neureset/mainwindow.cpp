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

    initializeGraph(ui->EEGGraph);
    ui->EEGGraph->yAxis->setRange(-500, 500);
    initializeGraph(ui->baselineGraph);
    ui->baselineGraph->yAxis->setRange(-150, 150);

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

//Button event-handlers for all ui components
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

void MainWindow::on_pcClearData_clicked() { pcdevice->clear(); }

//Communication between the NDC and the PCDevice
void MainWindow::uploadSession(Session* session) { pcdevice->uploadToPC(session); }

//Communication between the NDC and the EEGGraph
void MainWindow::updateGraph(EEGNode* node)
{
    //Sets graph to an empty state
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
        if (wave.size() < 501)
        {
            updateGraph(node);
            return;
        }
        ui->EEGGraph->graph()->setData(x, wave);
        ui->EEGGraph->replot();
    }
}

//Default Settings for EEGGraph
void MainWindow::initializeGraph(QCustomPlot *graph)
{
    graph->addGraph();
    graph->xAxis->setRange(0, 5);
    graph->xAxis->setLabel("Time (seconds)");
    graph->yAxis->setLabel("Voltage (μV)");
    graph->axisRect()->setupFullAxesBox(false);
    graph->setBackground(Qt::NoBrush); // Makes the plot's background transparent
    graph->axisRect()->setBackground(Qt::NoBrush); // Makes the canvas background transparent
    QPen plotPen(QColor(0, 0, 255));
    plotPen.setWidthF(1.5);
    graph->graph()->setPen(plotPen);
    graph->xAxis->setLabelFont(QFont("sans", 12));
    graph->yAxis->setLabelFont(QFont("sans", 12));
    QPen gridPen(QColor(200, 200, 200), 0, Qt::DashLine);
    graph->xAxis->grid()->setPen(gridPen);
    graph->yAxis->grid()->setPen(gridPen);
}
