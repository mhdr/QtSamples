#include "mainwidget.h"
#include <QFileDialog>
#include <QString>
#include <QTextStream>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QFileDialog *fileDialog=new QFileDialog();
    fileDialog->setDirectory("/home/mahmood/Downloads");
    QString filePath= fileDialog->getOpenFileName();

    QTextStream(stdout) << filePath;
}

MainWidget::~MainWidget()
{

}
