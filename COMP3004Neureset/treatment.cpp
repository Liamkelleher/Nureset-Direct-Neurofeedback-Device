#include "treatment.h"

Treatment::Treatment()
{
    treatCancelled = false;
}

void Treatment::treatNodes()
{
    if(!treatCancelled)
    {
        QThread::msleep(3000);
        emit nodeTreated();
    }
}

void Treatment::cancelTreatment()
{
    treatCancelled = true;
}
