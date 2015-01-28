#include <QApplication>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextBrowser *browser=new QTextBrowser();
    browser->setHtml("Hello <b>Mahmood</b>");
    browser->setHtml("Hello <b>Javad</b>");

    browser->show();

    return a.exec();
}
