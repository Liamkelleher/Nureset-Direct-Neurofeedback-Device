#ifndef EEGHEADSET_H
#define EEGHEADSET_H

#include "eegnode.h"
#include "defs.h"
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>

class EEGHeadset : public QObject
{
    Q_OBJECT
public:
    EEGHeadset();
    ~EEGHeadset();

    void captureAllWaves();
    EEGNode& operator[](int index);
    QVector<EEGNode *> getNodes();
    void clearNodes();

public slots:
    void getInitialBaseline();

signals:
    void startAnalysis();

private:
    QVector<EEGNode *> nodes;
};

#endif // EEGHEADSET_H
