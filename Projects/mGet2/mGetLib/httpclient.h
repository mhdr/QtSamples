#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);
    HttpClient(QString url);

    qint32 parseUrl();
    qint32 getFileSize();
    qint32 supportResume();
    qint32 downloadFile();
    qint32 downloadFile(qint32 start,qint32 end);
    QString getFileName();
    QHash<QString,QString> parseHeaders(QByteArray headersByte);
    QHash<QString,QString> parseHeaders(QString headersStr);
    void initializeDownload(int numOfConnections=8);

    QUrl *url() const;
    void setUrl(QUrl *url);

private:
    QUrl *m_url;
    int m_port;
    QString m_host;
    QString m_path;
    int m_bufferSize=1024 * 4;
    int m_waitTime=1000 * 5;

    int port() const;
    void setPort(int port);

    QString host() const;
    void setHost(const QString &host);

    QString path() const;
    void setPath(const QString &path);

    int bufferSize() const;
    void setBufferSize(int bufferSize);

    int waitTime() const;
    void setWaitTime(int waitTime);

signals:
    void downloadProgress(double value);
    void downloadCompleted(qint64 downloadedSize);
public slots:

};

#endif // HTTPCLIENT_H
