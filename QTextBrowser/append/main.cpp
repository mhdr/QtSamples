#include <QApplication>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextBrowser *browser=new QTextBrowser();
    browser->append("Hello <b>Mahmood</b>");
    browser->append("Hello <b>Javad</b>");
    browser->show();

    return a.exec();
}
