#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    Q_SLOT void spinbox_valueChanged(int value);
};

#endif // MAINWIDGET_H
