#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qenvvarpath.h"
#include <QDebug>

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QStringList strList;
    // sys
    sysPathList = new QPathList();
    ui->gridLayout->addWidget(sysPathList, 4, 0, 1, 4);
    on_pushButton_sysGet_clicked();

    // usr
    usrPathList = new QPathList();
    ui->gridLayout->addWidget(usrPathList, 4, 5, 1, 4);
    on_pushButton_usrGet_clicked();

}

MainWindow::~MainWindow() {
    delete ui;
    delete usrPathList;
    delete sysPathList;
}

void MainWindow::showAfter() {
    // message before everything
    QString title;
    QString tips;
    title = "Info";
    tips = tr("Operations will not be saved automatically.\n");
    tips += tr("Ensure the content is what you need after modification.\n");
    tips += tr("Then click the save button manually.\n");
    QMessageBox::information(this, title, tips);
}

bool MainWindow::delItemConfirm(/*in*/const QString & item) {
    QString title;
    QString tips;
    title = tr("Delete 'Path' Entry");
    tips = tr("Do you want to delete this 'Path' entry ?\n");

    if(item.isEmpty())
        tips += "This is an empty entry!";
    else
        tips += tr("Entry: ") + item + tr("\nwill be deleted!");

    int ret = QMessageBox::warning(this, title, tips,
                                    QMessageBox::Yes |
                                    QMessageBox::Cancel,
                                    QMessageBox::Cancel);
    if(ret == QMessageBox::Yes)
        return true;
    else
        return false;
}

void MainWindow::getNewItemDir(/*out*/QString & dir) {
    QString strHomeDir = QDir::toNativeSeparators(QDir::home().path());
    QString str = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    strHomeDir,
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontResolveSymlinks);
    // platform dir seperator compatition handle
    dir = QDir::toNativeSeparators(str);
}

void MainWindow::needAdminPrivileges(/*in*/const QString & mesg) {
    QString title;
    QString tips;
    title = tr("Error Message");
    tips = mesg;
    tips += tr("\nAdministrative Privileges may be required!");
    tips += tr("\nPlease re-run with Administrative Privileges");
    QMessageBox::critical(this, title, tips);
}

// sys buttons
void MainWindow::on_pushButton_sysGet_clicked() {
    QStringList strList;
    bool retval = QEnvVarPath::getSys(strList);

    if(retval == QEnvVarPath::Failure)
        needAdminPrivileges("Can not access System Environment Variable 'Path'!");
    else
        sysPathList->setAll(strList);
}

void MainWindow::on_pushButton_sysSave_clicked() {
    QStringList strList;
    sysPathList->getAll(strList);

    bool retval = QEnvVarPath::setSys(strList);
    if(retval == QEnvVarPath::Failure)
        needAdminPrivileges("Can not save System Environment Variable 'Path'!");
    else
        sysPathList->setAll(strList);
}

void MainWindow::on_pushButton_sysDel_clicked() {
    if(sysPathList->count() == 0)
        return;
    QString str;
    sysPathList->getCurrentStr(str);
    if(delItemConfirm(str))
        sysPathList->delPathItem();
}

void MainWindow::on_pushButton_sysToClipBoard_clicked() {
    sysPathList->toClipBoard();
}

void MainWindow::on_pushButton_sysAdd_clicked() {
    sysPathList->addPathItem();
}

void MainWindow::on_pushButton_sysAddFromDir_clicked() {
    QString str;
    getNewItemDir(str);
    if(!str.isEmpty())
        sysPathList->addPathItem(str);
}

void MainWindow::on_pushButton_usrAddFromDir_clicked() {
    QString str;
    getNewItemDir(str);
    if(!str.isEmpty())
        usrPathList->addPathItem(str);
}

void MainWindow::on_pushButton_sysMoveUp_clicked() {
    sysPathList->movePathItemUp();
}

void MainWindow::on_pushButton_sysMoveDown_clicked() {
    sysPathList->movePathItemDown();
}

void MainWindow::on_pushButton_sysRedo_clicked() {
    sysPathList->redo();
}

void MainWindow::on_pushButton_sysUndo_clicked() {
    sysPathList->undo();
}

// usr buttons
void MainWindow::on_pushButton_usrGet_clicked() {
    QStringList strList;
    QEnvVarPath::getUsr(strList);
    usrPathList->setAll(strList);
}

void MainWindow::on_pushButton_usrSave_clicked() {
    QStringList strList;
    usrPathList->getAll(strList);
    QEnvVarPath::setUsr(strList);
}

void MainWindow::on_pushButton_usrDel_clicked() {
    if(usrPathList->count() == 0)
        return;
    QString item;
    usrPathList->getCurrentStr(item);
    if(delItemConfirm(item))
        usrPathList->delPathItem();
}

void MainWindow::on_pushButton_usrToClipBoard_clicked() {
    usrPathList->toClipBoard();
}

void MainWindow::on_pushButton_usrAdd_clicked() {
    usrPathList->addPathItem();
}

void MainWindow::on_pushButton_usrMoveup_clicked() {
    usrPathList->movePathItemUp();
}

void MainWindow::on_pushButton_usrMoveDown_clicked() {
    usrPathList->movePathItemDown();
}

void MainWindow::on_pushButton_usrRedo_clicked() {
    usrPathList->redo();
}

void MainWindow::on_pushButton_usrUndo_clicked() {
    usrPathList->undo();
}
