#include "player.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QFile>

QHBoxLayout *mainLayout;
QFile *mplayerPipe;
QPushButton *buttonPause;
QPushButton *buttonSeekForward;
QPushButton *buttonSeekBakward;

Player::Player(QWidget *parent) : QWidget(parent)
{
    mplayerPipe=new QFile("/tmp/mplayerFIFO");
    mplayerPipe->open(QIODevice::ReadWrite);

    mainLayout=new QHBoxLayout();

    buttonPause=new QPushButton("Pause");
    connect(buttonPause,&QPushButton::clicked,this,&Player::pause);

    buttonSeekForward=new QPushButton("+10");
    connect(buttonSeekForward,&QPushButton::clicked,this,&Player::seekF);

    buttonSeekBakward=new QPushButton("-10");
    connect(buttonSeekBakward,&QPushButton::clicked,this,&Player::seekB);

    mainLayout->addWidget(buttonPause);
    mainLayout->addWidget(buttonSeekForward);
    mainLayout->addWidget(buttonSeekBakward);

    this->setLayout(mainLayout);
}

void Player::pause()
{
    mplayerPipe->write("pause\n");
    mplayerPipe->flush();
}

void Player::seekF()
{
    mplayerPipe->write("seek +10\n");
    mplayerPipe->flush();
}

void Player::seekB()
{
    mplayerPipe->write("seek -10\n");
    mplayerPipe->flush();
}

Player::~Player()
{

}

