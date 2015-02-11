#include <QCoreApplication>
#include <QLocalServer>
#include <QLocalSocket>
#include <QByteArray>
#include <QString>
#include <QTextStream>

QLocalServer *server;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *obj=new QObject();

    server=new QLocalServer(obj);

    if (server->listen("LocalSocket") )
    {
        QTextStream(stdout) << "waiting for new connection ..." << endl;
    }
    else
    {
        a.quit();
        return -1;
    }

    while (true)
    {
        server->waitForNewConnection(-1);

        QTextStream(stdout) << "new connection" << endl;
        QLocalSocket *client=server->nextPendingConnection();
        QTextStream(stdout) << "new client" << endl;

        client->waitForReadyRead();

        QTextStream(stdout) << "start reading data" << endl;
        QByteArray dataB=client->readAll();
        QTextStream(stdout) << "end of reading data" << endl;

        QString data=QString::fromUtf8(dataB);

        QTextStream(stdout) << data << endl;

        client->close();
    }

    return a.exec();
}
