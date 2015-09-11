#ifndef GREETING_H
#define GREETING_H

#include <QObject>

class Greeting : public QObject
{
    Q_OBJECT
public:
    explicit Greeting(QObject *parent = 0);
    Q_INVOKABLE QString welcome(QString name);

signals:

public slots:
};

#endif // GREETING_H
