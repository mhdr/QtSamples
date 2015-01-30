#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTextStream>
#include <QByteArray>

void writeJSON();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    writeJSON();

    QTextStream log(stdout);

    QFile *file=new QFile("data.json");
    file->open(QIODevice::ReadOnly);
    QByteArray jsonStr= file->readAll();
    file->close();

    QJsonDocument jsonDoc=QJsonDocument::fromJson(jsonStr);

    QJsonObject jsonObj= jsonDoc.object();

    log << jsonObj.value("FirstName").toString() << endl;
    log << jsonObj.value("LastName").toString() << endl;
    log << jsonObj.value("Age").toInt() << endl;

    return a.exec();
}

void writeJSON()
{
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
}
