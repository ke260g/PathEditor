#include "mainwindow.h"
#include <QApplication>

#include<QDir>
#include<QDebug>

#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./");
    QApplication a(argc, argv);
    MainWindow w;

#if 0 // set window in the center of screen
    // a bug that hidden the title of MainWindow
    w.setGeometry(QStyle::alignedRect(
                           Qt::LayoutDirectionAuto,
                           Qt::AlignCenter,
                           w.size(),
                           a.desktop()->availableGeometry()));
#endif
    w.setWindowTitle("PathEditor");
    w.show();
    w.showAfter();

    return a.exec();
}
