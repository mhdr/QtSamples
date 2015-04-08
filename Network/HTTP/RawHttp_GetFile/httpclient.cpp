#include "httpclient.h"

QTcpSocket *socket;
int count=0;

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    socket=new QTcpSocket();
    socket->connectToHost("localhost",80);
    connect(socket,&QTcpSocket::readyRead,this,&HttpClient::readData);
}

HttpClient::~HttpClient()
{

}

void HttpClient::readData()
{
    QByteArray dataB= socket->readAll();
    QString data=QString(dataB);

    count++;
    qDebug() << count << endl;

    QTextStream out(stdout);
    out << data;
}

void HttpClient::writeData(QString data)
{
    QByteArray dataB=data.toUtf8();
    socket->write(dataB);
}
