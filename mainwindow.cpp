#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qenvvarpath.h"
#include <QDebug>

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList strList;
    // sys
    sysPathList = new QPathList;
    ui->sysVLayout->addWidget(sysPathList);
    this->on_pushButton_sysGet_clicked();

    // usr
    usrPathList = new QPathList;
    ui->usrVLayout->addWidget(usrPathList);
    this->on_pushButton_usrGet_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// sys buttons
void MainWindow::on_pushButton_sysGet_clicked() {
    QStringList strList;
    QEnvVarPath::getSys(strList);
    sysPathList->setFromQStringList(strList);
}

void MainWindow::on_pushButton_sysSave_clicked() {
    QStringList strList;
    sysPathList->getToQStringList(strList);
    QEnvVarPath::setSys(strList);
}

void MainWindow::on_pushButton_sysDel_clicked() {
    if(sysPathList->count() == 0)
        return;
    QString item;
    sysPathList->getPathItem(item);
    if(delItemConfirm(item))
        sysPathList->delPathItem();
}

void MainWindow::on_pushButton_sysToClipBoard_clicked() {
    sysPathList->getToClipBoard();
}

void MainWindow::on_pushButton_sysAdd_clicked() {
    sysPathList->addPathItem();
    sysPathList->setCursorFollow();
}

// usr buttons
void MainWindow::on_pushButton_usrGet_clicked() {
    QStringList strList;
    QEnvVarPath::getUsr(strList);
    usrPathList->setFromQStringList(strList);
}

void MainWindow::on_pushButton_usrSave_clicked() {
    QStringList strList;
    usrPathList->getToQStringList(strList);
    QEnvVarPath::setUsr(strList);
}

void MainWindow::on_pushButton_usrDel_clicked() {
    if(usrPathList->count() == 0)
        return;
    QString item;
    usrPathList->getPathItem(item);
    if(delItemConfirm(item))
        usrPathList->delPathItem();
}

void MainWindow::on_pushButton_usrToClipBoard_clicked() {
    usrPathList->getToClipBoard();
}

void MainWindow::on_pushButton_usrAdd_clicked() {
    usrPathList->addPathItem();
    usrPathList->setCursorFollow();
}

bool MainWindow::delItemConfirm(QString & item) {
    QString prompt = tr("Delete 'Path' Entry");
    QString tips;
    tips = tr("Do you want to delete this 'Path' entry ?\n");

    if(item.isEmpty())
        tips += "This is an empty entry!";
    else
        tips += tr("Entry: ") + item + tr(" will be deleted!");

    int ret = QMessageBox::question(this, prompt, tips,
                                    QMessageBox::Yes |
                                    QMessageBox::Cancel,
                                    QMessageBox::Cancel);
    if(ret == QMessageBox::Yes)
        return true;
    else
        return false;
}

void MainWindow::on_pushButton_sysAddFromDir_clicked()
{

    QString str;
    this->getNewItemDir(str);
    if(!str.isEmpty())
        this->sysPathList->addPathItem(str);
}

void MainWindow::on_pushButton_usrAddFromDir_clicked()
{
    QString str;
    this->getNewItemDir(str);
    if(!str.isEmpty())
        this->usrPathList->addPathItem(str);
}

void MainWindow::getNewItemDir(QString & dir) {
    QString strHomeDir = QDir::toNativeSeparators(QDir::home().path());
    QString str = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    strHomeDir,
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontResolveSymlinks);
    // platform dir seperator compatition handle
    dir = QDir::toNativeSeparators(str);
}
