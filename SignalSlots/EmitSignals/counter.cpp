#include "counter.h"

Counter::Counter(QObject *parent) :
    QObject(parent)
{
}

int Counter::value()
{
    return this->m_value;
}

void Counter::setValue(int value)
{
    if (m_value!=value)
    {
        m_value=value;
        emit valueChanged(value);
    }
}
