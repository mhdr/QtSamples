#ifndef DOWNLOADINFO_H
#define DOWNLOADINFO_H

#include <QObject>

class DownloadInfo : public QObject
{
    Q_OBJECT
public:
    explicit DownloadInfo(QObject *parent = 0);
    QString fileName;
    int startByte;
    int endByte;

signals:

public slots:
};

#endif // DOWNLOADINFO_H
