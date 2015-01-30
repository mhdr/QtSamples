#include <QCoreApplication>
#include <QJsonObject>
#include <QTextStream>
#include <QJsonDocument>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJsonObject *json=new QJsonObject();
    json->insert("FirstName","Mahmood");
    json->insert("LastName","Ramzani");
    json->insert("Age",29);

    QJsonDocument *jsonDoc=new QJsonDocument(*json);

    QTextStream log(stdout);

    log << jsonDoc->toJson() << endl;

    QFile *file=new QFile("data.json");
    file->open(QIODevice::WriteOnly);

    file->write(jsonDoc->toJson());
    file->flush();
    file->close();

    return a.exec();
}

