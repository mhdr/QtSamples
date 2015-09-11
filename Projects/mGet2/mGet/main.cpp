#include <QCoreApplication>
#include <download.h>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream out(stdout);

    if (argc==2)
    {
        QString url=QString(argv[1]);
        Download *download=new Download(url);
        download->startDownload();
    }

    return 0;
}
