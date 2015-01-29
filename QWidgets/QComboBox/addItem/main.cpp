#include "mainwidget.h"
#include <QApplication>
#include <QComboBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QComboBox *comboBox=new QComboBox();
    comboBox->addItem("Mahmood");
    comboBox->addItem("Ali");
    comboBox->addItem("Hamed");
    comboBox->addItem("Javad");
    comboBox->show();

    return a.exec();
}
