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

    void captureWaves();
    EEGNode& operator[](int index);

public slots:
    void getBaseLine();
    void getTreatedBaseLine();

signals:
    void returnBaseLine();
    void returnTreatedBaseLine();


private:
    QVector<EEGNode *> nodes;
};

#endif // EEGHEADSET_H
