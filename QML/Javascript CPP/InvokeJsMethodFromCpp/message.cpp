#include "message.h"
#include <QVariant>

Message::Message(QObject *parent) : QObject(parent)
{

}

Message::triggerWelcome(QString name)
{
    auto msg=QString("Hello %1").arg(name);

    QVariant returnValue;
    QVariant arg1=msg;

    QMetaObject::invokeMethod(m_rootObject,"welcome",
                              Q_RETURN_ARG(QVariant,returnValue),
                              Q_ARG(QVariant,arg1));
}

void Message::setRootObject(QObject *rootObject)
{
    m_rootObject=rootObject;
}

