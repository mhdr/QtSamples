#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <httpclient.h>

class Download : public QObject
{
    Q_OBJECT
public:
    explicit Download(QObject *parent = 0);
    explicit Download(QString url);
    void startDownload();

    HttpClient *httpClient() const;
    void setHttpClient(HttpClient *httpClient);

signals:

public slots:
    void downloadProgress(double value);
    void downloadCompleted(qint64 downloadedSize);

private:
    HttpClient *m_httpClient;
};

#endif // DOWNLOAD_H
