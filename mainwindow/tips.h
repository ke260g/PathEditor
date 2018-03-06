#ifndef MAINWINDOW_TIPS_H
#define MAINWINDOW_TIPS_H

#include "../mainwindow.h"

// MainWindow::Tips
class MainWindow::Tips {
private:
    Tips();
    ~Tips();

public:
    static bool delItemConfirm(QWidget *parent, /*in*/const QString & item);
    static void getNewItemFromDir(QWidget *parent, /*out*/QString & item);
    static void sysPathRWError(QWidget * parent, /*in*/QString & msg);
    static void saveSucceeded(QWidget * parent);
    static bool closeConfirm(QWidget * parent);
};

#endif // MAINWINDOW_TIPS_H
