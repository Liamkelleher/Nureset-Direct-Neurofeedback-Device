#ifndef PCDEVICE_H
#define PCDEVICE_H

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QDebug>
#include "qcustomplot.h"
#include "Session.h"

class PCDevice : public QObject
{
    Q_OBJECT

public:
    PCDevice(QWidget *parentWidget);

    void toggleComponents(bool);
    void uploadToPC(Session *);
    void clear();

private:
    QWidget* m_parentWidget;
    QLabel* m_pcNoDataLabel;
    QLabel* m_pcDateValue;
    QLabel* m_pcElapsedValue;
    QLabel* m_pcBeforeValue;
    QLabel* m_pcAfterValue;
    QTableWidget* m_DFTable;
    QCustomPlot* m_pcgraph;

    void initializeComponents();
    void inputDataIntoLabels(QMap<QString, QString>);
    void inputDataIntoTable(QVector<double>, QVector<double>);
    void fillTableColumn(int, QVector<double>);
    void updateGraph(Session *);
    QMap<QString, QString> parseDataToString(Session *);
};

#endif // PCDEVICE_H
