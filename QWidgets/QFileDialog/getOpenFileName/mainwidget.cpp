#include "mainwidget.h"
#include <QFileDialog>
#include <QString>
#include <QTextStream>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QFileDialog *fileDialog=new QFileDialog();
    QString filePath= fileDialog->getOpenFileName();

    QTextStream(stdout) << filePath;
}

MainWidget::~MainWidget()
{

}
