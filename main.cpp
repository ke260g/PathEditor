#include "mainwindow.h"
#include <QApplication>
#include "win32uac.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WIN32UAC::elevate();

    MainWindow w;
    w.show();
    w.showAfter();

    return a.exec();
}
