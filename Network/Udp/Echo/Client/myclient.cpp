#include "myclient.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QTextStream>
#include <QString>

QUdpSocket *sock;

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    sock=new QUdpSocket();
    connect(sock,&QUdpSocket::readyRead,this,&MyClient::readData);
}

MyClient::~MyClient()
{

}

void MyClient::sendData(QString data)
{
    QByteArray dataB=data.toUtf8();

    QHostAddress *address=new QHostAddress("127.0.0.1");
    quint16 port=9001;

    sock->writeDatagram(dataB,*address,port);
}


void MyClient::readData()
{
    while (sock->hasPendingDatagrams())
    {
        QByteArray rdataB;
        rdataB.resize(sock->pendingDatagramSize());

        sock->readDatagram(rdataB.data(),rdataB.size());

        QString rdata=QString::fromUtf8(rdataB);

        QTextStream(stdout) << rdata << endl;
    }

    sock->close();
}
