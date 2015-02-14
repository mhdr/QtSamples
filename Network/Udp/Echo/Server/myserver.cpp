#include "myserver.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QTextStream>
#include <QString>

QUdpSocket *sock;

MyServer::MyServer(QObject *parent) : QObject(parent)
{
    sock=new QUdpSocket();
    connect(sock,&QUdpSocket::readyRead,this,&MyServer::readData);
}

MyServer::~MyServer()
{

}

void MyServer::startServer()
{
    sock->bind(QHostAddress::Any,9001);
}

void MyServer::readData()
{
    while (sock->hasPendingDatagrams()) {
        QByteArray dataB;
        dataB.resize(sock->pendingDatagramSize());
        QHostAddress address;
        quint16 port;

        sock->readDatagram(dataB.data(),dataB.size(),&address,&port);
        QString data=QString::fromUtf8(dataB);

        QTextStream(stdout) << data << endl;
        QTextStream(stdout) << QString::number(port) << endl;
        QTextStream(stdout) << address.toString() << endl;

        sock->writeDatagram(dataB,address,port);
    }
}
