#include "display.h"

Display::Display()
{   

}

void Display::setupDisplay(QListWidget *disLabel, QProgressBar *progLabel, QLabel *timerLabel, QDateTimeEdit *dteLabel)
{
    dis = disLabel;
    progBar = progLabel;
    timerDis = timerLabel;
    dTE = dteLabel;

    progBar->hide();
    timerDis->hide();
    dTE->hide();

    hidden = true;
    sesActive = false;
}

void Display::upArrowButton()
{
    if (dis->count() != 0)
    {
        int curr = dis->currentRow();

        if (curr > 0)
        {
            dis->setCurrentRow(curr - 1);
        }
    }
}


void Display::downArrowButton()
{
    if (dis->count() != 0)
    {
        int curr = dis->currentRow();

        if (curr < (dis->count() - 1))
        {
            dis->setCurrentRow(curr + 1);
        }
    }
}


void Display::startButton()
{
    if (dis->currentItem() == menuList[0])
    {
        dis->clear();

        progBar->show();
        timerDis->show();

        hidden = false;
        sesActive = true;
    }

    if (dis->currentItem() == menuList[1])
    {
        dis->clear();
        //Show session logs

        //Uploading to PC device
    }

    if (dis->currentItem() == menuList[2])
    {
        dis->clear();

        dTE->show();
    }
}


void Display::stopButton()
{
    if (sesActive)
    {
        //stop session protocol

        progBar->hide();
        timerDis->hide();

        hidden = true;
        sesActive = false;

        createMenuList();

        dis->setCurrentItem(menuList[0]);
    }
}


void Display::powerButton(bool deviceOn)
{
    if (deviceOn)
    {
        if (sesActive)
        {
            //stop session protocol

            progBar->hide();
            timerDis->hide();
            dTE->hide();

            hidden = true;
            sesActive = false;
        }

        dis->clear();
    }

    else
    {
        createMenuList();

        dis->setCurrentItem(menuList[0]);
    }
}

void Display::menuButton(bool deviceOn)
{
    if (deviceOn && !sesActive)
    {
        dTE->hide();

        //Slight visual bug involving dis->clear();
        //When a clear call is added prior to setting the current item/row
        //the ui is unable to set the current row/item as selected
        //forcing the user to press the down arrow to select the first item/row
        dis->clear();

        createMenuList();

        dis->setCurrentItem(menuList[0]);
    }
}

void Display::createMenuList()
{
    menuList[0] = new QListWidgetItem("NEW SESSION");
    menuList[1] = new QListWidgetItem("SESSION LOGS");
    menuList[2] = new QListWidgetItem("TIME AND DATE");

    menuList[0]->setTextAlignment(4);
    menuList[1]->setTextAlignment(4);
    menuList[2]->setTextAlignment(4);

    dis->addItem(menuList[0]);
    dis->addItem(menuList[1]);
    dis->addItem(menuList[2]);
}
