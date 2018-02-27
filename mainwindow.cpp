#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qenvvarpath.h"
#include "win32uac.h"

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
// the same as translation files

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

class MainWindow::Tips {
private:
    Tips();
    ~Tips();

public:
    static bool delItemConfirm(QWidget *parent, /*in*/const QString & item);
    static void getNewItemFromDir(QWidget *parent, /*out*/QString & item);
    static void sysPathRWError(QWidget * parent, /*in*/QString & msg);
    static void saveSucceeded(QWidget * parent);
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
    connect(usrPathList, &QPathList::newModification,
            this, &MainWindow::usrOnNewModification);

    // sys
    sysPathList = new QPathList();
    ui->gridLayout->addWidget(sysPathList, 4, 0, 1, 4);
    connect(sysPathList, &QPathList::newModification,
            this, &MainWindow::sysOnNewModification);
}

MainWindow::~MainWindow() {
    delete ui;
    delete usrPathList;
    delete sysPathList;
}

void MainWindow::showAfter() {
    on_pushButton_usrGet_clicked();
    on_pushButton_sysGet_clicked();

    usrIsSaved = true;
    ui->usrLogBar->setText("");

    sysIsSaved = true;
    ui->sysLogBar->setText("");
}

void MainWindow::closeEvent(QCloseEvent * event) {
    if(usrIsSaved || sysIsSaved)
        event->accept();
    QString title = tr("Close Confirmation");
    QString tips = tr("Modification is not saved\n"
                      "Are you sure you want to exit?");
    int retval = QMessageBox::question(this, title,  tips,
                                       QMessageBox::Yes|QMessageBox::No,
                                       QMessageBox::No);
    if (retval == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
};

// Language
QString MainWindow::Language::Chinese::name = "tr_zh";
QString MainWindow::Language::English::name = "tr_en";

// Tips implement
bool MainWindow::Tips::delItemConfirm(QWidget *parent, /*in*/const QString & item) {
    QString title;
    QString tips;
    title = tr("Delete 'Path' Entry");
    tips = tr("Are you sure to delete this 'Path' entry?");
    tips += '\n';

    if(item.isEmpty())
        tips += tr("This is an empty entry!");
    else
        tips += tr("Entry: ") + item + '\n' + tr("will be deleted!");

    int retval = QMessageBox::warning(parent, title, tips,
                                      QMessageBox::Yes |
                                      QMessageBox::Cancel,
                                      QMessageBox::Cancel);
    if(retval == QMessageBox::Yes)
        return true;
    else
        return false;
}

void MainWindow::Tips::getNewItemFromDir(QWidget *parent, /*out*/QString & item) {
    QString strHomeDir = QDir::toNativeSeparators(QDir::home().path());
    QString str = QFileDialog::getExistingDirectory(parent, tr("Select Directory"),
                                                    strHomeDir,
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontResolveSymlinks);
    // platform dir seperator compatition handle
    item = QDir::toNativeSeparators(str);
}

void MainWindow::Tips::sysPathRWError(QWidget * parent, /*in*/QString & msg) {
    QString title;
    QString tips;
    title = tr("Error");
    tips = msg;
    tips += '\n';
    if(WIN32UAC::isRunAsAdmin() == false) {
        tips += tr("Administrative Privileges is needed.\n"
                   "Re-run the program with Administrative Privileges.\n"
                   "Or say yes when ask for Administrative Privileges at the beginning.");
    } else
        tips += tr("Unkown") + ' ' + tr("Error");
    QMessageBox::critical(parent, title, tips);
}

void MainWindow::Tips::saveSucceeded(QWidget * parent) {
    QMessageBox::information(parent, "", tr("Save") + ' '  + tr("Succeeded!"));
}

void MainWindow::usrOnNewModification() {
    usrIsSaved = false;
    ui->usrLogBar->setText(tr("Modification is not saved"));
}

void MainWindow::sysOnNewModification() {
    sysIsSaved = false;
    ui->sysLogBar->setText(tr("Modification is not saved"));
}

// sys buttons
void MainWindow::on_pushButton_sysGet_clicked() {
    QString ErrMsg = tr("Fetch") + ' ' + tr("Failed");
    if(WIN32UAC::isRunAsAdmin() == false) {
        Tips::sysPathRWError(this, ErrMsg);
        return;
    }

    QStringList strList;
    bool retval = QEnvVarPath::getSys(strList);
    if(retval == QEnvVarPath::Failure)
        Tips::sysPathRWError(this, ErrMsg);
    else
        sysPathList->setAll(strList);
}

void MainWindow::on_pushButton_sysSave_clicked() {
    QString ErrMsg = tr("Save") + ' ' + tr("Failed");
    if(WIN32UAC::isRunAsAdmin() == false) {
        Tips::sysPathRWError(this, ErrMsg);
        return;
    }

    QStringList strList;
    sysPathList->getAll(strList);

    bool retval = QEnvVarPath::setSys(strList);
    if(retval == QEnvVarPath::Failure)
        Tips::sysPathRWError(this, ErrMsg);
    else {
        sysIsSaved = true;
        ui->sysLogBar->setText("");
        Tips::saveSucceeded(this);
    }
}

void MainWindow::on_pushButton_sysDel_clicked() {
    if(sysPathList->count() == 0)
        return;
    QString str;
    sysPathList->getCurrentStr(str);
    if(Tips::delItemConfirm(this, str))
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
    Tips::getNewItemFromDir(this, str);
    if(!str.isEmpty())
        sysPathList->addPathItem(str);
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

    ui->usrLogBar->setText("");
    usrIsSaved = true;
    Tips::saveSucceeded(this);
}

void MainWindow::on_pushButton_usrDel_clicked() {
    if(usrPathList->count() == 0)
        return;
    QString item;
    usrPathList->getCurrentStr(item);
    if(Tips::delItemConfirm(this, item))
        usrPathList->delPathItem();
}

void MainWindow::on_pushButton_usrToClipBoard_clicked() {
    usrPathList->toClipBoard();
}

void MainWindow::on_pushButton_usrAdd_clicked() {
    usrPathList->addPathItem();
}

void MainWindow::on_pushButton_usrAddFromDir_clicked() {
    QString str;
    Tips::getNewItemFromDir(this, str);
    if(!str.isEmpty())
        usrPathList->addPathItem(str);
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
