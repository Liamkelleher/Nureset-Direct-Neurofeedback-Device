/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *pcDeviceFrame;
    QPushButton *upArrowButton;
    QPushButton *downArrowButton;
    QListWidget *display;
    QProgressBar *sessionProgressBar;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QLabel *timeElapsed;
    QPushButton *menuButton;
    QPushButton *powerButton;
    QPushButton *contactLight;
    QPushButton *treatmentLight;
    QPushButton *contactLostLight;
    QProgressBar *batteryCharge;
    QDateTimeEdit *dateTimeEdit;
    QWidget *cTGDisplay;
    QFrame *environmentManagerFrame;
    QListWidget *pcDeviceInfo;
    QLabel *pcDeviceLabel;
    QWidget *cTGPC;
    QFrame *line;
    QFrame *line_2;
    QLabel *EEGLabel;
    QLabel *ECLabel;
    QPushButton *batteryUseButton;
    QPushButton *batteryFullButton;
    QPushButton *batteryEmptyButton;
    QGraphicsView *eegGraphDisplay;
    QComboBox *nodeDropDown;
    QPushButton *batteryUseButton_2;
    QPushButton *batteryUseButton_3;
    QPushButton *batteryUseButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1620, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pcDeviceFrame = new QFrame(centralwidget);
        pcDeviceFrame->setObjectName(QString::fromUtf8("pcDeviceFrame"));
        pcDeviceFrame->setGeometry(QRect(10, 10, 800, 600));
        pcDeviceFrame->setAutoFillBackground(true);
        pcDeviceFrame->setFrameShape(QFrame::Box);
        pcDeviceFrame->setFrameShadow(QFrame::Raised);
        upArrowButton = new QPushButton(pcDeviceFrame);
        upArrowButton->setObjectName(QString::fromUtf8("upArrowButton"));
        upArrowButton->setGeometry(QRect(630, 250, 80, 25));
        downArrowButton = new QPushButton(pcDeviceFrame);
        downArrowButton->setObjectName(QString::fromUtf8("downArrowButton"));
        downArrowButton->setGeometry(QRect(630, 325, 83, 25));
        display = new QListWidget(pcDeviceFrame);
        display->setObjectName(QString::fromUtf8("display"));
        display->setEnabled(true);
        display->setGeometry(QRect(200, 150, 400, 300));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        display->setFont(font);
        display->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        display->setFocusPolicy(Qt::StrongFocus);
        display->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        display->setSelectionMode(QAbstractItemView::SingleSelection);
        display->setSelectionBehavior(QAbstractItemView::SelectItems);
        display->setSpacing(10);
        display->setSelectionRectVisible(false);
        display->setItemAlignment(Qt::AlignCenter);
        sessionProgressBar = new QProgressBar(pcDeviceFrame);
        sessionProgressBar->setObjectName(QString::fromUtf8("sessionProgressBar"));
        sessionProgressBar->setEnabled(true);
        sessionProgressBar->setGeometry(QRect(250, 390, 300, 30));
        sessionProgressBar->setValue(0);
        sessionProgressBar->setTextVisible(true);
        startButton = new QPushButton(pcDeviceFrame);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(360, 470, 80, 25));
        pauseButton = new QPushButton(pcDeviceFrame);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(250, 470, 80, 25));
        stopButton = new QPushButton(pcDeviceFrame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(470, 470, 80, 25));
        timeElapsed = new QLabel(pcDeviceFrame);
        timeElapsed->setObjectName(QString::fromUtf8("timeElapsed"));
        timeElapsed->setGeometry(QRect(325, 220, 150, 100));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(false);
        font1.setWeight(50);
        timeElapsed->setFont(font1);
        timeElapsed->setAutoFillBackground(false);
        timeElapsed->setAlignment(Qt::AlignCenter);
        menuButton = new QPushButton(pcDeviceFrame);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(200, 110, 83, 25));
        powerButton = new QPushButton(pcDeviceFrame);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(710, 10, 83, 25));
        contactLight = new QPushButton(pcDeviceFrame);
        contactLight->setObjectName(QString::fromUtf8("contactLight"));
        contactLight->setEnabled(false);
        contactLight->setGeometry(QRect(10, 10, 21, 25));
        contactLight->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 255);"));
        treatmentLight = new QPushButton(pcDeviceFrame);
        treatmentLight->setObjectName(QString::fromUtf8("treatmentLight"));
        treatmentLight->setEnabled(false);
        treatmentLight->setGeometry(QRect(50, 10, 21, 25));
        treatmentLight->setStyleSheet(QString::fromUtf8("background-color:green"));
        contactLostLight = new QPushButton(pcDeviceFrame);
        contactLostLight->setObjectName(QString::fromUtf8("contactLostLight"));
        contactLostLight->setEnabled(false);
        contactLostLight->setGeometry(QRect(90, 10, 21, 25));
        contactLostLight->setStyleSheet(QString::fromUtf8("background-color:red"));
        contactLostLight->setFlat(false);
        batteryCharge = new QProgressBar(pcDeviceFrame);
        batteryCharge->setObjectName(QString::fromUtf8("batteryCharge"));
        batteryCharge->setGeometry(QRect(740, 490, 50, 95));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(batteryCharge->sizePolicy().hasHeightForWidth());
        batteryCharge->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        batteryCharge->setFont(font2);
        batteryCharge->setLayoutDirection(Qt::LeftToRight);
        batteryCharge->setStyleSheet(QString::fromUtf8("QProgressBar::chunk{\n"
"	background-color: black;}"));
        batteryCharge->setMaximum(100);
        batteryCharge->setValue(100);
        batteryCharge->setAlignment(Qt::AlignCenter);
        batteryCharge->setTextVisible(false);
        batteryCharge->setOrientation(Qt::Vertical);
        batteryCharge->setInvertedAppearance(false);
        batteryCharge->setTextDirection(QProgressBar::TopToBottom);
        dateTimeEdit = new QDateTimeEdit(pcDeviceFrame);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(320, 260, 160, 40));
        cTGDisplay = new QWidget(pcDeviceFrame);
        cTGDisplay->setObjectName(QString::fromUtf8("cTGDisplay"));
        cTGDisplay->setGeometry(QRect(200, 150, 400, 300));
        upArrowButton->raise();
        downArrowButton->raise();
        display->raise();
        startButton->raise();
        pauseButton->raise();
        stopButton->raise();
        timeElapsed->raise();
        menuButton->raise();
        powerButton->raise();
        contactLight->raise();
        treatmentLight->raise();
        contactLostLight->raise();
        batteryCharge->raise();
        sessionProgressBar->raise();
        dateTimeEdit->raise();
        cTGDisplay->raise();
        environmentManagerFrame = new QFrame(centralwidget);
        environmentManagerFrame->setObjectName(QString::fromUtf8("environmentManagerFrame"));
        environmentManagerFrame->setGeometry(QRect(810, 10, 800, 600));
        environmentManagerFrame->setLayoutDirection(Qt::LeftToRight);
        environmentManagerFrame->setAutoFillBackground(true);
        environmentManagerFrame->setFrameShape(QFrame::Box);
        environmentManagerFrame->setFrameShadow(QFrame::Raised);
        pcDeviceInfo = new QListWidget(environmentManagerFrame);
        pcDeviceInfo->setObjectName(QString::fromUtf8("pcDeviceInfo"));
        pcDeviceInfo->setEnabled(true);
        pcDeviceInfo->setGeometry(QRect(10, 40, 400, 551));
        pcDeviceInfo->setFont(font);
        pcDeviceInfo->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        pcDeviceInfo->setFocusPolicy(Qt::StrongFocus);
        pcDeviceInfo->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        pcDeviceInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        pcDeviceInfo->setSelectionBehavior(QAbstractItemView::SelectItems);
        pcDeviceInfo->setSpacing(10);
        pcDeviceInfo->setSelectionRectVisible(false);
        pcDeviceInfo->setItemAlignment(Qt::AlignCenter);
        pcDeviceLabel = new QLabel(environmentManagerFrame);
        pcDeviceLabel->setObjectName(QString::fromUtf8("pcDeviceLabel"));
        pcDeviceLabel->setGeometry(QRect(10, 10, 401, 20));
        cTGPC = new QWidget(environmentManagerFrame);
        cTGPC->setObjectName(QString::fromUtf8("cTGPC"));
        cTGPC->setGeometry(QRect(10, 40, 400, 551));
        line = new QFrame(environmentManagerFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(420, 300, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(environmentManagerFrame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(410, 0, 20, 601));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        EEGLabel = new QLabel(environmentManagerFrame);
        EEGLabel->setObjectName(QString::fromUtf8("EEGLabel"));
        EEGLabel->setGeometry(QRect(430, 10, 361, 20));
        ECLabel = new QLabel(environmentManagerFrame);
        ECLabel->setObjectName(QString::fromUtf8("ECLabel"));
        ECLabel->setGeometry(QRect(430, 320, 361, 20));
        batteryUseButton = new QPushButton(environmentManagerFrame);
        batteryUseButton->setObjectName(QString::fromUtf8("batteryUseButton"));
        batteryUseButton->setGeometry(QRect(430, 350, 141, 25));
        batteryFullButton = new QPushButton(environmentManagerFrame);
        batteryFullButton->setObjectName(QString::fromUtf8("batteryFullButton"));
        batteryFullButton->setGeometry(QRect(430, 380, 141, 25));
        batteryEmptyButton = new QPushButton(environmentManagerFrame);
        batteryEmptyButton->setObjectName(QString::fromUtf8("batteryEmptyButton"));
        batteryEmptyButton->setGeometry(QRect(430, 410, 141, 25));
        eegGraphDisplay = new QGraphicsView(environmentManagerFrame);
        eegGraphDisplay->setObjectName(QString::fromUtf8("eegGraphDisplay"));
        eegGraphDisplay->setGeometry(QRect(430, 39, 360, 261));
        nodeDropDown = new QComboBox(environmentManagerFrame);
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->addItem(QString());
        nodeDropDown->setObjectName(QString::fromUtf8("nodeDropDown"));
        nodeDropDown->setGeometry(QRect(655, 10, 130, 20));
        batteryUseButton_2 = new QPushButton(environmentManagerFrame);
        batteryUseButton_2->setObjectName(QString::fromUtf8("batteryUseButton_2"));
        batteryUseButton_2->setGeometry(QRect(650, 350, 141, 25));
        batteryUseButton_3 = new QPushButton(environmentManagerFrame);
        batteryUseButton_3->setObjectName(QString::fromUtf8("batteryUseButton_3"));
        batteryUseButton_3->setGeometry(QRect(650, 380, 141, 25));
        batteryUseButton_4 = new QPushButton(environmentManagerFrame);
        batteryUseButton_4->setObjectName(QString::fromUtf8("batteryUseButton_4"));
        batteryUseButton_4->setGeometry(QRect(650, 410, 141, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        upArrowButton->setText(QCoreApplication::translate("MainWindow", "Up Arrow", nullptr));
        downArrowButton->setText(QCoreApplication::translate("MainWindow", "Down Arrow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        timeElapsed->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        powerButton->setText(QCoreApplication::translate("MainWindow", "On/Off", nullptr));
        contactLight->setText(QString());
        treatmentLight->setText(QString());
        contactLostLight->setText(QString());
        pcDeviceLabel->setText(QCoreApplication::translate("MainWindow", "PC Device", nullptr));
        EEGLabel->setText(QCoreApplication::translate("MainWindow", "EEG Display", nullptr));
        ECLabel->setText(QCoreApplication::translate("MainWindow", "Environment Controls", nullptr));
        batteryUseButton->setText(QCoreApplication::translate("MainWindow", "Use Battery", nullptr));
        batteryFullButton->setText(QCoreApplication::translate("MainWindow", "Batter Full", nullptr));
        batteryEmptyButton->setText(QCoreApplication::translate("MainWindow", "Batter Empty", nullptr));
        nodeDropDown->setItemText(0, QCoreApplication::translate("MainWindow", "Node 1", nullptr));
        nodeDropDown->setItemText(1, QCoreApplication::translate("MainWindow", "Node 2", nullptr));
        nodeDropDown->setItemText(2, QCoreApplication::translate("MainWindow", "Node 3", nullptr));
        nodeDropDown->setItemText(3, QCoreApplication::translate("MainWindow", "Node 4", nullptr));
        nodeDropDown->setItemText(4, QCoreApplication::translate("MainWindow", "Node 5", nullptr));
        nodeDropDown->setItemText(5, QCoreApplication::translate("MainWindow", "Node 6", nullptr));
        nodeDropDown->setItemText(6, QCoreApplication::translate("MainWindow", "Node 7", nullptr));
        nodeDropDown->setItemText(7, QCoreApplication::translate("MainWindow", "Node 8", nullptr));
        nodeDropDown->setItemText(8, QCoreApplication::translate("MainWindow", "Node 9", nullptr));

        batteryUseButton_2->setText(QCoreApplication::translate("MainWindow", "Activity 1", nullptr));
        batteryUseButton_3->setText(QCoreApplication::translate("MainWindow", "Activity 2", nullptr));
        batteryUseButton_4->setText(QCoreApplication::translate("MainWindow", "Activity 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
