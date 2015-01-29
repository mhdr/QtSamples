#include "mainwidget.h"
#include <QSpinBox>
#include <QTextStream>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QSpinBox *spinbox=new QSpinBox();
    spinbox->setRange(0,100);
    spinbox->setValue(50);

    void (QSpinBox:: *valueChanged1)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinbox,valueChanged1,this,&MainWidget::spinbox_valueChanged);
    //QObject::connect(spinbox,&QSpinBox::valueChanged,this,&MainWidget::spinbox_valueChanged);
    //QObject::connect(spinbox,SIGNAL(valueChanged(int),this,SLOT(spinbox_valueChanged(int));

    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(spinbox);

    this->setLayout(layout);

}

void MainWidget::spinbox_valueChanged(int value)
{
    QTextStream(stdout) << value << endl;
}

MainWidget::~MainWidget()
{

}
