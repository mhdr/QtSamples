#include "widget.h"
#include <QApplication>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    WId id= w.winId();
    QFileDialog *fileDialog=new QFileDialog();
    QString filePath= fileDialog->getOpenFileName();

    QString idStr=QString::number(id);

    QString command=QString("mplayer %1 -wid %2").arg(filePath,idStr);

    w.show();

    QProcess *proc=new QProcess();
    proc->start(command);

    QTextStream(stdout) << command << endl;

    return a.exec();
}
