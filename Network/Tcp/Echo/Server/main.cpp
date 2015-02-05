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

    QTcpServer *server=new QTcpServer();
    server->listen(QHostAddress::Any,9001);

    while (true) {

        QTextStream(stdout) << "Waiting for new connection ..." << endl;
        server->waitForNewConnection(-1);

        QTcpSocket *client=server->nextPendingConnection();

        int port=client->peerPort();
        QHostAddress address=client->peerAddress();

        QString portStr=QString::number(port);
        QString addressStr= address.toString().trimmed();

        QString msg=QString("Connection from %1:%2").arg(addressStr,portStr);

        QTextStream(stdout) << msg << endl;

        client->waitForReadyRead();
        QByteArray dataB= client->read(1024);

        QString data=QString::fromUtf8(dataB);

        QTextStream(stdout) << data << endl;

        client->write(dataB,1024);
        client->waitForBytesWritten();

        client->close();
    }

    return a.exec();
}
