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
    client->waitForConnected();

    QString data="Hello World";
    QByteArray dataB=data.toUtf8();

    client->write(dataB,1024);
    client->waitForBytesWritten();

    client->waitForReadyRead();
    QByteArray echoDataB=client->read(1024);

    QString echoData=QString::fromUtf8(echoDataB);

    QString msg=QString("Echo : %1").arg(echoData);
    QTextStream(stdout) << msg << endl;

    client->close();

    return a.exec();
}
