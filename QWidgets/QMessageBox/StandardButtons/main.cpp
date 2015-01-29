#include <QApplication>
#include <QMessageBox>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox *message_box=new QMessageBox();
    message_box->setText("The document has been modified");
    message_box->setInformativeText("Do you want to save you changes?");
    message_box->setStandardButtons(QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Discard);
    message_box->setDefaultButton(QMessageBox::Save);

    int result = message_box->exec();

    if (result==QMessageBox::Save)
    {
        QTextStream(stdout) << "Save" << endl;
    }
    else if (result==QMessageBox::Cancel)
    {
        QTextStream(stdout) << "Cancel" << endl;
    }
    else if (result==QMessageBox::Discard)
    {
        QTextStream(stdout) << "Discard" << endl;
    }

    return a.exec();
}
