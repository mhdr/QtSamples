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

    query.prepare("INSERT INTO People (FirstName,LastName,Age) VALUES(:FirstName,:LastName,:Age)");
    query.bindValue(":FirstName","Mahmood");
    query.bindValue(":LastName","Ramzani");
    query.bindValue(":Age",30);

    if (!query.exec())
    {
        qDebug() << query.lastQuery() << endl;
        qDebug() << query.lastError() << endl;
    }

    query.prepare("INSERT INTO People (FirstName,LastName,Age) VALUES(?,?,?)");
    query.bindValue(0,"Nasim");
    query.bindValue(1,"Baastaani");
    query.bindValue(2,25);

    if (!query.exec())
    {
        qDebug() << query.lastQuery() << endl;
        qDebug() << query.lastError() << endl;
    }

    query.prepare("SELECT * FROM People");
    query.exec();
    auto records= query.record();

    qDebug() << records << endl;

    while (query.next())
    {
        qDebug() << query.value("LastName") << endl;
    }

    query.first();

    while (query.next())
    {
        qDebug() << query.value("FirstName") << endl;
    }

    db.close();

    return 0;
}
