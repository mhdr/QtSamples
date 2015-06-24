#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::doWork()
{
    QThread::sleep(5);
    qDebug() << "do Work" << endl;
}

void Worker::doWorkAsync()
{
    this->moveToThread(&thread);
    connect(&thread,&QThread::started,this,&Worker::doWork);
    thread.start();
}

