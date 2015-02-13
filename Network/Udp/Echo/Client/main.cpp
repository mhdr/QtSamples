#include <QCoreApplication>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data="Hello World";
    QByteArray dataB=data.toUtf8();

    QHostAddress *address=new QHostAddress("127.0.0.1");
    quint16 port=9001;

    QUdpSocket *sock=new QUdpSocket();
    sock->writeDatagram(dataB,*address,port);
    sock->waitForBytesWritten();

    QByteArray rdataB;
    rdataB.resize(sock->pendingDatagramSize());

    QTextStream(stdout) << QString::number(rdataB.size());

    sock->readDatagram(rdataB.data(),rdataB.size());

    QString rdata=QString::fromUtf8(rdataB);

    QTextStream(stdout) << rdata << endl;

    sock->close();

    return a.exec();
}
