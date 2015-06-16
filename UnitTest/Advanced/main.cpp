#include <QCoreApplication>
#include <QtTest/QtTest>
#include <qstringtests.h>
#include <qstringtests2.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringTests test1;
    QStringTests2 test2;

    QTest::qExec(&test1,argc,argv);
    QTest::qExec(&test2,argc,argv);

    return a.exec();
}
