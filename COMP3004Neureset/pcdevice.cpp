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
    m_pcgraph = m_parentWidget->findChild<QCustomPlot*>("baselineGraph");
    m_DFTable = m_parentWidget->findChild<QTableWidget*>("pcTable");
    m_DFTable->setRowCount(NUM_NODES);
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

void PCDevice::inputDataIntoLabels(QMap<QString, QString> parsedData)
{
    m_pcDateValue->setText(parsedData["Date"] + " at " + parsedData["Time"]);
    m_pcElapsedValue->setText(parsedData["Elapsed"]);
    m_pcBeforeValue->setText(parsedData["Before"] + " Hz");
    m_pcAfterValue->setText(parsedData["After"] + " Hz");
}

void PCDevice::uploadToPC(Session* session)
{
    if (!session)
        return;

    QMap<QString, QString> parsedData = parseDataToString(session);
    inputDataIntoLabels(parsedData);
    inputDataIntoTable(session->getBeforeDFs(), session->getAfterDFs());
    updateGraph(session);
    toggleComponents(true);
}

QMap<QString, QString> PCDevice::parseDataToString(Session * session)
{
    QMap<QString, QString> dataMap;
    dataMap["Date"] = session->getDateTime().date().toString();
    dataMap["Time"] = session->getDateTime().time().toString("hh:mm");
    dataMap["Elapsed"] = session->getTimeElapsed().toString();
    dataMap["Before"] = QString::number(session->getBeforeBaseline());
    dataMap["After"] = QString::number(session->getAfterBaseline());
    return dataMap;
}

void PCDevice::inputDataIntoTable(QVector<double> beforeDFs, QVector<double> afterDFs)
{
    m_DFTable->clearContents();
    fillTableColumn(0, beforeDFs);
    fillTableColumn(1, afterDFs);
}

void PCDevice::fillTableColumn(int column, QVector<double> domFreq)
{
    int numRows = domFreq.size();
    m_DFTable->setRowCount(numRows);
    for (int row = 0; row < numRows; ++row) {
        m_DFTable->setItem(row, column, new QTableWidgetItem(QString::number(domFreq[row])));
    }
}

void PCDevice::updateGraph(Session *session)
{
    QVector<double> values;
    for (int i = 0; i < GRAPH_STEPS; ++i) {
        double x = i * STEP;
        double waveValue = session->getAvgAmpl() * std::sin(2 * session->getAfterBaseline() * M_PI * x);
        values.push_back(waveValue);
    }

    QVector<double> x(GRAPH_STEPS);
    for (int i = 0; i < GRAPH_STEPS; ++i)
    {
        x[i] = STEP * i;
    }
    if (!values.isEmpty())
    {
        m_pcgraph->graph()->setData(x, values);
        m_pcgraph->replot();
    }
}

void PCDevice::clear()
{
    m_pcDateValue->setText("N/A");
    m_pcElapsedValue->setText("00:00");
    m_pcBeforeValue->setText("0 Hz");
    m_pcAfterValue->setText("0 Hz");

    toggleComponents(false);
}
