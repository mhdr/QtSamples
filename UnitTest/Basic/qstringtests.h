#ifndef QSTRINGTESTS_H
#define QSTRINGTESTS_H

#include <QObject>

class QStringTests : public QObject
{
    Q_OBJECT
public:
    explicit QStringTests(QObject *parent = 0);

signals:

public slots:

private slots:
    void toUpper();
    void toUpper2();
};

#endif // QSTRINGTESTS_H
