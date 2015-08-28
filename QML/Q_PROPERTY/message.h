#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    QString m_message;
    int m_counter;

public:
    explicit Message(QObject *parent = 0);

    QString message() const
    {
        return m_message;
    }

signals:

    void messageChanged(QString message);

public slots:

    void setMessage(QString message)
    {
        if (m_message == message)
            return;

        m_message = message;
        emit messageChanged(message);
    }

    void doMessage();
};

#endif // MESSAGE_H
