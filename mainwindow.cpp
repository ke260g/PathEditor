#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qenvvarpath.h"

#include <QDebug>

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDir>

#include <QCoreApplication>

// Language
class MainWindow::Language {
    Q_OBJECT
    // not allow to instantialize
private:
    Language();
    ~Language();

public:
    class Chinese {
    public:
        static QString name;
    };

    class English {
    public:
        static QString name;
    };
};
QString MainWindow::Language::Chinese::name = "tr_zh";
QString MainWindow::Language::English::name = "tr_en";

template<class Lang>
void MainWindow::setLanguage() {
    if(currentLanguage == Lang::name)
        return;

    QString basename = QString(":/translations/") + Lang::name;
    QString fullname = basename + QString(".qm");
    if(QFile::exists(fullname) == false)
        return;

    translator.load(basename);
    QCoreApplication::instance()->installTranslator(&translator);
    ui->retranslateUi(this);
    currentLanguage = Lang::name;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setLanguage<Language::English>();

    connect(ui->actionChinese, &QAction::triggered,
            this, &MainWindow::setLanguage<Language::Chinese>);
    connect(ui->actionEnglish, &QAction::triggered,
            this, &MainWindow::setLanguage<Language::English>);

    // usr
    usrPathList = new QPathList();
    ui->gridLayout->addWidget(usrPathList, 4, 5, 1, 4);

    // sys
    sysPathList = new QPathList();
    ui->gridLayout->addWidget(sysPathList, 4, 0, 1, 4);
}

MainWindow::~MainWindow() {
    delete ui;
    delete usrPathList;
    delete sysPathList;
}

void MainWindow::showAfter() {
    on_pushButton_usrGet_clicked();
    on_pushButton_sysGet_clicked();
}

bool MainWindow::delItemConfirm(/*in*/const QString & item) {
    QString title;
    QString tips;
    title = tr("Delete 'Path' Entry");
    tips = tr("Are you sure to delete this 'Path' entry?\n");

    if(item.isEmpty())
        tips += tr("This is an empty entry!");
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
    QString str = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                    strHomeDir,
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontResolveSymlinks);
    // platform dir seperator compatition handle
    dir = QDir::toNativeSeparators(str);
}

void MainWindow::needAdminPrivileges(/*in*/const QString & mesg) {
    QString title;
    QString tips;
    title = tr("Error");
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
