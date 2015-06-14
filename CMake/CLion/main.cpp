#include <QtCore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString msg="Hello World";

    QTextStream out(stdout);

    out << msg << endl;

    return 0;
}