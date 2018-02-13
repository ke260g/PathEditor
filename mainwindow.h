#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qpathlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    QPathList * sysPathList;
    QPathList * usrPathList;
    Ui::MainWindow *ui;
    bool delItemConfirm(QString & item);
    void getNewItemDir(QString & dir);
};

#endif // MAINWINDOW_H
