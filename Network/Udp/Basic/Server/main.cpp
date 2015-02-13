#include <QCoreApplication>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto *sock=new QUdpSocket();
    sock->bind(QHostAddress::Any,9001);

    while (true)
    {
        if (sock->hasPendingDatagrams())
        {
            QByteArray dataB;
            dataB.resize(sock->pendingDatagramSize());
            QHostAddress address;
            quint16 port;

            sock->readDatagram(dataB.data(),dataB.size(),&address,&port);
            QString data=QString::fromUtf8(dataB);

            QTextStream(stdout) << data << endl;
        }

    }

    return a.exec();
}
