#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QTime>
#include <QIODevice>
#include <QFile>
//kek

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push_extend(QString str)
{
    if(!extends.contains(ui->usersExtend->text()))
    {
        extends.append(str);
        ui->selectedExtends->append(str);
    }
}

void MainWindow::pop_extend(QString str)
{
    QString contens = ui->selectedExtends->toPlainText();
    extends = contens.split("\n");
    extends.removeAt(extends.indexOf(str));
    contens = "";
    for(int i = 0; i < extends.length(); i++)
    {
        if(extends.at(i) != "")
        {
            if(i != extends.length() - 1)
                contens += extends.at(i) + "\n";
            else
                contens += extends.at(i);
        }
    }
    ui->selectedExtends->clear();
    ui->selectedExtends->append(contens);
}


void MainWindow::on_txtCheck_clicked()
{
    if(ui->txtCheck->checkState() != Qt::CheckState())
    {
       push_extend(".txt");
    }else
    {
        pop_extend(".txt");
    }
}

void MainWindow::on_htmlCheck_clicked()
{
    if(ui->htmlCheck->checkState() != Qt::CheckState())
    {
        push_extend(".html");
    }else
    {
        pop_extend(".html");
    }
}

void MainWindow::on_xmdCheck_clicked()
{
    if(ui->xmdCheck->checkState() != Qt::CheckState())
    {
        push_extend(".xmd");
    }else
    {
        pop_extend(".xmd");
    }
}

void MainWindow::on_xmlCheck_clicked()
{
    if(ui->xmlCheck->checkState() != Qt::CheckState())
    {
        push_extend(".xml");
    }else
    {
        pop_extend(".xml");
    }
}

void MainWindow::on_xamlCheck_clicked()
{
    if(ui->xamlCheck->checkState() != Qt::CheckState())
    {
        push_extend(".xaml");
    }else
    {
        pop_extend(".xaml");
    }
}

void MainWindow::on_xmsCheck_clicked()
{
    if(ui->xmsCheck->checkState() != Qt::CheckState())
    {
         push_extend(".xms");
    }else
    {
        pop_extend(".xms");
    }
}

void MainWindow::on_addExtend_clicked()
{
    push_extend(ui->usersExtend->text());
}

void MainWindow::on_reset_clicked()
{
    if(ui->txtCheck->checkState() != Qt::CheckState()) ui->txtCheck->toggle();
    if(ui->htmlCheck->checkState() != Qt::CheckState()) ui->htmlCheck->toggle();
    if(ui->xmdCheck->checkState() != Qt::CheckState()) ui->xmdCheck->toggle();
    if(ui->xmlCheck->checkState() != Qt::CheckState()) ui->xmlCheck->toggle();
    if(ui->xamlCheck->checkState() != Qt::CheckState()) ui->xamlCheck->toggle();
    if(ui->xmsCheck->checkState() != Qt::CheckState()) ui->xmsCheck->toggle();
    if(ui->cssCheck->checkState() != Qt::CheckState()) ui->cssCheck->toggle();
    if(ui->jsCheck->checkState() != Qt::CheckState()) ui->jsCheck->toggle();
    if(ui->xslCheck->checkState() != Qt::CheckState()) ui->xslCheck->toggle();
    if(ui->phpCheck->checkState() != Qt::CheckState()) ui->phpCheck->toggle();
    if(ui->jsonCheck->checkState() != Qt::CheckState()) ui->jsonCheck->toggle();
    if(ui->pyCheck->checkState() != Qt::CheckState()) ui->pyCheck->toggle();
    if(ui->iniCheck->checkState() != Qt::CheckState()) ui->iniCheck->toggle();
    if(ui->logCheck->checkState() != Qt::CheckState()) ui->logCheck->toggle();
    if(ui->htaCheck->checkState() != Qt::CheckState()) ui->htaCheck->toggle();
    if(ui->batCheck->checkState() != Qt::CheckState()) ui->batCheck->toggle();
    extends.clear();
    ui->selectedExtends->clear();
}

void MainWindow::on_startSearch_clicked()
{
    if (ui->subString->text().length() >= 3){
        QTime time;
        time.start();
        ui->output->clear();
        filesCount = 0;
        QString str = ui->subString->text();

        scanDirectory(ui->searchDirectory->text(), str);

        ui->output->append("\nВсего файлов: " + QString::number(filesCount));
        ui->output->append("\nВремя выполнения: " + QString::number(time.elapsed()) + " мсек");
    }
}

void MainWindow::scanDirectory(QString path, QString str)
{
    QDir dir(path);
    QFileInfoList dirList = dir.entryInfoList();
    foreach(QFileInfo inf, dirList)
    {
        if(inf.isDir())
        {
            if(inf.fileName() != "." && inf.fileName() != "..")
            {
                scanDirectory(inf.filePath(), str);
            }
        }
        else
        {
            filesCount++;
            scanFile(inf.filePath(), str);
        }
    }
}

void MainWindow::scanFile(QString path, QString str)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int lineCount = 1;
        QString stringBoofer;
        while (!in.atEnd())
        {
            stringBoofer = in.readLine();
            if(stringBoofer.contains(str))
            {
                ui->output->append(path + ":");
                ui->output->append(QString::number(lineCount) + ": " + stringBoofer.mid(0, 75));
            }
            lineCount++;
        }
    }
    else ui->output->append("Ошибка открытия файла " + path);
}

void MainWindow::on_chooseDirectory_clicked()
{
    ui->searchDirectory->setText(QFileDialog::getExistingDirectory());
}

void MainWindow::on_xslCheck_clicked()
{
    if(ui->xslCheck->checkState() != Qt::CheckState())
    {
        push_extend(".xsl");
    }else
    {
        pop_extend(".xsl");
    }
}

void MainWindow::on_jsCheck_clicked()
{
    if(ui->jsCheck->checkState() != Qt::CheckState())
    {
        push_extend(".js");
    }else
    {
        pop_extend(".js");
    }
}

void MainWindow::on_cssCheck_clicked()
{
    if(ui->cssCheck->checkState() != Qt::CheckState())
    {
        push_extend(".css");
    }else
    {
        pop_extend(".css");
    }
}

void MainWindow::on_phpCheck_clicked()
{
    if(ui->phpCheck->checkState() != Qt::CheckState())
    {
        push_extend(".php");
    }else
    {
        pop_extend(".php");
    }
}

void MainWindow::on_jsonCheck_clicked()
{
    if(ui->jsonCheck->checkState() != Qt::CheckState())
    {
        push_extend(".json");
    }else
    {
        pop_extend(".json");
    }
}

void MainWindow::on_pyCheck_clicked()
{
    if(ui->pyCheck->checkState() != Qt::CheckState())
    {
        push_extend(".py");
    }else
    {
        pop_extend(".py");
    }
}

void MainWindow::on_iniCheck_clicked()
{
    if(ui->iniCheck->checkState() != Qt::CheckState())
    {
        push_extend(".ini");
    }else
    {
        pop_extend(".ini");
    }
}

void MainWindow::on_logCheck_clicked()
{
    if(ui->logCheck->checkState() != Qt::CheckState())
    {
        push_extend(".log");
    }else
    {
        pop_extend(".log");
    }
}

void MainWindow::on_htaCheck_clicked()
{
    if(ui->htaCheck->checkState() != Qt::CheckState())
    {
        push_extend(".hta");
    }else
    {
        pop_extend(".hta");
    }
}

void MainWindow::on_batCheck_clicked()
{
    if(ui->batCheck->checkState() != Qt::CheckState())
    {
        push_extend(".bat");
    }else
    {
        pop_extend(".bat");
    }
}

void MainWindow::on_cCheck_clicked()
{
    if(ui->cCheck->checkState() != Qt::CheckState())
    {
        push_extend(".c");
    }else
    {
        pop_extend(".c");
    }
}

void MainWindow::on_cppCheck_clicked()
{
    if(ui->cppCheck->checkState() != Qt::CheckState())
    {
        push_extend(".cpp");
    }else
    {
        pop_extend(".cpp");
    }
}
