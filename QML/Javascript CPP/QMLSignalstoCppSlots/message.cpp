#include "message.h"
#include <QTextStream>

Message::Message(QObject *parent) : QObject(parent)
{

}

void Message::doMessage()
{
    QTextStream out(stdout);

    out << "Hello World" << endl;
}

