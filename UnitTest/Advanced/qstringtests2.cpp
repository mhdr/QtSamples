#include "qstringtests2.h"
#include <QtTest/QtTest>


QStringTests2::QStringTests2(QObject *parent) :
    QObject(parent)
{
}

void QStringTests2::toUpper()
{
    QString str="Hello";

    QCOMPARE(str.toUpper(),QString("HELLO"));
}

void QStringTests2::toUpper2()
{
    QString str="Hello";

    QCOMPARE(str.toUpper(),QString("HELLO"));
}
