#include <QCoreApplication>
#include <worker.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker *worker=new Worker();
    worker->doWorkAsync();

    qDebug() << "Hello Thread" << endl;

    return a.exec();
}
