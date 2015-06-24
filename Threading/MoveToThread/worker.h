#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT

    QThread thread;
public:
    explicit Worker(QObject *parent = 0);

    void doWork();
    void doWorkAsync();

signals:

public slots:
};

#endif // WORKER_H
