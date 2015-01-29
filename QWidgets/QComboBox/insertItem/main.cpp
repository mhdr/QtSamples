#include "mainwidget.h"
#include <QApplication>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QComboBox *comboBox=new QComboBox();
    comboBox->setFixedWidth(200);
    comboBox->insertItem(0,"Mahmood");
    comboBox->insertItem(0,"Javad");
    comboBox->insertItem(0,"Majeed");
    comboBox->insertItem(comboBox->count(),"Hamed");

    comboBox->show();

    return a.exec();
}
