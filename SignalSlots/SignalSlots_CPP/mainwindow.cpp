#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonExit,SIGNAL(clicked()),SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
