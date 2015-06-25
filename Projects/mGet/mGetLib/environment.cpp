#include "environment.h"
#include <QFile>
#include <QDir>

Environment::Environment(QObject *parent) : QObject(parent)
{

}

QString Environment::getmGetFolder()
{
    QString folderPath=QString("%1/.mGet").arg(QDir::homePath());
    return folderPath;
}

qint32 Environment::createmGetFolder()
{
    QString folderPath=Environment::getmGetFolder();

    QDir *dir=new QDir(folderPath);

    if (!dir->exists(folderPath))
    {
        if (dir->mkdir(folderPath))
        {
            return 1;
        }
        else
        {
            // failure in directory creation
            return -1;
        }
    }
    else
    {
        // directory allready exist
        return 2;
    }

    return 0;
}
