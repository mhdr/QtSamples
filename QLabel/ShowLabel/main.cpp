#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel *label=new QLabel("<font size='18'>Hello <b>Mahmood</b></font>");
    label->show();

    return a.exec();
}
