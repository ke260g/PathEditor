#include "mainwindow.h"
#include <QApplication>

#include<QDir>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./");
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("PathEditor");
    w.show();

    return a.exec();
}
