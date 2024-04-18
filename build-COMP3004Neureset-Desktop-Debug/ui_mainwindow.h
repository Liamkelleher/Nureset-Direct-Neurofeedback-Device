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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
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
    QWidget *dateTimeWidget;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_5;
    QWidget *sessionCompleteWidget;
    QProgressBar *progressBar_2;
    QLabel *label_2;
    QPushButton *contactLostLight;
    QPushButton *treatmentLight;
    QPushButton *contactLight;
    QFrame *environmentManagerFrame;
    QLabel *pcDeviceLabel;
    QFrame *line;
    QFrame *line_2;
    QLabel *EEGLabel;
    QLabel *ECLabel;
    QPushButton *batteryUseButton;
    QPushButton *batteryFullButton;
    QComboBox *nodeDropDown;
    QPushButton *terminateConnection;
    QWidget *pcDeviceWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *pcDate;
    QLabel *pcDateValue;
    QLabel *pcElapsedTime;
    QLabel *pcElapsedValue;
    QLabel *pcSessionTitle;
    QLabel *pcNoDataTitle;
    QLabel *pcEEGTitle;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *pcBeforeLabel;
    QLabel *pcAfterLabel;
    QLabel *pcBeforeValue;
    QLabel *pcAfterValue;
    QPushButton *pcClearData;
    QTableWidget *pcTable;
    QCustomPlot *baselineGraph;
    QLabel *pcGraphTitle;
    QLabel *label_3;
    QCustomPlot *EEGGraph;
    QPushButton *establishConnection;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1562, 621);
        MainWindow->setMinimumSize(QSize(1560, 621));
        MainWindow->setMaximumSize(QSize(1562, 621));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pcDeviceFrame = new QFrame(centralwidget);
        pcDeviceFrame->setObjectName(QString::fromUtf8("pcDeviceFrame"));
        pcDeviceFrame->setGeometry(QRect(10, 10, 601, 600));
        pcDeviceFrame->setAutoFillBackground(true);
        pcDeviceFrame->setFrameShape(QFrame::Box);
        pcDeviceFrame->setFrameShadow(QFrame::Raised);
        upArrowButton = new QPushButton(pcDeviceFrame);
        upArrowButton->setObjectName(QString::fromUtf8("upArrowButton"));
        upArrowButton->setGeometry(QRect(500, 240, 51, 25));
        upArrowButton->setStyleSheet(QString::fromUtf8(""));
        downArrowButton = new QPushButton(pcDeviceFrame);
        downArrowButton->setObjectName(QString::fromUtf8("downArrowButton"));
        downArrowButton->setGeometry(QRect(500, 315, 51, 25));
        QFont font;
        font.setPointSize(10);
        downArrowButton->setFont(font);
        display = new QListWidget(pcDeviceFrame);
        display->setObjectName(QString::fromUtf8("display"));
        display->setEnabled(true);
        display->setGeometry(QRect(70, 140, 400, 300));
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
        sessionProgressBar->setGeometry(QRect(120, 380, 300, 30));
        sessionProgressBar->setValue(0);
        sessionProgressBar->setTextVisible(true);
        startButton = new QPushButton(pcDeviceFrame);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(230, 460, 80, 25));
        pauseButton = new QPushButton(pcDeviceFrame);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(120, 460, 80, 25));
        stopButton = new QPushButton(pcDeviceFrame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(340, 460, 80, 25));
        timeElapsed = new QLabel(pcDeviceFrame);
        timeElapsed->setObjectName(QString::fromUtf8("timeElapsed"));
        timeElapsed->setGeometry(QRect(195, 210, 150, 100));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(false);
        font2.setWeight(50);
        timeElapsed->setFont(font2);
        timeElapsed->setAutoFillBackground(false);
        timeElapsed->setAlignment(Qt::AlignCenter);
        menuButton = new QPushButton(pcDeviceFrame);
        menuButton->setObjectName(QString::fromUtf8("menuButton"));
        menuButton->setGeometry(QRect(230, 100, 83, 25));
        powerButton = new QPushButton(pcDeviceFrame);
        powerButton->setObjectName(QString::fromUtf8("powerButton"));
        powerButton->setGeometry(QRect(390, 100, 83, 25));
        batteryCharge = new QProgressBar(pcDeviceFrame);
        batteryCharge->setObjectName(QString::fromUtf8("batteryCharge"));
        batteryCharge->setGeometry(QRect(540, 520, 51, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(batteryCharge->sizePolicy().hasHeightForWidth());
        batteryCharge->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setKerning(true);
        batteryCharge->setFont(font3);
        batteryCharge->setLayoutDirection(Qt::LeftToRight);
        batteryCharge->setAutoFillBackground(false);
        batteryCharge->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"            border: 2px solid grey;\n"
"            border-radius: 10px;\n"
"			background-color: #ececec;\n"
"			color: rgb(255, 255, 255);\n"
"        }\n"
"\n"
"        QProgressBar::chunk {\n"
"            background-color:  #5BC236;\n"
"            border-radius: 7px; \n"
"			margin: 2px\n"
"        }"));
        batteryCharge->setMaximum(150);
        batteryCharge->setValue(150);
        batteryCharge->setAlignment(Qt::AlignCenter);
        batteryCharge->setTextVisible(true);
        batteryCharge->setOrientation(Qt::Vertical);
        batteryCharge->setInvertedAppearance(false);
        batteryCharge->setTextDirection(QProgressBar::TopToBottom);
        stackedWidget = new QStackedWidget(pcDeviceFrame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 140, 400, 300));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(20);
        stackedWidget->setFont(font4);
        stackedWidget->setFocusPolicy(Qt::NoFocus);
        stackedWidget->setFrameShape(QFrame::Box);
        mainMenuWidget = new QWidget();
        mainMenuWidget->setObjectName(QString::fromUtf8("mainMenuWidget"));
        menuList = new QListWidget(mainMenuWidget);
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(menuList);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font5);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(menuList);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font5);
        QFont font6;
        font6.setPointSize(17);
        font6.setBold(true);
        font6.setWeight(75);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(menuList);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font6);
        menuList->setObjectName(QString::fromUtf8("menuList"));
        menuList->setGeometry(QRect(0, 0, 401, 301));
        menuList->setFrameShape(QFrame::NoFrame);
        menuList->setFrameShadow(QFrame::Plain);
        menuList->setMovement(QListView::Static);
        menuList->setViewMode(QListView::ListMode);
        menuList->setUniformItemSizes(false);
        menuList->setSortingEnabled(false);
        stackedWidget->addWidget(mainMenuWidget);
        newSessionWidget = new QWidget();
        newSessionWidget->setObjectName(QString::fromUtf8("newSessionWidget"));
        progressBar = new QProgressBar(newSessionWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 192, 301, 31));
        progressBar->setValue(0);
        label = new QLabel(newSessionWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 211, 31));
        QFont font7;
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setItalic(true);
        font7.setWeight(75);
        label->setFont(font7);
        timerLabel = new QLabel(newSessionWidget);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        timerLabel->setGeometry(QRect(140, 90, 131, 41));
        QFont font8;
        font8.setPointSize(30);
        font8.setBold(true);
        font8.setWeight(75);
        font8.setStrikeOut(false);
        font8.setKerning(true);
        timerLabel->setFont(font8);
        stackedWidget->addWidget(newSessionWidget);
        sessionLogWidget = new QWidget();
        sessionLogWidget->setObjectName(QString::fromUtf8("sessionLogWidget"));
        sessionList = new QListWidget(sessionLogWidget);
        sessionList->setObjectName(QString::fromUtf8("sessionList"));
        sessionList->setGeometry(QRect(0, 0, 401, 301));
        stackedWidget->addWidget(sessionLogWidget);
        dateTimeWidget = new QWidget();
        dateTimeWidget->setObjectName(QString::fromUtf8("dateTimeWidget"));
        label_4 = new QLabel(dateTimeWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 171, 31));
        label_4->setFont(font7);
        dateTimeEdit = new QDateTimeEdit(dateTimeWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(70, 110, 261, 61));
        label_5 = new QLabel(dateTimeWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 80, 171, 31));
        QFont font9;
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setItalic(true);
        font9.setWeight(75);
        label_5->setFont(font9);
        stackedWidget->addWidget(dateTimeWidget);
        sessionCompleteWidget = new QWidget();
        sessionCompleteWidget->setObjectName(QString::fromUtf8("sessionCompleteWidget"));
        progressBar_2 = new QProgressBar(sessionCompleteWidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(50, 192, 301, 31));
        progressBar_2->setValue(100);
        progressBar_2->setInvertedAppearance(false);
        label_2 = new QLabel(sessionCompleteWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 130, 301, 31));
        QFont font10;
        font10.setPointSize(20);
        font10.setBold(true);
        font10.setItalic(false);
        font10.setWeight(75);
        label_2->setFont(font10);
        stackedWidget->addWidget(sessionCompleteWidget);
        contactLostLight = new QPushButton(pcDeviceFrame);
        contactLostLight->setObjectName(QString::fromUtf8("contactLostLight"));
        contactLostLight->setEnabled(false);
        contactLostLight->setGeometry(QRect(90, 100, 15, 25));
        contactLostLight->setStyleSheet(QString::fromUtf8("background-color:red"));
        contactLostLight->setFlat(false);
        treatmentLight = new QPushButton(pcDeviceFrame);
        treatmentLight->setObjectName(QString::fromUtf8("treatmentLight"));
        treatmentLight->setEnabled(false);
        treatmentLight->setGeometry(QRect(110, 100, 16, 25));
        treatmentLight->setStyleSheet(QString::fromUtf8("background-color:green"));
        contactLight = new QPushButton(pcDeviceFrame);
        contactLight->setObjectName(QString::fromUtf8("contactLight"));
        contactLight->setEnabled(false);
        contactLight->setGeometry(QRect(70, 100, 16, 25));
        contactLight->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 255);"));
        sessionProgressBar->raise();
        timeElapsed->raise();
        display->raise();
        upArrowButton->raise();
        downArrowButton->raise();
        startButton->raise();
        pauseButton->raise();
        stopButton->raise();
        menuButton->raise();
        powerButton->raise();
        batteryCharge->raise();
        stackedWidget->raise();
        contactLostLight->raise();
        treatmentLight->raise();
        contactLight->raise();
        environmentManagerFrame = new QFrame(centralwidget);
        environmentManagerFrame->setObjectName(QString::fromUtf8("environmentManagerFrame"));
        environmentManagerFrame->setGeometry(QRect(610, 10, 941, 600));
        environmentManagerFrame->setLayoutDirection(Qt::LeftToRight);
        environmentManagerFrame->setAutoFillBackground(true);
        environmentManagerFrame->setFrameShape(QFrame::Box);
        environmentManagerFrame->setFrameShadow(QFrame::Raised);
        pcDeviceLabel = new QLabel(environmentManagerFrame);
        pcDeviceLabel->setObjectName(QString::fromUtf8("pcDeviceLabel"));
        pcDeviceLabel->setGeometry(QRect(10, 10, 401, 20));
        line = new QFrame(environmentManagerFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(510, 300, 431, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(environmentManagerFrame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(500, 0, 20, 601));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        EEGLabel = new QLabel(environmentManagerFrame);
        EEGLabel->setObjectName(QString::fromUtf8("EEGLabel"));
        EEGLabel->setGeometry(QRect(520, 10, 361, 20));
        ECLabel = new QLabel(environmentManagerFrame);
        ECLabel->setObjectName(QString::fromUtf8("ECLabel"));
        ECLabel->setGeometry(QRect(520, 320, 361, 20));
        batteryUseButton = new QPushButton(environmentManagerFrame);
        batteryUseButton->setObjectName(QString::fromUtf8("batteryUseButton"));
        batteryUseButton->setGeometry(QRect(520, 350, 141, 25));
        batteryFullButton = new QPushButton(environmentManagerFrame);
        batteryFullButton->setObjectName(QString::fromUtf8("batteryFullButton"));
        batteryFullButton->setGeometry(QRect(520, 400, 141, 25));
        nodeDropDown = new QComboBox(environmentManagerFrame);
        nodeDropDown->setObjectName(QString::fromUtf8("nodeDropDown"));
        nodeDropDown->setGeometry(QRect(790, 10, 130, 20));
        terminateConnection = new QPushButton(environmentManagerFrame);
        terminateConnection->setObjectName(QString::fromUtf8("terminateConnection"));
        terminateConnection->setGeometry(QRect(720, 350, 201, 25));
        pcDeviceWidget = new QWidget(environmentManagerFrame);
        pcDeviceWidget->setObjectName(QString::fromUtf8("pcDeviceWidget"));
        pcDeviceWidget->setGeometry(QRect(10, 40, 491, 551));
        pcDeviceWidget->setAutoFillBackground(false);
        formLayoutWidget = new QWidget(pcDeviceWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 30, 281, 54));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
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

        pcSessionTitle = new QLabel(pcDeviceWidget);
        pcSessionTitle->setObjectName(QString::fromUtf8("pcSessionTitle"));
        pcSessionTitle->setGeometry(QRect(0, 0, 248, 25));
        pcNoDataTitle = new QLabel(pcDeviceWidget);
        pcNoDataTitle->setObjectName(QString::fromUtf8("pcNoDataTitle"));
        pcNoDataTitle->setEnabled(false);
        pcNoDataTitle->setGeometry(QRect(100, 210, 294, 62));
        pcEEGTitle = new QLabel(pcDeviceWidget);
        pcEEGTitle->setObjectName(QString::fromUtf8("pcEEGTitle"));
        pcEEGTitle->setGeometry(QRect(0, 100, 160, 25));
        formLayoutWidget_2 = new QWidget(pcDeviceWidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 130, 281, 66));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        pcBeforeLabel = new QLabel(formLayoutWidget_2);
        pcBeforeLabel->setObjectName(QString::fromUtf8("pcBeforeLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pcBeforeLabel);

        pcAfterLabel = new QLabel(formLayoutWidget_2);
        pcAfterLabel->setObjectName(QString::fromUtf8("pcAfterLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pcAfterLabel);

        pcBeforeValue = new QLabel(formLayoutWidget_2);
        pcBeforeValue->setObjectName(QString::fromUtf8("pcBeforeValue"));
        pcBeforeValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pcBeforeValue);

        pcAfterValue = new QLabel(formLayoutWidget_2);
        pcAfterValue->setObjectName(QString::fromUtf8("pcAfterValue"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pcAfterValue);

        pcClearData = new QPushButton(pcDeviceWidget);
        pcClearData->setObjectName(QString::fromUtf8("pcClearData"));
        pcClearData->setGeometry(QRect(0, 520, 91, 25));
        pcTable = new QTableWidget(pcDeviceWidget);
        if (pcTable->columnCount() < 2)
            pcTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        pcTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        pcTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (pcTable->rowCount() < 7)
            pcTable->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFlags(Qt::NoItemFlags);
        pcTable->setItem(0, 0, __qtablewidgetitem2);
        pcTable->setObjectName(QString::fromUtf8("pcTable"));
        pcTable->setGeometry(QRect(300, 40, 191, 233));
        pcTable->setMinimumSize(QSize(191, 233));
        pcTable->setMaximumSize(QSize(191, 233));
        pcTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pcTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pcTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pcTable->setAlternatingRowColors(true);
        pcTable->setGridStyle(Qt::SolidLine);
        pcTable->setRowCount(7);
        pcTable->horizontalHeader()->setVisible(true);
        pcTable->horizontalHeader()->setDefaultSectionSize(95);
        pcTable->verticalHeader()->setVisible(false);
        baselineGraph = new QCustomPlot(pcDeviceWidget);
        baselineGraph->setObjectName(QString::fromUtf8("baselineGraph"));
        baselineGraph->setGeometry(QRect(0, 270, 491, 251));
        pcGraphTitle = new QLabel(pcDeviceWidget);
        pcGraphTitle->setObjectName(QString::fromUtf8("pcGraphTitle"));
        pcGraphTitle->setGeometry(QRect(70, 260, 126, 17));
        label_3 = new QLabel(pcDeviceWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 20, 151, 17));
        EEGGraph = new QCustomPlot(environmentManagerFrame);
        EEGGraph->setObjectName(QString::fromUtf8("EEGGraph"));
        EEGGraph->setGeometry(QRect(520, 40, 401, 261));
        establishConnection = new QPushButton(environmentManagerFrame);
        establishConnection->setObjectName(QString::fromUtf8("establishConnection"));
        establishConnection->setGeometry(QRect(720, 400, 201, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        upArrowButton->setText(QCoreApplication::translate("MainWindow", "Up ", nullptr));
        downArrowButton->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        timeElapsed->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        powerButton->setText(QCoreApplication::translate("MainWindow", "Power", nullptr));

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
        label_4->setText(QCoreApplication::translate("MainWindow", "Time and Date:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Enter today's date", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Session Complete!", nullptr));
        contactLostLight->setText(QString());
        treatmentLight->setText(QString());
        contactLight->setText(QString());
        pcDeviceLabel->setText(QCoreApplication::translate("MainWindow", "PC Device", nullptr));
        EEGLabel->setText(QCoreApplication::translate("MainWindow", "EEG Readings", nullptr));
        ECLabel->setText(QCoreApplication::translate("MainWindow", "Environment Controls", nullptr));
        batteryUseButton->setText(QCoreApplication::translate("MainWindow", "Use Battery", nullptr));
        batteryFullButton->setText(QCoreApplication::translate("MainWindow", "Battery Full", nullptr));
        terminateConnection->setText(QCoreApplication::translate("MainWindow", "Terminate Connection", nullptr));
        pcDate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Date:</span></p></body></html>", nullptr));
        pcDateValue->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        pcElapsedTime->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Time Elapsed:</span></p></body></html>", nullptr));
        pcElapsedValue->setText(QCoreApplication::translate("MainWindow", "N/A", nullptr));
        pcSessionTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Session History View</span></p></body></html>", nullptr));
        pcNoDataTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Currently no session history</span></p><p align=\"center\"><span style=\" font-size:16pt;\">available</span></p></body></html>", nullptr));
        pcEEGTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Therapy Data</span></p></body></html>", nullptr));
        pcBeforeLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Before Baseline:</span></p></body></html>", nullptr));
        pcAfterLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">After Baseline:</span></p></body></html>", nullptr));
        pcBeforeValue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>N/A</p></body></html>", nullptr));
        pcAfterValue->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>N/A</p></body></html>", nullptr));
        pcClearData->setText(QCoreApplication::translate("MainWindow", "Clear History", nullptr));
        QTableWidgetItem *___qtablewidgetitem = pcTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Before", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = pcTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "After", nullptr));

        const bool __sortingEnabled1 = pcTable->isSortingEnabled();
        pcTable->setSortingEnabled(false);
        pcTable->setSortingEnabled(__sortingEnabled1);

        pcGraphTitle->setText(QCoreApplication::translate("MainWindow", "Baseline Waveform", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Dominant Frequencies", nullptr));
        establishConnection->setText(QCoreApplication::translate("MainWindow", "Establish Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
