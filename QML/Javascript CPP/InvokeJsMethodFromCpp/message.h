#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    QObject* m_rootObject;

public:
    explicit Message(QObject *parent = 0);
    Q_INVOKABLE triggerWelcome(QString name);
    void setRootObject(QObject* rootObject);

signals:

public slots:

};

#endif // MESSAGE_H
