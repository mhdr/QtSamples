#include "widget.h"
#include  "player.h"
#include <QApplication>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QProcess>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    WId id= w.winId();
    QFileDialog *fileDialog=new QFileDialog();
    QString filePath= fileDialog->getOpenFileName();

    QString idStr=QString::number(id);

    mkfifo("/tmp/mplayerFIFO",S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);

    QString command=QString("mplayer -wid %1 -slave -input file=/tmp/mplayerFIFO %2").arg(idStr,filePath);

    w.show();

    QProcess *proc=new QProcess();
    proc->start(command);

    QTextStream(stdout) << command << endl;

    auto *p=new Player();
    p->show();

    return a.exec();
}
