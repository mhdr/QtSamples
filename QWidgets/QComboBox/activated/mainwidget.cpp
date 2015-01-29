#include "mainwidget.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QTextStream>
#include <QString>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    comboBox->addItem("Mahmood");
    comboBox->addItem("Ali");
    comboBox->addItem("Javad");
    comboBox->addItem("Hamid");
    comboBox->addItem("Nima");
    comboBox->addItem("Vahid");

    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(comboBox);

    void (QComboBox:: *comboBox_activated1) (int)=&QComboBox::activated;
    QObject::connect(comboBox,comboBox_activated1,this,&MainWidget::comboBox_activated);

    this->setLayout(layout);
}

void MainWidget::comboBox_activated(int index)
{
     QString currentText= comboBox->currentText();

     QString currentItem=comboBox->itemText(index);


     QString result=QString("index : %1 ,currentItem : %2 .currentText : %3").arg(QString::number(index),currentItem,currentText);
     QTextStream(stdout) << result << endl;
}

MainWidget::~MainWidget()
{
}
