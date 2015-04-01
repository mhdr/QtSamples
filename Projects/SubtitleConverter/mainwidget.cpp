#include "mainwidget.h"
#include "ui_mainwidget.h"

QTextStream log(stdout);
QSettings settings("settings.ini",QSettings::IniFormat);

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    this->initialize_ui();
    this->initialize_nonui();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initialize_ui()
{
    this->setWindowTitle("Subtitle Connverter");

    QByteArray mainWidgetGeometry=settings.value("Geometry/MainWidget").toByteArray();

    if (mainWidgetGeometry!=NULL)
    {
        this->restoreGeometry(mainWidgetGeometry);
    }

}

void MainWidget::initialize_nonui()
{

}

void MainWidget::on_buttonConvert_clicked()
{
    QString fileName=ui->lineEdit->text();
    QMessageBox *msgBox=new QMessageBox();

    if (fileName.length()==0)
    {
        msgBox->setText("No file is selected.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    QFile *file=new QFile(fileName);

    if (!file->exists())
    {
        msgBox->setText("Invalid file path.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    QFileInfo *fileInfo=new QFileInfo(fileName);

    QString suffix= fileInfo->completeSuffix();

    if (suffix!="srt")
    {
        msgBox->setText("Invalid file type.You can only convert srt files.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    if (!file->open(QIODevice::ReadWrite))
    {
        msgBox->setText("Can not open the file.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    QString backupfileName=QString("%1.bak").arg(fileName);
    if (!file->copy(fileName,backupfileName))
    {
        msgBox->setText("Backup creation failed.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    QByteArray content= file->readAll();

    if (!file->remove())
    {
        msgBox->setText("Removaing old file failed.");
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->exec();

        return;
    }

    file->close();

    file=new QFile(fileName);
    file->open(QIODevice::WriteOnly);

    QTextCodec *codec=QTextCodec::codecForName("windows-1256");
    QString utfContent=codec->toUnicode(content);

    QTextStream outputFile(file);
    outputFile.setCodec("UTF-8");
    outputFile.setGenerateByteOrderMark(true);
    outputFile << utfContent;

    outputFile.flush();

    //file->write(utfContent.toStdString().c_str());

    if (file->flush())
    {
        msgBox->setText("File converted successfully.");
        msgBox->setIcon(QMessageBox::Information);
        msgBox->exec();
    }

    file->close();
}

void MainWidget::on_buttonBrowse_clicked()
{
    QFileDialog *dialog=new QFileDialog();

    QString lastDir= settings.value("LastDir").toString();

    if (lastDir.length()>0)
    {
        dialog->setDirectory(lastDir);
    }

    QString fileName=dialog->getOpenFileName();

    if (fileName.length()>0)
    {
        ui->lineEdit->setText(fileName);

        QFileInfo *fileInfo=new QFileInfo(fileName);
        settings.setValue("LastDir",fileInfo->absolutePath());
    }
}

void MainWidget::MainWidget::closeEvent(QCloseEvent *event)
{
    settings.setValue("Geometry/MainWidget",this->saveGeometry());
}
