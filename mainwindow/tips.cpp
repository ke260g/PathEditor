#include "tips.h"
#include "../win32uac.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>


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
        tips += tr("Administrative Privileges is needed.\n");
        /*
         * "Re-run the program with Administrative Privileges.\n"
         * "Or say yes when ask for Administrative Privileges at the beginning.\n"
         */
    } else
        tips += tr("Unkown") + ' ' + tr("Error");
    QMessageBox::critical(parent, title, tips);
}

void MainWindow::Tips::saveSucceeded(QWidget * parent) {
    QMessageBox::information(parent, "", tr("Save Succeeded"));
}


bool MainWindow::Tips::closeConfirm(QWidget * parent) {
    QString title = tr("Close Confirmation");
    QString tips = tr("Modification is not saved\n"
                      "Are you sure you want to exit?");
    int retval = QMessageBox::question(parent, title,  tips,
                                       QMessageBox::Yes|QMessageBox::No,
                                       QMessageBox::No);
    if(retval == QMessageBox::Yes)
        return true;
    else
        return false;
}
