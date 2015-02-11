#include <QCoreApplication>
#include <QLocalSocket>
#include <QByteArray>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *obj=new QObject();

    QLocalSocket *sock=new QLocalSocket(obj);
    sock->connectToServer("LocalSocket");

    QString data=QString("Hello World");
    QByteArray dataB=data.toUtf8();

    sock->write(dataB);
    sock->waitForBytesWritten();
    sock->close();

    return a.exec();
}
