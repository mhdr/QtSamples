#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>

class Environment : public QObject
{
    Q_OBJECT
public:
    explicit Environment(QObject *parent = 0);
    static QString getmGetFolder();
    qint32 createmGetFolder();

signals:

public slots:
};

#endif // ENVIRONMENT_H
