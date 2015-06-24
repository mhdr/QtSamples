#include "worker.h"
#include <QDebug>

void Worker::run()
{
    qDebug() << QString("Start %1").arg(this->threadName()) << endl;
    this->sleep(this->waitTime());
    qDebug() << QString("End %1").arg(this->threadName()) << endl;
}

Worker::Worker()
{

}
int Worker::waitTime() const
{
    return m_waitTime;
}

void Worker::setWaitTime(int waitTime)
{
    m_waitTime = waitTime;
}
QString Worker::threadName() const
{
    return m_threadName;
}

void Worker::setThreadName(const QString &threadName)
{
    m_threadName = threadName;
}



