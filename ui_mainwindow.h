/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *mVLayout;
    QGridLayout *gridLayout;
    QFrame *line;
    QFrame *line_2;
    QPushButton *pushButton_sysGet;
    QPushButton *pushButton_sysSave;
    QPushButton *pushButton_usrAdd;
    QVBoxLayout *sysVLayout;
    QPushButton *pushButton_usrSave;
    QPushButton *pushButton_usrGet;
    QVBoxLayout *usrVLayout;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_3;
    QPushButton *pushButton_sysAdd;
    QPushButton *pushButton_sysToClipBoard;
    QPushButton *pushButton_sysBundle;
    QPushButton *pushButton_usrDel;
    QPushButton *pushButton_sysUndo;
    QPushButton *pushButton_sysDel;
    QPushButton *pushButton_usrBundle;
    QPushButton *pushButton_usrUndo;
    QPushButton *pushButton_usrToClipBoard;
    QPushButton *pushButton_sysAddFromDir;
    QPushButton *pushButton_usrAddFromDir;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 697);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(720, 640));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mVLayout = new QVBoxLayout();
        mVLayout->setSpacing(6);
        mVLayout->setObjectName(QStringLiteral("mVLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 6, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 3);

        pushButton_sysGet = new QPushButton(centralWidget);
        pushButton_sysGet->setObjectName(QStringLiteral("pushButton_sysGet"));

        gridLayout->addWidget(pushButton_sysGet, 1, 0, 1, 1);

        pushButton_sysSave = new QPushButton(centralWidget);
        pushButton_sysSave->setObjectName(QStringLiteral("pushButton_sysSave"));

        gridLayout->addWidget(pushButton_sysSave, 1, 1, 1, 1);

        pushButton_usrAdd = new QPushButton(centralWidget);
        pushButton_usrAdd->setObjectName(QStringLiteral("pushButton_usrAdd"));

        gridLayout->addWidget(pushButton_usrAdd, 3, 4, 1, 1);

        sysVLayout = new QVBoxLayout();
        sysVLayout->setSpacing(6);
        sysVLayout->setObjectName(QStringLiteral("sysVLayout"));

        gridLayout->addLayout(sysVLayout, 5, 0, 1, 3);

        pushButton_usrSave = new QPushButton(centralWidget);
        pushButton_usrSave->setObjectName(QStringLiteral("pushButton_usrSave"));

        gridLayout->addWidget(pushButton_usrSave, 1, 5, 1, 1);

        pushButton_usrGet = new QPushButton(centralWidget);
        pushButton_usrGet->setObjectName(QStringLiteral("pushButton_usrGet"));

        gridLayout->addWidget(pushButton_usrGet, 1, 4, 1, 1);

        usrVLayout = new QVBoxLayout();
        usrVLayout->setSpacing(6);
        usrVLayout->setObjectName(QStringLiteral("usrVLayout"));

        gridLayout->addLayout(usrVLayout, 5, 4, 1, 3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 4, 1, 3);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 4, 4, 1, 3);

        pushButton_sysAdd = new QPushButton(centralWidget);
        pushButton_sysAdd->setObjectName(QStringLiteral("pushButton_sysAdd"));

        gridLayout->addWidget(pushButton_sysAdd, 3, 0, 1, 1);

        pushButton_sysToClipBoard = new QPushButton(centralWidget);
        pushButton_sysToClipBoard->setObjectName(QStringLiteral("pushButton_sysToClipBoard"));

        gridLayout->addWidget(pushButton_sysToClipBoard, 1, 2, 1, 1);

        pushButton_sysBundle = new QPushButton(centralWidget);
        pushButton_sysBundle->setObjectName(QStringLiteral("pushButton_sysBundle"));

        gridLayout->addWidget(pushButton_sysBundle, 3, 2, 1, 1);

        pushButton_usrDel = new QPushButton(centralWidget);
        pushButton_usrDel->setObjectName(QStringLiteral("pushButton_usrDel"));

        gridLayout->addWidget(pushButton_usrDel, 2, 5, 1, 1);

        pushButton_sysUndo = new QPushButton(centralWidget);
        pushButton_sysUndo->setObjectName(QStringLiteral("pushButton_sysUndo"));

        gridLayout->addWidget(pushButton_sysUndo, 2, 2, 1, 1);

        pushButton_sysDel = new QPushButton(centralWidget);
        pushButton_sysDel->setObjectName(QStringLiteral("pushButton_sysDel"));

        gridLayout->addWidget(pushButton_sysDel, 2, 1, 1, 1);

        pushButton_usrBundle = new QPushButton(centralWidget);
        pushButton_usrBundle->setObjectName(QStringLiteral("pushButton_usrBundle"));

        gridLayout->addWidget(pushButton_usrBundle, 3, 6, 1, 1);

        pushButton_usrUndo = new QPushButton(centralWidget);
        pushButton_usrUndo->setObjectName(QStringLiteral("pushButton_usrUndo"));

        gridLayout->addWidget(pushButton_usrUndo, 2, 6, 1, 1);

        pushButton_usrToClipBoard = new QPushButton(centralWidget);
        pushButton_usrToClipBoard->setObjectName(QStringLiteral("pushButton_usrToClipBoard"));

        gridLayout->addWidget(pushButton_usrToClipBoard, 1, 6, 1, 1);

        pushButton_sysAddFromDir = new QPushButton(centralWidget);
        pushButton_sysAddFromDir->setObjectName(QStringLiteral("pushButton_sysAddFromDir"));

        gridLayout->addWidget(pushButton_sysAddFromDir, 3, 1, 1, 1);

        pushButton_usrAddFromDir = new QPushButton(centralWidget);
        pushButton_usrAddFromDir->setObjectName(QStringLiteral("pushButton_usrAddFromDir"));

        gridLayout->addWidget(pushButton_usrAddFromDir, 3, 5, 1, 1);


        mVLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(mVLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_sysGet->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", Q_NULLPTR));
        pushButton_sysSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_usrAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_usrSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_usrGet->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\347\216\257\345\242\203\345\217\230\351\207\217Path", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\216\257\345\242\203\345\217\230\351\207\217Path", Q_NULLPTR));
        pushButton_sysAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_sysToClipBoard->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260\345\211\252\345\210\207\346\235\277", Q_NULLPTR));
        pushButton_sysBundle->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_usrDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_sysUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_sysDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_usrBundle->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_usrUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_usrToClipBoard->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260\345\211\252\345\210\207\346\235\277", Q_NULLPTR));
        pushButton_sysAddFromDir->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\244\271\344\270\255\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_usrAddFromDir->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\244\271\344\270\255\346\267\273\345\212\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
