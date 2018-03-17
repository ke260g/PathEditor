#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qenvvarpath.h"
#include "win32uac.h"
#include "mainwindow/language.h"
#include "mainwindow/tips.h"

#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>

#define CONFIG_FILENAME "config.json"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    hasInit = false;

    setLanguage<Language::English>();

    connect(ui->actionChinese, &QAction::triggered,
            this, &MainWindow::setLanguage<Language::Chinese>);
    connect(ui->actionEnglish, &QAction::triggered,
            this, &MainWindow::setLanguage<Language::English>);

    // usr
    usrPathList = new QPathList();
    ui->gridLayout->addWidget(usrPathList, 4, 5, 1, 4);
    connect(usrPathList, &QPathList::newModification,
            this, &MainWindow::usrUnSaved);

    // sys
    sysPathList = new QPathList();
    ui->gridLayout->addWidget(sysPathList, 4, 0, 1, 4);
    connect(sysPathList, &QPathList::newModification,
            this, &MainWindow::sysUnSaved);

    usrDoSaved();
    sysDoSaved();

}

MainWindow::~MainWindow() {
    delete ui;
    delete usrPathList;
    delete sysPathList;
}

template<class mLanguage>
void MainWindow::setLanguage() {
    QString langname,
            basename,
            fullname;

    if(hasInit) {
        if(currentLanguage == mLanguage::name)
            return;

        langname = mLanguage::name;
    } else {
        QString configLanguage;
        bool hasSetLanguage = getConfig("language", configLanguage);
        if(hasSetLanguage)
            langname = configLanguage;
        else
            langname = Language::English::name;
    }

    basename = QString(":/translations/") + langname;
    fullname = basename + QString(".qm");
    // access translation file
    if(QFile::exists(fullname) == false)
        return;

    // set new language
    translator.load(basename);
    QCoreApplication::instance()->installTranslator(&translator);
    showAgain();
    currentLanguage = mLanguage::name;

    setConfig("language", mLanguage::name);
};

void MainWindow::showBefore() {
}

void MainWindow::showAfter() {
    // usrGet should be called before sysGet
    // as sysGet may need Administrative Privileges

    on_pushButton_sysGet_clicked();
    on_pushButton_usrGet_clicked();

    usrDoSaved();
    sysDoSaved();

    hasInit = true;
}

void MainWindow::showAgain() {
    ui->retranslateUi(this);

    if(usrIsSaved == false)
        usrUnSaved();

    if(sysIsSaved == false)
        sysUnSaved();
}

void MainWindow::closeEvent(QCloseEvent * event) {
    if(usrIsSaved && sysIsSaved) {
        event->accept();
        return;
    }
    if (Tips::closeConfirm(this))
        event->accept();
    else
        event->ignore();
};

// configuration
QString MainWindow::configFilename = CONFIG_FILENAME;
void MainWindow::setConfig(/*in*/const QString & key, /*in*/const QString & value) {
    QString pwd = QDir::currentPath();
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    QFile file;
    QString configString;
    QJsonObject configJson;
    QJsonDocument docJson;
    file.setFileName(CONFIG_FILENAME);

    // get existed config
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    configString = file.readAll();
    configJson = QJsonDocument::fromJson(configString.toUtf8()).object();
    file.close();

    // set new config
    configJson[key] = value;
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    docJson.setObject(configJson);
    configString = docJson.toJson();
    file.write(configString.toUtf8(), configString.size());
    file.close();

    QDir::setCurrent(pwd);
}

bool MainWindow::getConfig(/*in*/const QString & key, /*out*/QString & value) {
    bool hasKey = false;
    QString pwd = QDir::currentPath();
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    QFile file;
    QString configString;
    QJsonObject configJson;
    QJsonDocument docJson;
    file.setFileName(CONFIG_FILENAME);

    // get existed config
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    configString = file.readAll();
    configJson = QJsonDocument::fromJson(configString.toUtf8()).object();
    file.close();

    if(configJson.contains(key)) {
        value = configJson[key].toString();
        hasKey = true;
    }  else {
        value = "";
        hasKey = false;
    }

    QDir::setCurrent(pwd);
    return hasKey;
}

// save & unsave
void MainWindow::sysUnSaved() {
    sysIsSaved = false;
    ui->sysLogBar->setText(tr("Modification is not saved"));
}

void MainWindow::usrUnSaved() {
    usrIsSaved = false;
    ui->usrLogBar->setText(tr("Modification is not saved"));
}

void MainWindow::sysDoSaved() {
    sysIsSaved = true;
    ui->sysLogBar->setText("");
}

void MainWindow::usrDoSaved() {
    usrIsSaved = true;
    ui->usrLogBar->setText("");
}

// sys buttons
void MainWindow::on_pushButton_sysGet_clicked() {
    QString ErrMsg = tr("Fetch") + ' ' + tr("Failed");
    if(WIN32UAC::isRunAsAdmin() == false) {
        if(hasInit)
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
    QString ErrMsg = tr("Save Failed");
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
        sysDoSaved();
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

    usrDoSaved();
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
