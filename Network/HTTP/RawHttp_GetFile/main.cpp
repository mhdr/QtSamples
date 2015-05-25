#include <QCoreApplication>
#include <QStringList>
#include "httpclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList *request=new QStringList();
    request->append("GET /index.html HTTP/1.1");
    request->append("Host: localhost");
    request->append("Connection: Close");
    request->append("");
    request->append("");

    QString data=request->join("\r\n");

    HttpClient *client=new HttpClient();
    client->writeData(data);

    return a.exec();
}
