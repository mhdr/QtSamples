#ifndef PRINTMSG_H
#define PRINTMSG_H

#include <QObject>
#include <QTextStream>

class PrintMsg : public QObject
{
    Q_OBJECT
public:
    explicit PrintMsg(QObject *parent = 0);
    void print(int value);

signals:

public slots:

};

#endif // PRINTMSG_H
