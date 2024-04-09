#ifndef PCDEVICE_H
#define PCDEVICE_H

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include "Session.h"

class PCDevice : public QObject
{
    Q_OBJECT

public:
    PCDevice(QWidget *parentWidget);

    void toggleComponents(bool);
    void inputDataIntoTable(const QVector<float>&, const QVector<float>&);
    void inputDataIntoLabels(const QString&, const QString&, const QString&);
    void fillTableColumn(int, const QVector<float>&);
    void uploadToPC(Session *);

private:
    QWidget* m_parentWidget;
    QLabel* m_pcNoDataLabel;
    QLabel* m_pcDateValue;
    QLabel* m_pcElapsedValue;
    QTableWidget* m_pcEEGTable;

    void initializeComponents();
    QMap<QString, QString> parseDataToString(Session *);
};

#endif // PCDEVICE_H
