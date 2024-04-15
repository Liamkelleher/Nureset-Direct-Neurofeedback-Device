#include "Session.h"

Session::Session(QDateTime dateTime) : dateTime(dateTime), beforeBaseline(0.0), afterBaseline(0.0)
{
    beforeDFs.resize(NUM_NODES);
    afterDFs.resize(NUM_NODES);
}

Session::Session(Session& sessionCopy)
{
    this->dateTime = sessionCopy.dateTime;
    this->beforeBaseline = sessionCopy.beforeBaseline;
    this->afterBaseline = sessionCopy.afterBaseline;
    this->elapsedTime = sessionCopy.elapsedTime;
    this->beforeDFs = sessionCopy.beforeDFs;
    this->afterDFs = sessionCopy.afterDFs;
    this->avgAmplitude = sessionCopy.avgAmplitude;
}

Session::Session() : dateTime(QDateTime()), beforeBaseline(0.0), afterBaseline(0.0), elapsedTime(QTime()) {}

Session::~Session() {}

void Session::startSession()
{
    elapsedTime = QTime(0,0);
}

void Session::endSession(QTime elapsed)
{
    this->elapsedTime = elapsed;
}

void Session::updateBeforeBaseline(double value)
{
    beforeBaseline = value;
}

void Session::updateAfterBaseline(double value)
{
    afterBaseline = value;
}

void Session::addToDF(bool isBefore, QVector<double> domFreq)
{
    if (isBefore)
    {
        beforeDFs = domFreq;
    }
    else
    {
        afterDFs = domFreq;
    }
}

QTime Session::getTimeElapsed()
{
    return elapsedTime;
}

void Session::setTimeElapsed(QTime newTime)
{
    this->elapsedTime = newTime;
}

double Session::getBeforeBaseline()
{
    return beforeBaseline;
}

double Session::getAfterBaseline()
{
    return afterBaseline;
}

QVector<double> Session::getBeforeDFs()
{
    return beforeDFs;
}

QVector<double> Session::getAfterDFs()
{
    return afterDFs;
}

void Session::updateAvgAmp(double amp)
{
    avgAmplitude = amp;
}

double Session::getAvgAmpl()
{
    return avgAmplitude;
}

QDateTime Session::getDateTime()
{
    return dateTime;
}

QString Session::toString() const
{
    return "Date: " + dateTime.toString("dd.MM.yyyy hh:mm:ss");
}

QDataStream &operator<<(QDataStream &out, const Session &session) {
    out << session.dateTime;
    out << QString::number(session.beforeBaseline);
    out << QString::number(session.afterBaseline);
    out << session.elapsedTime.toString("mm:ss");
    out << session.beforeDFs;
    out << session.afterDFs;
    out << session.avgAmplitude;
    return out;
}

QDataStream &operator>>(QDataStream &in, Session &session) {
    QString beforeBaselineStr, afterBaselineStr, timeString;
    QVector<double> before;
    QVector<double> after;

    in >> session.dateTime;
    in >> beforeBaselineStr;
    in >> afterBaselineStr;
    in >> timeString;
    in >> before;
    in >> after;
    in >> session.avgAmplitude;

    session.beforeBaseline = beforeBaselineStr.toDouble();
    session.afterBaseline = afterBaselineStr.toDouble();
    session.elapsedTime = QTime::fromString(timeString, "mm:ss");
    session.addToDF(true, before);
    session.addToDF(false, after);

    return in;
}
