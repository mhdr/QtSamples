#ifndef HTTPCLIENTTESTS_H
#define HTTPCLIENTTESTS_H

#include <QObject>

class HttpClientTests : public QObject
{
    Q_OBJECT
public:
    explicit HttpClientTests(QObject *parent = 0);

signals:

public slots:

private slots:
    void test0001_url();
    void test0002_url();
    void test0003_getFileSize();
    void test0004_getFileSize();
    void test0005_getFileSize();
    void test0006_getFileSize();
    void test0007_downloadFile();
    void test0008_downloadFile();

};

#endif // HTTPCLIENTTESTS_H
