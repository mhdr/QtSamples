#include <QApplication>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit *line_edit=new QLineEdit();
    //line_edit->setEchoMode(QLineEdit::NoEcho);
    //line_edit->setEchoMode(QLineEdit::Normal);
    //line_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    line_edit->setEchoMode(QLineEdit::Password);

    line_edit->show();

    return a.exec();
}
