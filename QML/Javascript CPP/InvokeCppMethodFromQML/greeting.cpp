#include "greeting.h"

Greeting::Greeting(QObject *parent) : QObject(parent)
{

}

QString Greeting::welcome(QString name)
{
    QString msg=QString("Hello %1").arg(name);
    return msg;
}

