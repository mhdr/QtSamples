#include <QCoreApplication>
#include <worker.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker *worker1=new Worker();
    worker1->setWaitTime(5);
    worker1->setThreadName("Thread1");
    worker1->start();

    Worker *worker2=new Worker();
    worker2->setWaitTime(3);
    worker2->setThreadName("Thread2");
    worker2->start();

    Worker *worker3=new Worker();
    worker3->setWaitTime(6);
    worker3->setThreadName("Thread3");
    worker3->start();

    return a.exec();
}
