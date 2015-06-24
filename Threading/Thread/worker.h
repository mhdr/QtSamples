#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QThread
{
    Q_OBJECT
    void run();

public:
    Worker();
    int waitTime() const;
    void setWaitTime(int waitTime);

    QString threadName() const;
    void setThreadName(const QString &threadName);

private:
    int m_waitTime;
    QString m_threadName;
};

#endif // WORKER_H
