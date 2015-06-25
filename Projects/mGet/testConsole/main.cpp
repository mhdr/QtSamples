#include <QCoreApplication>
#include <httpclient.h>
#include <environment.h>
#include <QDir>
#include <QDebug>
#include <queue.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Environment *env=new Environment();
    qDebug() << env->createmGetFolder() << endl;
    qDebug() << env->createmGetDb() << endl;

    Queue *q=new Queue();
    qDebug() << q->addToQueue("http://www.google.com") << endl;

    return 0;
}
