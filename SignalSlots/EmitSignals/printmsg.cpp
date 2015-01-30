#include "printmsg.h"

PrintMsg::PrintMsg(QObject *parent) :
    QObject(parent)
{

}

void PrintMsg::print(int value)
{
    QTextStream(stdout) << value << endl;
}
