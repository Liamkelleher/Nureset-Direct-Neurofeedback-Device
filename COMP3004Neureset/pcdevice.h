#ifndef PCDEVICE_H
#define PCDEVICE_H

#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QFont>
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

    void initializeComponents();
    void inputDataIntoLabels(const QString&, const QString&, const QString&, const QString&, const QString&);
    QMap<QString, QString> parseDataToString(Session *);
};

#endif // PCDEVICE_H
