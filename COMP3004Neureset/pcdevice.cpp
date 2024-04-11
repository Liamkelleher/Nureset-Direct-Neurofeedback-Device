#include "pcdevice.h"

PCDevice::PCDevice(QWidget *parentWidget) : m_parentWidget(parentWidget)
{
    initializeComponents();
}

void PCDevice::initializeComponents()
{
    // Find and initialize UI components
    m_pcNoDataLabel = m_parentWidget->findChild<QLabel*>("pcNoDataTitle");
    m_pcDateValue = m_parentWidget->findChild<QLabel*>("pcDateValue");
    m_pcElapsedValue = m_parentWidget->findChild<QLabel*>("pcElapsedValue");
    m_pcBeforeValue = m_parentWidget->findChild<QLabel*>("pcBeforeValue");
    m_pcAfterValue = m_parentWidget->findChild<QLabel*>("pcAfterValue");
}

void PCDevice::toggleComponents(bool isVisible)
{
    // Hide all children of the parent widget except the noDataLabel
    QList<QWidget*> children = m_parentWidget->findChildren<QWidget*>();
    for (QWidget* child : children) {
        if (child != m_pcNoDataLabel)
            child->setVisible(isVisible);
    }
    m_pcNoDataLabel->setVisible(!isVisible);
}

void PCDevice::inputDataIntoLabels(const QString& dateValue, const QString& timeValue, const QString& elapsedValue, const QString& beforeValue, const QString& afterValue)
{
    QFont font = m_pcBeforeValue->font();
    font.setPointSize(24);
    m_pcDateValue->setText(dateValue + " at " + timeValue);
    m_pcElapsedValue->setText(elapsedValue);
    m_pcBeforeValue->setText(beforeValue + " Hz");
    m_pcBeforeValue->setFont(font);
    m_pcAfterValue->setText(afterValue + " Hz");
    m_pcAfterValue->setFont(font);
}

void PCDevice::uploadToPC(Session* session)
{
    if (!session)
        return;

    QMap<QString, QString> parsedData = parseDataToString(session);
    inputDataIntoLabels(parsedData["Date"], parsedData["Time"], parsedData["Elapsed"], QString::number(session->getBeforeBaseline()), QString::number(session->getAfterBaseline()));

    toggleComponents(true);
}

QMap<QString, QString> PCDevice::parseDataToString(Session * session)
{
    QMap<QString, QString> dataMap;
    dataMap["Date"] = session->getDateTime().date().toString();
    dataMap["Time"] = session->getDateTime().time().toString();
    dataMap["Elapsed"] = session->getTimeElapsed().toString();
    return dataMap;
}
