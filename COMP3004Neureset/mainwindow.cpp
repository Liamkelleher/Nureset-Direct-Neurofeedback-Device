#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->sessionProgressBar->hide();
    ui->timeElapsed->hide();
    hidden = true;
    sesActive = false;

    // Create LightIndicator instances for each light indicator button
    contactLightIndicator = new LightIndicator(ui->contactLight);
    treatmentLightIndicator = new LightIndicator(ui->treatmentLight);
    contactLostLightIndicator = new LightIndicator(ui->contactLostLight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_upArrowButton_clicked()
{

    if (ui->display->count() != 0)
    {
        int curr = menuList.indexOf(ui->display->currentItem());

        if (curr > 0)
        {
            ui->display->setCurrentItem(menuList[curr - 1]);
        }
    }

}


void MainWindow::on_downArrowButton_clicked()
{
    if (ui->display->count() != 0)
    {
        int curr = menuList.indexOf(ui->display->currentItem());

        if (curr < (menuList.length() - 1))
        {
            ui->display->setCurrentItem(menuList[curr + 1]);
        }
    }
}


void MainWindow::on_startButton_clicked()
{
    if (ui->display->currentItem() == menuList[0])
    {
        ui->display->clear();

        ui->sessionProgressBar->show();
        ui->timeElapsed->show();

        hidden = false;
        sesActive = true;
    }

    if (ui->display->currentItem() == menuList[1])
    {
        ui->display->clear();
        //Show session logs

        //Uploading to PC device
    }

    if (ui->display->currentItem() == menuList[2])
    {
        ui->display->clear();

        //time and date adjustment
    }
}


void MainWindow::on_stopButton_clicked()
{
    if (sesActive)
    {
        //stop session protocol

        ui->sessionProgressBar->hide();
        ui->timeElapsed->hide();

        hidden = true;
        sesActive = false;

        createMenuList();

        ui->display->setCurrentItem(menuList[0]);
    }
}


void MainWindow::on_powerButton_clicked()
{
    if (deviceOn)
    {
        deviceOn = false;

        if (sesActive)
        {
            //stop session protocol

            ui->sessionProgressBar->hide();
            ui->timeElapsed->hide();

            hidden = true;
            sesActive = false;
        }

        ui->display->clear();
    }

    else
    {
        deviceOn = true;

        createMenuList();

        ui->display->setCurrentItem(menuList[0]);
    }
}


void MainWindow::on_menuButton_clicked()
{
    if (deviceOn && !sesActive)
    {
        ui->display->clear();

        createMenuList();

        ui->display->setCurrentItem(menuList[0]);
    }
}

void MainWindow::createMenuList()
{
    menuList[0] = new QListWidgetItem("NEW SESSION");
    menuList[1] = new QListWidgetItem("SESSION LOGS");
    menuList[2] = new QListWidgetItem("TIME AND DATE");

    menuList[0]->setTextAlignment(4);
    menuList[1]->setTextAlignment(4);
    menuList[2]->setTextAlignment(4);

    ui->display->addItem(menuList[0]);
    ui->display->addItem(menuList[1]);
    ui->display->addItem(menuList[2]);
}


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

