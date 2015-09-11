#include "httpclienttests.h"
#include <QtTest/QtTest>
#include <httpclient.h>

HttpClientTests::HttpClientTests(QObject *parent) :
    QObject(parent)
{
}

void HttpClientTests::test0001_url()
{
    HttpClient *httpClient=new HttpClient("http://80.84.55.200/proxy/OmegaRules_Auto_Switch.sorl");
    httpClient->parseUrl();
    QUrl *url= httpClient->url();

    QTextStream out(stdout);

    out << QString("scheme : %1").arg(url->scheme()) << endl;
    out << QString("host : %1").arg(url->host()) << endl;
    out << QString("port : %1").arg(url->port()) << endl;
    out << QString("path : %1").arg(url->path()) << endl;
}

void HttpClientTests::test0002_url()
{
    HttpClient *httpClient=new HttpClient("http://www.google.com:8080");
    httpClient->parseUrl();
    QUrl *url= httpClient->url();

    QTextStream out(stdout);

    out << QString("scheme : %1").arg(url->scheme()) << endl;
    out << QString("host : %1").arg(url->host()) << endl;
    out << QString("port : %1").arg(url->port()) << endl;
    out << QString("path : %1").arg(url->path()) << endl;
}

void HttpClientTests::test0003_getFileSize()
{
    HttpClient *httpClient=new HttpClient("http://80.84.55.200/proxy/OmegaRules_Auto_Switch.sorl");
    httpClient->parseUrl();
    int length= httpClient->getFileSize();

    QTextStream out(stdout);

    out << QString("Length : %1").arg(length) << endl;
}

void HttpClientTests::test0004_getFileSize()
{
    HttpClient *httpClient=new HttpClient("http://www.yahoo.com");
    httpClient->parseUrl();
    int length= httpClient->getFileSize();

    bool result=false;

    if (length>0)
    {
        result=true;
    }

    Q_ASSERT(result);

    QTextStream out(stdout);

    out << QString("Length : %1").arg(length) << endl;
}

void HttpClientTests::test0005_getFileSize()
{
    HttpClient *httpClient=new HttpClient("http://dl.softgozar.com/Files/Software/Process_Lasso_Pro_8.2.0.0_x86_Softgozar.com.exe");
    httpClient->parseUrl();
    int length= httpClient->getFileSize();

    bool result=false;

    if (length>0)
    {
        result=true;
    }

    Q_ASSERT(result);

    QTextStream out(stdout);

    out << QString("Length : %1").arg(length) << endl;
}

void HttpClientTests::test0006_getFileSize()
{
    HttpClient *httpClient=new HttpClient("http://80.84.55.200");
    httpClient->parseUrl();
    int actual= httpClient->getFileSize();
    int expected=-1;

    QCOMPARE(expected,actual);
    QTextStream out(stdout);

    out << QString("Length : %1").arg(actual) << endl;
}

void HttpClientTests::test0007_downloadFile()
{
    HttpClient *httpClient=new HttpClient("http://80.84.55.200/proxy/OmegaRules_Auto_Switch.sorl");
    httpClient->parseUrl();
    int length= httpClient->getFileSize();
    int downloadedLength=httpClient->downloadFile();

    QCOMPARE(length,downloadedLength);
}

void HttpClientTests::test0008_downloadFile()
{
    HttpClient *httpClient=new HttpClient("http://80.84.55.200");
    httpClient->parseUrl();
    int length= httpClient->getFileSize();
    int downloadedLength=httpClient->downloadFile();

    QCOMPARE(length,downloadedLength);
}
