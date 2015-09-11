#include "download.h"
#include <QTextStream>
#include <QUrl>

Download::Download(QObject *parent) : QObject(parent)
{
}

Download::Download(QString url)
{
    HttpClient *httpClient=new HttpClient(url);
    connect(httpClient,&HttpClient::downloadProgress,this,&Download::downloadProgress);
    connect(httpClient,&HttpClient::downloadCompleted,this,&Download::downloadCompleted);

    this->setHttpClient(httpClient);
}

void Download::startDownload()
{
    if (this->httpClient()->parseUrl()>0)
    {
        this->httpClient()->downloadFile();
    }
}

void Download::downloadProgress(double value)
{
    QTextStream out(stdout);

    QString value2=QString::number(value,'f',2);
    out << QString("\r%1").arg(value2);
}

void Download::downloadCompleted(qint64 downloadedSize)
{
    QTextStream out(stdout);

    out << endl;
    out << QString("%1 Completed.").arg(this->httpClient()->url()->toString()) << endl;
    out << QString("Download Size : %1 Bytes").arg(downloadedSize) << endl;
}
HttpClient *Download::httpClient() const
{
    return m_httpClient;
}

void Download::setHttpClient(HttpClient *httpClient)
{
    m_httpClient = httpClient;
}


