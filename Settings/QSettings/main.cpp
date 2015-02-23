#include <QCoreApplication>
#include <QSettings>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSettings *setting=new QSettings("settings.ini",QSettings::IniFormat);

    setting->setValue("var1","value1");



    QSettings *setting2=new QSettings("settings.ini",QSettings::IniFormat);
    QTextStream(stdout) << setting2->value("var1").toString() << endl;


    setting->setValue("category1/var2","value2");
    QTextStream(stdout) << setting2->value("category1/var2").toString() << endl;

    setting->beginGroup("category2");

    setting->setValue("var3","value3");
    setting->setValue("var4","value4");

    setting->endGroup();

    QTextStream(stdout) << setting2->value("category2/var3").toString() << endl;
    QTextStream(stdout) << setting2->value("category2/var4").toString() << endl;

    return a.exec();
}
