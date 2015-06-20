#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug();
    qDebug() << QString::number( 123.4567890123456         );
    qDebug() << QString::number( 123.4567890123456, 'f', 2 );
    qDebug() << QString::number( 123.4567890123456, 'f', 6 );
    qDebug();
    qDebug() << QString::number( 123.4567890123456, 'e'    );
    qDebug() << QString::number( 123.4567890123456, 'e', 2 );
    qDebug() << QString::number( 123.4567890123456, 'e', 6 );
    qDebug();
    qDebug() << QString::number( 123.4567890123456, 'g'    );
    qDebug() << QString::number( 123.4567890123456, 'g', 2 );
    qDebug() << QString::number( 123.4567890123456, 'g', 6 );

    return 0;
}
