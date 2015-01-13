#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream(stdout) << "Hello World!!!" << endl;

    return a.exec();
}
