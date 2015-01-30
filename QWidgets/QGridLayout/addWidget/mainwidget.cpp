#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    label1=new QLabel("Label 1");
    label2=new QLabel("Label 2");
    label3=new QLabel("Label 3");
    label4=new QLabel("Label 4");

    mainLayout=new QGridLayout();

    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(label2,0,1);
    mainLayout->addWidget(label3,1,0);
    mainLayout->addWidget(label4,1,1);

    this->setWindowTitle("Grid");
    this->resize(600,400);
    this->setLayout(mainLayout);

}

MainWidget::~MainWidget()
{

}
