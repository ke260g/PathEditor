#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpathlist.h"

#include <QMainWindow>
#include <QTranslator>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showBefore();
    void showAfter();
    void showAgain();

private slots:
    void on_pushButton_sysGet_clicked();

    void on_pushButton_sysSave_clicked();

    void on_pushButton_sysDel_clicked();

    void on_pushButton_sysToClipBoard_clicked();

    void on_pushButton_sysAdd_clicked();

    void on_pushButton_usrGet_clicked();

    void on_pushButton_usrSave_clicked();

    void on_pushButton_usrDel_clicked();

    void on_pushButton_usrToClipBoard_clicked();

    void on_pushButton_usrAdd_clicked();

    void on_pushButton_sysAddFromDir_clicked();

    void on_pushButton_usrAddFromDir_clicked();

    void on_pushButton_sysMoveUp_clicked();

    void on_pushButton_sysMoveDown_clicked();

    void on_pushButton_usrMoveup_clicked();

    void on_pushButton_usrMoveDown_clicked();

    void on_pushButton_sysRedo_clicked();

    void on_pushButton_sysUndo_clicked();

    void on_pushButton_usrRedo_clicked();

    void on_pushButton_usrUndo_clicked();

private:
    Ui::MainWindow * ui;

    void closeEvent(QCloseEvent * event);


    bool hasInit;

    QPathList * sysPathList;
    QPathList * usrPathList;

    bool usrIsSaved;
    bool sysIsSaved;
    void usrDoSaved();
    void sysDoSaved();
    void usrUnSaved();
    void sysUnSaved();

    // Tips
    class Tips;

    // language supports
    class Language;
    QString currentLanguage;
    QTranslator translator;
    template<class Lang> void setLanguage();
};

#endif // MAINWINDOW_H
