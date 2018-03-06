#ifndef MAINWINDOW_LANGUAGE_H
#define MAINWINDOW_LANGUAGE_H

#include "../mainwindow.h"

// MainWindow::Language
class MainWindow::Language {
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

#if 0
    class new_language {
    public:
        static QString name;
    }
#endif
};
#endif // MAINWINDOW_LANGUAGE_H
