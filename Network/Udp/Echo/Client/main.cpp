#include <QCoreApplication>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QTextStream>
#include <QString>
#include "myclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClient *myClient=new MyClient();
    myClient->sendData("Hello World");

    return a.exec();
}
