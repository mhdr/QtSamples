#include <QCoreApplication>
#include "object1.h"
#include "object2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Object1 *obj1=new Object1();
    Object2 *obj2=new Object2();

    obj1->doWork(obj2);

    return 0;
}
