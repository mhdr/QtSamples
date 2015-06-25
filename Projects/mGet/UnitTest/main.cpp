#include <QCoreApplication>
#include <QtTest/QtTest>
#include <httpclienttests.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HttpClientTests httpClientTests;
    QTest::qExec(&httpClientTests,argc,argv);

    return 0;
}
