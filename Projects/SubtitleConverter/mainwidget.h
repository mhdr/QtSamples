#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextCodec>
#include <QFileDialog>
#include <QSettings>
#include <QTextStream>
#include <QByteArray>
#include <QIODevice>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    void initialize_ui();
    void initialize_nonui();
private slots:
    void on_buttonConvert_clicked();
    void on_buttonBrowse_clicked();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWIDGET_H
