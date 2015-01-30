#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class MainWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *mainLayout;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
};

#endif // MAINWIDGET_H
