#include <QCoreApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("testDb");
    db.open();

    auto query=QSqlQuery(db);
    query.prepare("CREATE TABLE IF NOT EXISTS 'People' ('PersonId' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                  "'FirstName' TEXT NOT NULL,"
                  "'LastName' TEXT NOT NULL,"
                  "'Age' INTEGER)");
    query.exec();
    db.close();

    return 0;
}
