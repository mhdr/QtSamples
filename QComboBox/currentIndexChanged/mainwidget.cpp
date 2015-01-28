#include "mainwidget.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QTextStream>
#include <QString>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //QComboBox *comboBox=new QComboBox();
    comboBox->addItem("Mahmood");
    comboBox->addItem("Ali");
    comboBox->addItem("Javad");
    comboBox->addItem("Hamid");
    comboBox->addItem("Nima");
    comboBox->addItem("Vahid");

    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(comboBox);

    void (QComboBox:: *currentIndexChanged1) (int)=&QComboBox::currentIndexChanged;
    QObject::connect(comboBox,currentIndexChanged1,this,&MainWidget::comboBox_currentIndexChanged);

    this->setLayout(layout);
}

void MainWidget::comboBox_currentIndexChanged(int index)
{
     QString currentText= comboBox->currentText();

     QString currentItem=comboBox->itemText(index);


     QString result=QString("index : %1 ,currentItem : %2 .currentText : %3").arg(QString::number(index),currentItem,currentText);
     QTextStream(stdout) << result << endl;
}

MainWidget::~MainWidget()
{

}
