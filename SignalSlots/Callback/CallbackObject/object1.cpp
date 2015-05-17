#include "object1.h"
#include "object2.h"
#include <QThread>

Object1::Object1()
{
}

void Object1::doWork(void *f)
{
    QThread::sleep(10);

    ((Object2 *)f)->callBack();
}
