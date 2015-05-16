#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFileDialog *dialog=new QFileDialog();
    QFileDialog::Options options=QFileDialog::DontUseNativeDialog;

    dialog->getOpenFileName(0,"","","",0,options);

    return 0;
}
