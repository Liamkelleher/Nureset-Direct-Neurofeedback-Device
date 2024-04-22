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

/*
 *
 * Discription:
 * This starts a session and initializes elapsed time to 0
 *
*/
void Session::startSession()
{
    elapsedTime = QTime(0,0);
}

/*
 *
 * Discription:
 * This updates elapesd time to given value
 *
 * Given:
 * Qtime - time that has elapsed
 *
 * Returns:
 * None
 *
*/
void Session::endSession(QTime elapsed)
{
    this->elapsedTime = elapsed;
}

/*
 *
 * Discription:
 * This sets pre-treatement baseline
 *
 * Given:
 * double - baseline
 *
 * Returns:
 * None
 *
*/
void Session::updateBeforeBaseline(double value)
{
    beforeBaseline = value;
}

/*
 *
 * Discription:
 * This sets post-treatement baseline
 *
 * Given:
 * double - baseline
 *
 * Returns:
 * None
 *
*/
void Session::updateAfterBaseline(double value)
{
    afterBaseline = value;
}

/*
 *
 * Discription:
 * This sets/saves treatement Dominant Frequency
 *
 * Given:
 * bool - true if pre-treatment false if post-treatment
 * QVector<double> - dominant requency to save
 *
 * Returns:
 * None
 *
*/
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

/*
 *
 * Discription:
 * Returns elapesed time
 *
 * Given:
 * None
 *
 * Returns:
 * Qtime - Elapsed Time
 *
*/
QTime Session::getTimeElapsed()
{
    return elapsedTime;
}

/*
 *
 * Discription:
 * Updates elapesed time
 *
 * Given:
 * Qtime - Elapsed Time
 *
 * Returns:
 * None
 *
*/
void Session::setTimeElapsed(QTime newTime)
{
    this->elapsedTime = newTime;
}

/*
 *
 * Discription:
 * returns pre-treatment baseline
 *
 * Given:
 * None
 *
 * Returns:
 * double - pre-treatment baseline
 *
*/
double Session::getBeforeBaseline()
{
    return beforeBaseline;
}

/*
 *
 * Discription:
 * returns post-treatment baseline
 *
 * Given:
 * None
 *
 * Returns:
 * double - post-treatment baseline
 *
*/
double Session::getAfterBaseline()
{
    return afterBaseline;
}

/*
 *
 * Discription:
 * returns pre-treatment dominant frequency for all EEG nodes
 *
 * Given:
 * None
 *
 * Returns:
 * QVector<double> - an array of pre-treatment dominant frequency for all EEG nodes
 *
*/
QVector<double> Session::getBeforeDFs()
{
    return beforeDFs;
}
/*
 *
 * Discription:
 * returns post-treatment dominant frequency for all EEG nodes
 *
 * Given:
 * None
 *
 * Returns:
 * QVector<double> - an array of post-treatment dominant frequency for all EEG nodes
 *
*/
QVector<double> Session::getAfterDFs()
{
    return afterDFs;
}
/*
 *
 * Discription:
 * sets the avrage amplitude
 *
 * Given:
 * double - the amlpitued to save
 *
 * Returns:
 * None
 *
*/
void Session::updateAvgAmp(double amp)
{
    avgAmplitude = amp;
}

/*
 *
 * Discription:
 * returns amplitude of this session
 *
 * Given:
 * None
 *
 * Returns:
 * double - the avrage amplitude of the session
 *
*/
double Session::getAvgAmpl()
{
    return avgAmplitude;
}

/*
 *
 * Discription:
 * returns date and time that the session started
 *
 * Given:
 * None
 *
 * Returns:
 * QDateTime - of the session
 *
*/
QDateTime Session::getDateTime()
{
    return dateTime;
}

/*
 *
 * Discription:
 * returns a string of the start date and time of the session
 *
 * Given:
 * None
 *
 * Returns:
 * QString - string info of the start date and time
 *
*/
QString Session::toString() const
{
    return "Date: " + dateTime.toString("dd.MM.yyyy hh:mm:ss");
}

/*
 *
 * Discription:
 * formats and returns session info for the session logger to write it to a file
 *
 * Given:
 * QDataStream - empty datastream that recives the data
 * Session - the session that returns the data
 *
 * Returns:
 * QDataStream - the data that will be sent to the logger
 *
*/
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

/*
 *
 * Discription:
 * Creates sessions from the inputed info for the session logger as it reads in a file.
 *
 * Given:
 * QDataStream - datastream that has data
 * Session - the session that needs populating the data
 *
 * Returns:
 * QDataStream - the inputed data.
 *
*/
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
