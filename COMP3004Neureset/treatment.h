#ifndef TREATMENT_H
#define TREATMENT_H

#include <QObject>
#include <QThread>

class Treatment: public QObject
{
    Q_OBJECT

public:
    Treatment();

    void cancelTreatment();

public slots:
    void treatNodes();

signals:
    void nodeTreated();

private:
    bool treatCancelled;

};

#endif // TREATMENT_H
