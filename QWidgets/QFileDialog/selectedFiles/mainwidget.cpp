#include "mainwidget.h"
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QStringList>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QFileDialog *fileDialog=new QFileDialog();
    QStringList fileNames;
    QTextStream log(stdout);

    if (fileDialog->exec())
    {
        fileNames=fileDialog->selectedFiles();
    }

    int count=fileNames.count();
    log << count << endl;

    for (int i=0;i<count;i++)
    {
        QString fileName=fileNames[i];
        log << fileName << endl;
    }
}

MainWidget::~MainWidget()
{

}
