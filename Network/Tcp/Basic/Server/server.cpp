#include "server.h"
#include <QTcpServer>
#include <QHostAddress>
#include <QByteArray>
#include <QTcpSocket>
#include <QTextStream>
#include <QString>

QTcpServer *server;

Server::Server(QObject *parent) :
    QObject(parent)
{
    server=new QTcpServer();
    connect(server,&QTcpServer::newConnection,this,&Server::newConnectionStarted);
}

void Server::startServer()
{
    QTextStream(stdout) << "Waiting for connection ..." << endl;
    server->listen(QHostAddress::Any,9001);
}

void Server::newConnectionStarted()
{
    QTcpSocket *client=server->nextPendingConnection();

    int port=client->peerPort();
    QHostAddress address=client->peerAddress();

    QString portStr=QString::number(port);
    QString addressStr= address.toString().trimmed();

    QString msg=QString("Connection from %1:%2").arg(addressStr,portStr);

    QTextStream(stdout) << msg << endl;

    QByteArray dataB= client->read(1024);

    QString data=QString::fromUtf8(dataB);

    QTextStream(stdout) << data << endl;

    client->close();
}
