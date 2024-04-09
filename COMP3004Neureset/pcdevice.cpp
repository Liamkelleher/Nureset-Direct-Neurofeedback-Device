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
    m_pcEEGTable = m_parentWidget->findChild<QTableWidget*>("pcEEGTable");
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

void PCDevice::inputDataIntoTable(const QVector<float>& beforeBaselines, const QVector<float>& afterBaselines)
{
    m_pcEEGTable->clearContents();
    fillTableColumn(0, beforeBaselines);
    fillTableColumn(1, afterBaselines);
}

void PCDevice::fillTableColumn(int column, const QVector<float> & baseline)
{
    int numRowsBefore = baseline.size();
    m_pcEEGTable->setRowCount(numRowsBefore);
    for (int row = 0; row < numRowsBefore; ++row) {
        m_pcEEGTable->setItem(row, column, new QTableWidgetItem(QString::number(baseline[row])));
    }
}

void PCDevice::inputDataIntoLabels(const QString& dateValue, const QString& timeValue, const QString& elapsedValue)
{
    m_pcDateValue->setText(dateValue + " at " + timeValue);
    m_pcElapsedValue->setText(elapsedValue);
}

void PCDevice::uploadToPC(Session* session)
{
    if (!session)
        return;

    QMap<QString, QString> parsedData = parseDataToString(session);
    // Update labels with session data
    inputDataIntoLabels(parsedData["Date"],parsedData["Time"], parsedData["Elapsed"]);

    // Upload before and after baselines to table
    inputDataIntoTable(session->getBeforeBaselines(), session->getAfterBaselines());

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
