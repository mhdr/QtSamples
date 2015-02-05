#include <QCoreApplication>
#include <QTcpServer>
#include <QHostAddress>
#include <QByteArray>
#include <QTcpSocket>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket *client=new QTcpSocket();
    client->connectToHost("127.0.0.1",9001);

    QString data="Hello World";
    QByteArray dataB=data.toUtf8();

    client->write(dataB,1024);
    client->close();

    return a.exec();
}
