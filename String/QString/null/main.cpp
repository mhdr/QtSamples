#include <QCoreApplication>
#include <QString>
#include <QTextStream>

void CheckString(QString txt);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name;

    CheckString(name);

    name="";

    CheckString(name);

    name="Mahmood";

    CheckString(name);

    return a.exec();
}

void CheckString(QString txt)
{
    if (txt.isNull())
    {
        QTextStream(stdout) << "null" << endl;
    }
    else if (txt.isEmpty())
    {
        QTextStream(stdout) << "empty" << endl;
    }
    else
    {
        QTextStream(stdout) << txt << endl;
    }
}
