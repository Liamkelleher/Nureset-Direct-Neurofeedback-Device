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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

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
    QStackedWidget *stackedWidget;
    QWidget *mainMenuWidget;
    QListWidget *menuList;
    QWidget *newSessionWidget;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *timerLabel;
    QWidget *sessionLogWidget;
    QListWidget *sessionList;
    QLabel *label_3;
    QWidget *dateTimeWidget;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_5;
    QFrame *environmentManagerFrame;
    QLabel *pcDeviceLabel;
    QFrame *line;
    QFrame *line_2;
    QLabel *EEGLabel;
    QLabel *ECLabel;
    QPushButton *batteryUseButton;
    QPushButton *batteryFullButton;
    QPushButton *batteryEmptyButton;
    QComboBox *nodeDropDown;
    QPushButton *batteryUseButton_2;
    QPushButton *batteryUseButton_3;
    QPushButton *batteryUseButton_4;
    QWidget *pcDeviceWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *pcDate;
    QLabel *pcDateValue;
    QLabel *pcElapsedTime;
    QLabel *pcElapsedValue;
    QSpacerItem *verticalSpacer;
    QLabel *pcSessionTitle;
    QLabel *pcNoDataTitle;
    QLabel *pcEEGTitle;
    QWidget *formLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *pcBeforeLabel;
    QLabel *pcBeforeValue;
    QLabel *pcAfterLabel;
    QLabel *pcAfterValue;
    QCustomPlot *EEGGraph;

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
        QFont font;
        font.setPointSize(10);
        downArrowButton->setFont(font);
        display = new QListWidget(pcDeviceFrame);
        display->setObjectName(QString::fromUtf8("display"));
        display->setEnabled(true);
        display->setGeometry(QRect(200, 150, 400, 300));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        display->setFont(font1);
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
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(false);
        font2.setWeight(50);
        timeElapsed->setFont(font2);
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
        batteryCharge->setFont(font);
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
        stackedWidget = new QStackedWidget(pcDeviceFrame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(200, 150, 400, 300));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(20);
        stackedWidget->setFont(font3);
        stackedWidget->setFocusPolicy(Qt::NoFocus);
        stackedWidget->setFrameShape(QFrame::Box);
        mainMenuWidget = new QWidget();
        mainMenuWidget->setObjectName(QString::fromUtf8("mainMenuWidget"));
        menuList = new QListWidget(mainMenuWidget);
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(menuList);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font4);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(menuList);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font4);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(menuList);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font4);
        menuList->setObjectName(QString::fromUtf8("menuList"));
        menuList->setGeometry(QRect(0, 0, 401, 301));
        menuList->setFrameShape(QFrame::NoFrame);
        menuList->setFrameShadow(QFrame::Plain);
        stackedWidget->addWidget(mainMenuWidget);
        newSessionWidget = new QWidget();
        newSessionWidget->setObjectName(QString::fromUtf8("newSessionWidget"));
        progressBar = new QProgressBar(newSessionWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 200, 301, 23));
        progressBar->setValue(0);
        label = new QLabel(newSessionWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 211, 31));
        QFont font5;
        font5.setPointSize(15);
        font5.setBold(true);
        font5.setItalic(true);
        font5.setWeight(75);
        label->setFont(font5);
        timerLabel = new QLabel(newSessionWidget);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        timerLabel->setGeometry(QRect(140, 90, 131, 41));
        QFont font6;
        font6.setPointSize(30);
        font6.setBold(true);
        font6.setWeight(75);
        font6.setStrikeOut(false);
        font6.setKerning(true);
        timerLabel->setFont(font6);
        stackedWidget->addWidget(newSessionWidget);
        sessionLogWidget = new QWidget();
        sessionLogWidget->setObjectName(QString::fromUtf8("sessionLogWidget"));
        sessionList = new QListWidget(sessionLogWidget);
        sessionList->setObjectName(QString::fromUtf8("sessionList"));
        sessionList->setGeometry(QRect(10, 60, 381, 231));
        label_3 = new QLabel(sessionLogWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 171, 31));
        label_3->setFont(font5);
        stackedWidget->addWidget(sessionLogWidget);
        dateTimeWidget = new QWidget();
        dateTimeWidget->setObjectName(QString::fromUtf8("dateTimeWidget"));
        label_4 = new QLabel(dateTimeWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 171, 31));
        label_4->setFont(font5);
        dateTimeEdit = new QDateTimeEdit(dateTimeWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(70, 110, 261, 61));
        label_5 = new QLabel(dateTimeWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 80, 171, 31));
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setItalic(true);
        font7.setWeight(75);
        label_5->setFont(font7);
        stackedWidget->addWidget(dateTimeWidget);
        upArrowButton->raise();
        downArrowButton->raise();
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
        display->raise();
        stackedWidget->raise();
        environmentManagerFrame = new QFrame(centralwidget);
        environmentManagerFrame->setObjectName(QString::fromUtf8("environmentManagerFrame"));
        environmentManagerFrame->setGeometry(QRect(810, 10, 800, 600));
        environmentManagerFrame->setLayoutDirection(Qt::LeftToRight);
        environmentManagerFrame->setAutoFillBackground(true);
        environmentManagerFrame->setFrameShape(QFrame::Box);
        environmentManagerFrame->setFrameShadow(QFrame::Raised);
        pcDeviceLabel = new QLabel(environmentManagerFrame);
        pcDeviceLabel->setObjectName(QString::fromUtf8("pcDeviceLabel"));
        pcDeviceLabel->setGeometry(QRect(10, 10, 401, 20));
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
        nodeDropDown = new QComboBox(environmentManagerFrame);
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
        pcDeviceWidget = new QWidget(environmentManagerFrame);
        pcDeviceWidget->setObjectName(QString::fromUtf8("pcDeviceWidget"));
        pcDeviceWidget->setGeometry(QRect(10, 40, 401, 551));
        pcDeviceWidget->setAutoFillBackground(false);
        formLayoutWidget = new QWidget(pcDeviceWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 40, 371, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        pcDate = new QLabel(formLayoutWidget);
        pcDate->setObjectName(QString::fromUtf8("pcDate"));

        formLayout->setWidget(0, QFormLayout::LabelRole, pcDate);

        pcDateValue = new QLabel(formLayoutWidget);
        pcDateValue->setObjectName(QString::fromUtf8("pcDateValue"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pcDateValue);

        pcElapsedTime = new QLabel(formLayoutWidget);
        pcElapsedTime->setObjectName(QString::fromUtf8("pcElapsedTime"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pcElapsedTime);

        pcElapsedValue = new QLabel(formLayoutWidget);
        pcElapsedValue->setObjectName(QString::fromUtf8("pcElapsedValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pcElapsedValue);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::SpanningRole, verticalSpacer);

        pcSessionTitle = new QLabel(pcDeviceWidget);
        pcSessionTitle->setObjectName(QString::fromUtf8("pcSessionTitle"));
        pcSessionTitle->setGeometry(QRect(0, 0, 248, 25));
        pcNoDataTitle = new QLabel(pcDeviceWidget);
        pcNoDataTitle->setObjectName(QString::fromUtf8("pcNoDataTitle"));
        pcNoDataTitle->setEnabled(false);
        pcNoDataTitle->setGeometry(QRect(50, 210, 294, 62));
        pcEEGTitle = new QLabel(pcDeviceWidget);
        pcEEGTitle->setObjectName(QString::fromUtf8("pcEEGTitle"));
        pcEEGTitle->setGeometry(QRect(20, 170, 369, 25));
        formLayoutWidget_2 = new QWidget(pcDeviceWidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 210, 361, 281));
        verticalLayout = new QVBoxLayout(formLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pcBeforeLabel = new QLabel(formLayoutWidget_2);
        pcBeforeLabel->setObjectName(QString::fromUtf8("pcBeforeLabel"));

        verticalLayout->addWidget(pcBeforeLabel);

        pcBeforeValue = new QLabel(formLayoutWidget_2);
        pcBeforeValue->setObjectName(QString::fromUtf8("pcBeforeValue"));

        verticalLayout->addWidget(pcBeforeValue);

        pcAfterLabel = new QLabel(formLayoutWidget_2);
        pcAfterLabel->setObjectName(QString::fromUtf8("pcAfterLabel"));

        verticalLayout->addWidget(pcAfterLabel);

        pcAfterValue = new QLabel(formLayoutWidget_2);
        pcAfterValue->setObjectName(QString::fromUtf8("pcAfterValue"));

        verticalLayout->addWidget(pcAfterValue);

        EEGGraph = new QCustomPlot(environmentManagerFrame);
        EEGGraph->setObjectName(QString::fromUtf8("EEGGraph"));
        EEGGraph->setGeometry(QRect(440, 40, 341, 251));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


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

        const bool __sortingEnabled = menuList->isSortingEnabled();
        menuList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = menuList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "New Session", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = menuList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Session Logs", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = menuList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Time and Date", nullptr));
        menuList->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("MainWindow", "New Session", nullptr));
        timerLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Session Logs:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Time and Date:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter today's date", nullptr));
        pcDeviceLabel->setText(QCoreApplication::translate("MainWindow", "PC Device", nullptr));
        EEGLabel->setText(QCoreApplication::translate("MainWindow", "EEG Display", nullptr));
        ECLabel->setText(QCoreApplication::translate("MainWindow", "Environment Controls", nullptr));
        batteryUseButton->setText(QCoreApplication::translate("MainWindow", "Use Battery", nullptr));
        batteryFullButton->setText(QCoreApplication::translate("MainWindow", "Batter Full", nullptr));
        batteryEmptyButton->setText(QCoreApplication::translate("MainWindow", "Batter Empty", nullptr));
        batteryUseButton_2->setText(QCoreApplication::translate("MainWindow", "Activity 1", nullptr));
        batteryUseButton_3->setText(QCoreApplication::translate("MainWindow", "Activity 2", nullptr));
        batteryUseButton_4->setText(QCoreApplication::translate("MainWindow", "Activity 3", nullptr));
        pcDate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Date:</span></p></body></html>", nullptr));
        pcDateValue->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        pcElapsedTime->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Time Elapsed:</span></p></body></html>", nullptr));
        pcElapsedValue->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        pcSessionTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Session History View</span></p></body></html>", nullptr));
        pcNoDataTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Currently no session history</span></p><p align=\"center\"><span style=\" font-size:16pt;\">available</span></p></body></html>", nullptr));
        pcEEGTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">EEG Baselines</span></p></body></html>", nullptr));
        pcBeforeLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Before Baseline:</span></p></body></html>", nullptr));
        pcBeforeValue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">N/A</span></p></body></html>", nullptr));
        pcAfterLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">After Baseline:</span></p></body></html>", nullptr));
        pcAfterValue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">N/A</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
