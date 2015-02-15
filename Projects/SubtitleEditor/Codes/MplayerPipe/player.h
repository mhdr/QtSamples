#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);
    ~Player();

    void pause();
    void seekF();
    void seekB();

signals:

public slots:
};

#endif // PLAYER_H
