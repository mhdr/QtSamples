#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    QFile file("read.txt");

    if (file.exists())
    {
        out << "Exists" << endl;
    }
    else
    {
        out << "Does not exist" << endl;
    }

    return a.exec();
}
