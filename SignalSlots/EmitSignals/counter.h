#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = 0);
    int value();
    void setValue(int value);

signals:
    void valueChanged(int newValue);
public slots:


private:
    int m_value;
};

#endif // COUNTER_H
