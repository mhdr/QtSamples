#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox *message_box=new QMessageBox();
    message_box->setText("Hello World");
    message_box->exec();

    return a.exec();
}
