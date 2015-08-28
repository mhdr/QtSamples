#include "message.h"

Message::Message(QObject *parent) : QObject(parent)
{
    m_message="";
    m_counter=0;
}

void Message::doMessage()
{
    m_counter++;
    QString msg=QString("Hello World : %1").arg(m_counter);
    setMessage(msg);
}

