#include <QCoreApplication>
#include "httpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data="GET /hello.txt HTTP/1.1\r\nHost: localhost\r\nConnection: Close\r\n\r\n";

    HttpClient *client=new HttpClient();
    client->writeData(data);

    return a.exec();
}
