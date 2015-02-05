#include <QCoreApplication>
#include <QString>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream inStream(stdin);
    QTextStream outStream(stdout);

    outStream << "Enter your name : " << endl;

    QString name=inStream.readLine();

    outStream << "Your name is " << name << endl;

    return a.exec();
}
