#include "mainwindow.h"
#include <QApplication>
#include "win32uac.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.showAfter();
    WIN32UAC::elevate();

    return a.exec();
}
