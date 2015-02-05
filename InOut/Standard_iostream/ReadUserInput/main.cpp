#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char name[50];

    std::cout << "Please enter your name : ";
    std::cin >> name;
    std::cout << "Your name is " << name << endl;

    QString text(name);

    QTextStream(stdout) << text << endl;

    return a.exec();
}
