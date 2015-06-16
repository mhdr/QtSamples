#ifndef QSTRINGTESTS2_H
#define QSTRINGTESTS2_H

#include <QObject>

class QStringTests2 : public QObject
{
    Q_OBJECT
public:
    explicit QStringTests2(QObject *parent = 0);

signals:

public slots:

private slots:
    void toUpper();
    void toUpper2();
};

#endif // QSTRINGTESTS2_H
