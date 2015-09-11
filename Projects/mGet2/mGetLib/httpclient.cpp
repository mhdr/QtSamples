#include "httpclient.h"
#include <QUrl>
#include <QTcpSocket>
#include <QHostInfo>
#include <QHostAddress>
#include <QUuid>
#include <QFile>
#include <QFileInfo>

HttpClient::HttpClient(QObject *parent) :
    QObject(parent)
{
}

HttpClient::HttpClient(QString url)
{
    this->setUrl(new QUrl(url));
}

qint32 HttpClient::parseUrl()
{
    QUrl *url=this->url();

    if (url->isValid()==false)
    {
        return -1;
    }

    if (url->scheme()!="http")
    {
        return -2;
    }

    QHostAddress *address=new QHostAddress(this->url()->host());

    if (address->protocol()==QAbstractSocket::UnknownNetworkLayerProtocol)
    {
        QHostInfo hostInfo= QHostInfo::fromName(this->url()->host());
        this->setHost(hostInfo.addresses()[0].toString());
    }
    else if (address->protocol()==QAbstractSocket::IPv4Protocol)
    {
        this->setHost(this->url()->host());
    }


    if (this->url()->path().length()==0)
    {
        this->setPath("/");
    }
    else {
        this->setPath(this->url()->path());
    }


    if (this->url()->port()==-1)
    {
        this->setPort(80);
    }
    else
    {
        this->setPort(this->url()->port());
    }

    return 1;
}

qint32 HttpClient::getFileSize()
{
    QStringList *requestList=new QStringList();
    requestList->append(QString("HEAD %1 HTTP/1.1").arg(this->m_path));
    requestList->append(QString("Host: %1").arg(this->m_host));
    requestList->append("Connection: Alive");
    requestList->append("");
    requestList->append("");

    QString request=requestList->join("\r\n");

    QTcpSocket *socket=new QTcpSocket();
    socket->connectToHost(this->m_host,this->m_port);
    socket->waitForConnected(this->waitTime());

    QByteArray requestB=request.toLatin1();

    if (socket->write(requestB)==-1)
    {
        return -2;
    }

    if (socket->waitForBytesWritten(this->waitTime())==false)
    {
        return -3;
    }

    int count=0;
    while (!socket->waitForReadyRead(this->waitTime()))
    {
        if (count>4)
        {
            break;
        }

        count++;
    }

    char buffer[this->bufferSize()];
    bzero(buffer,sizeof(buffer));
    QByteArray dataB=QByteArray();

    while (socket->bytesAvailable())
    {
        qint64 readBytes=socket->read(buffer,this->bufferSize());

        while (readBytes>0) {
            dataB.append(buffer,readBytes);
            bzero(buffer,sizeof(buffer));

            // read again
            readBytes=socket->read(buffer,this->bufferSize());
        }

        socket->waitForReadyRead(this->waitTime());
    }

    if (dataB.length()==0)
    {
        // empty response
        return -4;
    }

    QHash<QString,QString> headers=this->parseHeaders(dataB);

    if (headers.contains("Content-Length"))
    {
        socket->close();
        int length= headers["Content-Length"].toInt();

        return length;
    }

    socket->close();
    return -1;
}

qint32 HttpClient::supportResume()
{
    QStringList *requestList=new QStringList();
    requestList->append(QString("HEAD %1 HTTP/1.1").arg(this->m_path));
    requestList->append(QString("Host: %1").arg(this->m_host));
    requestList->append("Connection: Alive");
    requestList->append("Range: bytes=0-1");
    requestList->append("");
    requestList->append("");

    QString request=requestList->join("\r\n");

    QTcpSocket *socket=new QTcpSocket();
    socket->connectToHost(this->m_host,this->m_port);
    socket->waitForConnected(this->waitTime());

    QByteArray requestB=request.toLatin1();

    if (socket->write(requestB)==-1)
    {
        return -2;
    }

    if (socket->waitForBytesWritten(this->waitTime())==false)
    {
        return -3;
    }

    int count=0;
    while (!socket->waitForReadyRead(this->waitTime()))
    {
        if (count>4)
        {
            break;
        }

        count++;
    }

    char buffer[this->bufferSize()];
    bzero(buffer,sizeof(buffer));
    QByteArray dataB=QByteArray();

    while (socket->bytesAvailable())
    {
        qint64 readBytes=socket->read(buffer,this->bufferSize());

        while (readBytes>0) {
            dataB.append(buffer,readBytes);
            bzero(buffer,sizeof(buffer));

            // read again
            readBytes=socket->read(buffer,this->bufferSize());
        }

        socket->waitForReadyRead(this->waitTime());
    }

    if (dataB.length()==0)
    {
        // empty response
        return -4;
    }

    QHash<QString,QString> headers=this->parseHeaders(dataB);

    if (headers.contains("Accept-Ranges"))
    {
        QString result= headers["Accept-Ranges"];

        if (result=="none")
        {
            socket->close();
            return 0;
        }

        socket->close();
        return 1;
    }

    socket->close();
    return -1;
}

qint32 HttpClient::downloadFile()
{
    int fileSize=this->getFileSize();

    if (fileSize<1)
    {
        return -1;
    }

    QFile *newFile=new QFile(this->getFileName());
    newFile->open(QIODevice::WriteOnly);

    QStringList *requestList=new QStringList();
    requestList->append(QString("GET %1 HTTP/1.1").arg(this->m_path));
    requestList->append(QString("Host: %1").arg(this->m_host));
    requestList->append("Connection: Close");
    requestList->append("");
    requestList->append("");

    QString request=requestList->join("\r\n");

    QTcpSocket *socket=new QTcpSocket();
    socket->connectToHost(this->m_host,this->m_port);
    socket->waitForConnected(this->waitTime());

    QByteArray requestB=request.toLatin1();

    if (socket->write(requestB)==-1)
    {
        return -2;
    }

    if (socket->waitForBytesWritten(this->waitTime())==false)
    {
        return -3;
    }

    int count=0;
    while (!socket->waitForReadyRead(this->waitTime()))
    {
        if (count>4)
        {
            break;
        }

        count++;
    }

    int bufferSize=this->bufferSize();
    char buffer[bufferSize];
    bzero(buffer,sizeof(buffer));
    QByteArray totalBytes=QByteArray();
    bool headerLengthFound=false;
    int headerLength=-1;
    QByteArray headerBytes=QByteArray();
    QByteArray contentBytes=QByteArray();
    double responseLength=-1;

    while (socket->bytesAvailable())
    {
        qint64 readBytes=socket->read(buffer,bufferSize);

        while (readBytes>0) {
            QByteArray newData=QByteArray(buffer,readBytes);
            totalBytes.append(newData);

            if (headerLength>0)
            {
                contentBytes.append(newData);
                newFile->write(newData);
                newFile->flush();
            }

            if (headerLengthFound==false)
            {
                headerLength= totalBytes.indexOf("\r\n\r\n");

                if (headerLength>=0)
                {
                    headerBytes.append(totalBytes.mid(0,headerLength));
                    contentBytes.append(totalBytes.mid(headerLength+4));

                    newFile->write(totalBytes.mid(headerLength+4));
                    newFile->flush();

                    responseLength=headerLength+4+fileSize;

                    headerLengthFound=true;
                }
            }

            double progress=(totalBytes.length()/responseLength)*100;
            emit downloadProgress(progress);

            bzero(buffer,sizeof(buffer));

            // read again
            readBytes=socket->read(buffer,bufferSize);
        }

        socket->waitForReadyRead(this->waitTime());
    }

    socket->close();
    newFile->close();

    emit this->downloadCompleted(contentBytes.length());
    return contentBytes.length();
}

qint32 HttpClient::downloadFile(qint32 start, qint32 end)
{
    int fileSize=this->getFileSize();

    if (fileSize<1)
    {
        return -1;
    }

    QFile *newFile=new QFile(this->getFileName());
    newFile->open(QIODevice::WriteOnly);

    QStringList *requestList=new QStringList();
    requestList->append(QString("GET %1 HTTP/1.1").arg(this->m_path));
    requestList->append(QString("Host: %1").arg(this->m_host));
    requestList->append("Connection: Close");
    requestList->append("");
    requestList->append("");

    QString request=requestList->join("\r\n");

    QTcpSocket *socket=new QTcpSocket();
    socket->connectToHost(this->m_host,this->m_port);
    socket->waitForConnected(this->waitTime());

    QByteArray requestB=request.toLatin1();

    if (socket->write(requestB)==-1)
    {
        return -2;
    }

    if (socket->waitForBytesWritten(this->waitTime())==false)
    {
        return -3;
    }

    int count=0;
    while (!socket->waitForReadyRead(this->waitTime()))
    {
        if (count>4)
        {
            break;
        }

        count++;
    }

    int bufferSize=this->bufferSize();
    char buffer[bufferSize];
    bzero(buffer,sizeof(buffer));
    QByteArray totalBytes=QByteArray();
    bool headerLengthFound=false;
    int headerLength=-1;
    QByteArray headerBytes=QByteArray();
    QByteArray contentBytes=QByteArray();
    double responseLength=-1;

    while (socket->bytesAvailable())
    {
        qint64 readBytes=socket->read(buffer,bufferSize);

        while (readBytes>0) {
            QByteArray newData=QByteArray(buffer,readBytes);
            totalBytes.append(newData);

            if (headerLength>0)
            {
                contentBytes.append(newData);
                newFile->write(newData);
                newFile->flush();
            }

            if (headerLengthFound==false)
            {
                headerLength= totalBytes.indexOf("\r\n\r\n");

                if (headerLength>=0)
                {
                    headerBytes.append(totalBytes.mid(0,headerLength));
                    contentBytes.append(totalBytes.mid(headerLength+4));

                    newFile->write(totalBytes.mid(headerLength+4));
                    newFile->flush();

                    responseLength=headerLength+4+fileSize;

                    headerLengthFound=true;
                }
            }

            double progress=(totalBytes.length()/responseLength)*100;
            emit downloadProgress(progress);

            bzero(buffer,sizeof(buffer));

            // read again
            readBytes=socket->read(buffer,bufferSize);
        }

        socket->waitForReadyRead(this->waitTime());
    }

    socket->close();
    newFile->close();

    emit this->downloadCompleted(contentBytes.length());
    return contentBytes.length();
}

QString HttpClient::getFileName()
{
    QFileInfo *fileInfo=new QFileInfo(this->path());
    QString fileName= fileInfo->fileName();

    return fileName;
}

QHash<QString, QString> HttpClient::parseHeaders(QByteArray headersByte)
{
    QString headersStr=QString(headersByte);

    return this->parseHeaders(headersStr);
}

QHash<QString, QString> HttpClient::parseHeaders(QString headersStr)
{
    QHash<QString,QString> result=QHash<QString,QString>();
    QStringList headersList=headersStr.split("\r\n");

    foreach (QString s,headersList)
    {
        if (s.contains(":"))
        {
            QStringList hList=s.split(":");
            QString key=hList[0].trimmed();
            QString value=hList[1].trimmed();

            result.insert(key,value);
        }
    }

    return result;
}

void HttpClient::initializeDownload(int numOfConnections)
{

}

QUrl *HttpClient::url() const
{
    return m_url;
}

void HttpClient::setUrl(QUrl *url)
{
    m_url = url;
}
int HttpClient::bufferSize() const
{
    return m_bufferSize;
}

void HttpClient::setBufferSize(int bufferSize)
{
    m_bufferSize = bufferSize;
}
int HttpClient::waitTime() const
{
    return m_waitTime;
}

void HttpClient::setWaitTime(int waitTime)
{
    m_waitTime = waitTime;
}


int HttpClient::port() const
{
    return m_port;
}

void HttpClient::setPort(int port)
{
    m_port = port;
}
QString HttpClient::host() const
{
    return m_host;
}

void HttpClient::setHost(const QString &host)
{
    m_host = host;
}
QString HttpClient::path() const
{
    return m_path;
}

void HttpClient::setPath(const QString &path)
{
    m_path = path;
}








