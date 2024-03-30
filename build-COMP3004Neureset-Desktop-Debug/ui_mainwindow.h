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
#include <QtWidgets/QFrame>
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
    QWidget *cTGDisplay;
    QProgressBar *batteryCharge;
    QFrame *environmentManagerFrame;
    QListWidget *pcDeviceInfo;
    QLabel *pcDeviceLabel;
    QWidget *cTGPC;
    QFrame *line;
    QFrame *line_2;
    QLabel *EEGLabel;
    QLabel *ECLabel;
    QPushButton *eegNode1;
    QPushButton *eegNode2;
    QPushButton *eegNode3;
    QPushButton *eegNode4;
    QPushButton *eegNode5;
    QPushButton *eegNode9;
    QPushButton *eegNode8;
    QPushButton *eegNode7;
    QPushButton *eegNode6;
    QPushButton *eegNode10;
    QPushButton *eegNode11;
    QPushButton *eegNode12;
    QPushButton *eegNode13;
    QPushButton *eegNode14;
    QPushButton *eegNode15;
    QPushButton *eegNode17;
    QPushButton *eegNode21;
    QPushButton *eegNode19;
    QPushButton *eegNode18;
    QPushButton *eegNode20;
    QPushButton *eegNode16;
    QPushButton *batteryUseButton;
    QPushButton *batteryFullButton;
    QPushButton *batteryEmptyButton;

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
        contactLight->setStyleSheet(QString::fromUtf8("background-color:blue"));
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
        cTGDisplay = new QWidget(pcDeviceFrame);
        cTGDisplay->setObjectName(QString::fromUtf8("cTGDisplay"));
        cTGDisplay->setGeometry(QRect(200, 150, 400, 300));
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
        pcDeviceInfo->setGeometry(QRect(10, 30, 400, 561));
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
        cTGPC->setGeometry(QRect(10, 30, 400, 560));
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
        eegNode1 = new QPushButton(environmentManagerFrame);
        eegNode1->setObjectName(QString::fromUtf8("eegNode1"));
        eegNode1->setEnabled(false);
        eegNode1->setGeometry(QRect(430, 40, 41, 41));
        eegNode1->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode2 = new QPushButton(environmentManagerFrame);
        eegNode2->setObjectName(QString::fromUtf8("eegNode2"));
        eegNode2->setEnabled(false);
        eegNode2->setGeometry(QRect(490, 40, 41, 41));
        eegNode2->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode3 = new QPushButton(environmentManagerFrame);
        eegNode3->setObjectName(QString::fromUtf8("eegNode3"));
        eegNode3->setEnabled(false);
        eegNode3->setGeometry(QRect(550, 40, 41, 41));
        eegNode3->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode4 = new QPushButton(environmentManagerFrame);
        eegNode4->setObjectName(QString::fromUtf8("eegNode4"));
        eegNode4->setEnabled(false);
        eegNode4->setGeometry(QRect(630, 40, 41, 41));
        eegNode4->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode5 = new QPushButton(environmentManagerFrame);
        eegNode5->setObjectName(QString::fromUtf8("eegNode5"));
        eegNode5->setEnabled(false);
        eegNode5->setGeometry(QRect(690, 40, 41, 41));
        eegNode5->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode9 = new QPushButton(environmentManagerFrame);
        eegNode9->setObjectName(QString::fromUtf8("eegNode9"));
        eegNode9->setEnabled(false);
        eegNode9->setGeometry(QRect(550, 100, 41, 41));
        eegNode9->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode8 = new QPushButton(environmentManagerFrame);
        eegNode8->setObjectName(QString::fromUtf8("eegNode8"));
        eegNode8->setEnabled(false);
        eegNode8->setGeometry(QRect(490, 100, 41, 41));
        eegNode8->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode7 = new QPushButton(environmentManagerFrame);
        eegNode7->setObjectName(QString::fromUtf8("eegNode7"));
        eegNode7->setEnabled(false);
        eegNode7->setGeometry(QRect(430, 100, 41, 41));
        eegNode7->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode6 = new QPushButton(environmentManagerFrame);
        eegNode6->setObjectName(QString::fromUtf8("eegNode6"));
        eegNode6->setEnabled(false);
        eegNode6->setGeometry(QRect(750, 40, 41, 41));
        eegNode6->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode10 = new QPushButton(environmentManagerFrame);
        eegNode10->setObjectName(QString::fromUtf8("eegNode10"));
        eegNode10->setEnabled(false);
        eegNode10->setGeometry(QRect(630, 100, 41, 41));
        eegNode10->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode11 = new QPushButton(environmentManagerFrame);
        eegNode11->setObjectName(QString::fromUtf8("eegNode11"));
        eegNode11->setEnabled(false);
        eegNode11->setGeometry(QRect(690, 100, 41, 41));
        eegNode11->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode12 = new QPushButton(environmentManagerFrame);
        eegNode12->setObjectName(QString::fromUtf8("eegNode12"));
        eegNode12->setEnabled(false);
        eegNode12->setGeometry(QRect(750, 100, 41, 41));
        eegNode12->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode13 = new QPushButton(environmentManagerFrame);
        eegNode13->setObjectName(QString::fromUtf8("eegNode13"));
        eegNode13->setEnabled(false);
        eegNode13->setGeometry(QRect(430, 160, 41, 41));
        eegNode13->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode14 = new QPushButton(environmentManagerFrame);
        eegNode14->setObjectName(QString::fromUtf8("eegNode14"));
        eegNode14->setEnabled(false);
        eegNode14->setGeometry(QRect(490, 160, 41, 41));
        eegNode14->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode15 = new QPushButton(environmentManagerFrame);
        eegNode15->setObjectName(QString::fromUtf8("eegNode15"));
        eegNode15->setEnabled(false);
        eegNode15->setGeometry(QRect(550, 160, 41, 41));
        eegNode15->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode17 = new QPushButton(environmentManagerFrame);
        eegNode17->setObjectName(QString::fromUtf8("eegNode17"));
        eegNode17->setEnabled(false);
        eegNode17->setGeometry(QRect(690, 160, 41, 41));
        eegNode17->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode21 = new QPushButton(environmentManagerFrame);
        eegNode21->setObjectName(QString::fromUtf8("eegNode21"));
        eegNode21->setEnabled(false);
        eegNode21->setGeometry(QRect(550, 230, 41, 41));
        eegNode21->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode19 = new QPushButton(environmentManagerFrame);
        eegNode19->setObjectName(QString::fromUtf8("eegNode19"));
        eegNode19->setEnabled(false);
        eegNode19->setGeometry(QRect(430, 230, 41, 41));
        eegNode19->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode18 = new QPushButton(environmentManagerFrame);
        eegNode18->setObjectName(QString::fromUtf8("eegNode18"));
        eegNode18->setEnabled(false);
        eegNode18->setGeometry(QRect(750, 160, 41, 41));
        eegNode18->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode20 = new QPushButton(environmentManagerFrame);
        eegNode20->setObjectName(QString::fromUtf8("eegNode20"));
        eegNode20->setEnabled(false);
        eegNode20->setGeometry(QRect(490, 230, 41, 41));
        eegNode20->setStyleSheet(QString::fromUtf8("background-color:white"));
        eegNode16 = new QPushButton(environmentManagerFrame);
        eegNode16->setObjectName(QString::fromUtf8("eegNode16"));
        eegNode16->setEnabled(false);
        eegNode16->setGeometry(QRect(630, 160, 41, 41));
        eegNode16->setStyleSheet(QString::fromUtf8("background-color:white"));
        batteryUseButton = new QPushButton(environmentManagerFrame);
        batteryUseButton->setObjectName(QString::fromUtf8("batteryUseButton"));
        batteryUseButton->setGeometry(QRect(430, 350, 141, 25));
        batteryFullButton = new QPushButton(environmentManagerFrame);
        batteryFullButton->setObjectName(QString::fromUtf8("batteryFullButton"));
        batteryFullButton->setGeometry(QRect(430, 380, 141, 25));
        batteryEmptyButton = new QPushButton(environmentManagerFrame);
        batteryEmptyButton->setObjectName(QString::fromUtf8("batteryEmptyButton"));
        batteryEmptyButton->setGeometry(QRect(430, 410, 141, 25));
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
        eegNode1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        eegNode2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        eegNode3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        eegNode4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        eegNode5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        eegNode9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        eegNode8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        eegNode7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        eegNode6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        eegNode10->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        eegNode11->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        eegNode12->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        eegNode13->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        eegNode14->setText(QCoreApplication::translate("MainWindow", "14", nullptr));
        eegNode15->setText(QCoreApplication::translate("MainWindow", "15", nullptr));
        eegNode17->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        eegNode21->setText(QCoreApplication::translate("MainWindow", "21", nullptr));
        eegNode19->setText(QCoreApplication::translate("MainWindow", "19", nullptr));
        eegNode18->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        eegNode20->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        eegNode16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        batteryUseButton->setText(QCoreApplication::translate("MainWindow", "Use Battery", nullptr));
        batteryFullButton->setText(QCoreApplication::translate("MainWindow", "Batter Full", nullptr));
        batteryEmptyButton->setText(QCoreApplication::translate("MainWindow", "Batter Empty", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
