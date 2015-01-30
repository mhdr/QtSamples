#include <QCoreApplication>
#include <counter.h>
#include <printmsg.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter *counter=new Counter();
    PrintMsg *print_msg=new PrintMsg();

    QObject::connect(counter,&Counter::valueChanged,print_msg,&PrintMsg::print);

    counter->setValue(12);
    counter->setValue(20);
    counter->setValue(29);

    return a.exec();
}


