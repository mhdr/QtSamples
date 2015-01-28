#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QComboBox>

class MainWidget : public QWidget
{
    Q_OBJECT
    QComboBox *comboBox=new QComboBox();

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void comboBox_currentIndexChanged(int);
};

#endif // MAINWIDGET_H
