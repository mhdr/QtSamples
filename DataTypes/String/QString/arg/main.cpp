#include <QCoreApplication>
#include <QString>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int index=10;

    QString result=QString("index : %1 ,name : %2 ").arg(QString::number(index),"Mahmood");
    QTextStream(stdout) << result << endl;

    return a.exec();
}
