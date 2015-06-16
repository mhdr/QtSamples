#include "qstringtests.h"
#include <QtTest/QtTest>

QStringTests::QStringTests(QObject *parent) :
    QObject(parent)
{
}

void QStringTests::toUpper()
{
    QString str="Hello";

    QCOMPARE(str.toUpper(),QString("HELLO"));
}

void QStringTests::toUpper2()
{
    QString str="Hello";

    QCOMPARE(str.toUpper(),QString("HELLO"));
}
