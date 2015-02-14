#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = 0);
    ~MyClient();

    void sendData(QString data);

signals:

public slots:

private:
    void readData();
};

#endif // MYCLIENT_H
