#include "display.h"

Display::Display(QStackedWidget* stackedWidget)
    : stackedWidget(stackedWidget)
{
    // init
    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 0));
    stackedWidget->hide();

    dynamic_cast<QDateTimeEdit*>(stackedWidget->widget(3)->findChild<QDateTimeEdit*>("dateTimeEdit"))->setDateTime(QDateTime::currentDateTime());
}

void Display::upArrowButton()
{
    // check if arrows should be active based on current page
    QListWidget* widget = NULL;

    if (stackedWidget->currentIndex() == 0) // main menu page
    {
        widget = dynamic_cast<QListWidget*>(stackedWidget->currentWidget()->findChild<QListWidget*>("menuList"));
    }
    else if (stackedWidget->currentIndex() == 2) // session logs
    {
        widget = dynamic_cast<QListWidget*>(stackedWidget->widget(2)->findChild<QListWidget*>("sessionList"));
    }

    // move selection
    if (widget && widget->count() > 0)
    {
        int currentRow = widget->currentRow();
        if (currentRow > 0)
        {
            widget->setCurrentRow(currentRow - 1);
        }
    }
}

void Display::downArrowButton()
{
    // check if arrows should be active based on current page
    QListWidget* widget = NULL;

    if (stackedWidget->currentIndex() == 0) // main menu page
    {
        widget = dynamic_cast<QListWidget*>(stackedWidget->currentWidget()->findChild<QListWidget*>("menuList"));
    }
    else if (stackedWidget->currentIndex() == 2) // session logs
    {
        widget = dynamic_cast<QListWidget*>(stackedWidget->widget(2)->findChild<QListWidget*>("sessionList"));
    }

    // move selection
    if (widget && widget->count() > 0)
    {
        int currentRow = widget->currentRow();
        if (currentRow < widget->count() - 1)
        {
            widget->setCurrentRow(currentRow + 1);
        }
    }
}


void Display::startButton()
{
    int currentIndex = stackedWidget->currentIndex();

    // Based on current index of the QStackedWidget
    switch (currentIndex)
    {
        case 0: // Main Menu
        {
            QListWidget* menuList = dynamic_cast<QListWidget*>(stackedWidget->widget(0)->findChild<QListWidget*>("menuList"));

            int selected = menuList->currentRow();

            switch (selected)
            {
                case 0: // "New Session" is selected
                    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 1));
                    break;
                case 1: // "Session Logs" is selected
                    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 2));
                    break;
                case 2: // "Time and Date" is selected
                    dynamic_cast<QDateTimeEdit*>(stackedWidget->widget(3)->findChild<QDateTimeEdit*>("dateTimeEdit"))->setDateTime(QDateTime::currentDateTime());
                    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 3));
                    break;
            }
            break;
        }
        case 2: // Session Logs
        {
            QListWidget* sessionList = dynamic_cast<QListWidget*>(stackedWidget->widget(2)->findChild<QListWidget*>("sessionList"));
            if (!sessionList) {
                return;
            }

            // emit Device, Device emit signals, mainWindow calls pc upload with session
            if (sessionList->currentRow() >= 0)
                emit uploadSession(sessionList->currentRow());

            break;
        }
        case 3: // Time and Date
        {
            QDateTimeEdit* dateTime = dynamic_cast<QDateTimeEdit*>(stackedWidget->widget(3)->findChild<QDateTimeEdit*>("dateTimeEdit"));
            QDateTime newDateTime = dateTime->dateTime();
            emit updateDateTime(newDateTime);
            QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 0)); // Go back to the main menu
            break;
        }
    }
}

void Display::stopButton()
{
    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 0)); // Go back to the main menu
}

void Display::powerOnDisplay()
{
    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 0)); // main menu
    QListWidget* widget = dynamic_cast<QListWidget*>(stackedWidget->currentWidget()->findChild<QListWidget*>("menuList"));
    widget->setCurrentRow(0); // reset index
    QMetaObject::invokeMethod(stackedWidget, "show", Qt::QueuedConnection);
}

void Display::powerOffDisplay()
{
    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 0)); // main menu
    stackedWidget->hide(); // hide to simulate 'shut off'
}

void Display::menuButton()
{
    int currentIndex = stackedWidget->currentIndex();
    if (currentIndex != 0)
    {
        stackedWidget->setCurrentIndex(0);
    }
}

int Display::getCurrentMenuSelect()
{
    if (stackedWidget->currentIndex() == 0)
    {
        QListWidget* menuList = dynamic_cast<QListWidget*>(stackedWidget->widget(0)->findChild<QListWidget*>("menuList"));
        if (menuList)
        {
            return menuList->currentRow();
        }
    }
    return -1;
}

void Display::populateSessionLogs(SessionLog *sessionLogs)
{
    if (!sessionLogs) {
        return;
    }

    // Attempt to retrieve the session list widget
    QListWidget* sessionList = dynamic_cast<QListWidget*>(stackedWidget->widget(2)->findChild<QListWidget*>("sessionList"));
    if (!sessionList) {
        return;
    }

    sessionList->clear();
    // Check the count method and array access are safe
    int logCount = sessionLogs->count();
    if (logCount <= 0) {
        return;
    }

    // Iterate through the session logs and add them to the list
    for (int i = 0; i < logCount; i++) {
        QString logEntry = (*sessionLogs)[i].toString();
        if (logEntry.isEmpty()) {
            continue;
        }
        QListWidgetItem* newItem = new QListWidgetItem(logEntry);
        sessionList->addItem(newItem);
    }
}

void Display::updateTimer(qint64 timeInMSecs)
{
    QLabel* timerLabel = dynamic_cast<QLabel*>(stackedWidget->widget(1)->findChild<QLabel*>("timerLabel"));

    if (timerLabel)
    {
        QTime time = QTime(0,0).addMSecs(static_cast<int>(timeInMSecs));
        QString text = time.toString("mm:ss");
        timerLabel->setText(text);
    }
}

void Display::sessionComplete()
{
    QMetaObject::invokeMethod(stackedWidget, "setCurrentIndex", Qt::QueuedConnection, Q_ARG(int, 4));
}
