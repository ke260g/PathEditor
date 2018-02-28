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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnglish;
    QAction *actionChinese;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *usrLogBar;
    QWidget *usrPathList;
    QLabel *sysLogBar;
    QPushButton *pushButton_sysRedo;
    QFrame *line_2;
    QPushButton *pushButton_usrGet;
    QPushButton *pushButton_usrToClipBoard;
    QPushButton *pushButton_usrDel;
    QPushButton *pushButton_sysSave;
    QFrame *line_3;
    QPushButton *pushButton_sysGet;
    QPushButton *pushButton_usrSave;
    QPushButton *pushButton_usrMoveDown;
    QPushButton *pushButton_usrMoveup;
    QPushButton *pushButton_usrAddFromDir;
    QPushButton *pushButton_usrAdd;
    QPushButton *pushButton_usrRedo;
    QPushButton *pushButton_usrUndo;
    QFrame *line;
    QWidget *sysPathList;
    QPushButton *pushButton_sysMoveDown;
    QPushButton *pushButton_sysAdd;
    QPushButton *pushButton_sysMoveUp;
    QPushButton *pushButton_sysUndo;
    QPushButton *pushButton_sysDel;
    QPushButton *pushButton_sysAddFromDir;
    QPushButton *pushButton_sysToClipBoard;
    QPushButton *pushButton_usrBundle;
    QPushButton *pushButton_sysBundle;
    QMenuBar *menuBar;
    QMenu *menuLanguage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 697);
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        actionChinese = new QAction(MainWindow);
        actionChinese->setObjectName(QStringLiteral("actionChinese"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(720, 640));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        usrLogBar = new QLabel(centralWidget);
        usrLogBar->setObjectName(QStringLiteral("usrLogBar"));
        usrLogBar->setEnabled(true);
        usrLogBar->setFrameShape(QFrame::Panel);
        usrLogBar->setTextFormat(Qt::RichText);
        usrLogBar->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(usrLogBar, 5, 5, 1, 4);

        usrPathList = new QWidget(centralWidget);
        usrPathList->setObjectName(QStringLiteral("usrPathList"));

        gridLayout->addWidget(usrPathList, 4, 5, 1, 4);

        sysLogBar = new QLabel(centralWidget);
        sysLogBar->setObjectName(QStringLiteral("sysLogBar"));
        sysLogBar->setFrameShape(QFrame::Panel);
        sysLogBar->setTextFormat(Qt::RichText);
        sysLogBar->setScaledContents(true);
        sysLogBar->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(sysLogBar, 5, 0, 1, 4);

        pushButton_sysRedo = new QPushButton(centralWidget);
        pushButton_sysRedo->setObjectName(QStringLiteral("pushButton_sysRedo"));

        gridLayout->addWidget(pushButton_sysRedo, 2, 2, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 4);

        pushButton_usrGet = new QPushButton(centralWidget);
        pushButton_usrGet->setObjectName(QStringLiteral("pushButton_usrGet"));

        gridLayout->addWidget(pushButton_usrGet, 0, 5, 1, 1);

        pushButton_usrToClipBoard = new QPushButton(centralWidget);
        pushButton_usrToClipBoard->setObjectName(QStringLiteral("pushButton_usrToClipBoard"));

        gridLayout->addWidget(pushButton_usrToClipBoard, 0, 8, 1, 1);

        pushButton_usrDel = new QPushButton(centralWidget);
        pushButton_usrDel->setObjectName(QStringLiteral("pushButton_usrDel"));

        gridLayout->addWidget(pushButton_usrDel, 1, 6, 1, 1);

        pushButton_sysSave = new QPushButton(centralWidget);
        pushButton_sysSave->setObjectName(QStringLiteral("pushButton_sysSave"));

        gridLayout->addWidget(pushButton_sysSave, 0, 1, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 5, 1, 4);

        pushButton_sysGet = new QPushButton(centralWidget);
        pushButton_sysGet->setObjectName(QStringLiteral("pushButton_sysGet"));

        gridLayout->addWidget(pushButton_sysGet, 0, 0, 1, 1);

        pushButton_usrSave = new QPushButton(centralWidget);
        pushButton_usrSave->setObjectName(QStringLiteral("pushButton_usrSave"));

        gridLayout->addWidget(pushButton_usrSave, 0, 6, 1, 1);

        pushButton_usrMoveDown = new QPushButton(centralWidget);
        pushButton_usrMoveDown->setObjectName(QStringLiteral("pushButton_usrMoveDown"));

        gridLayout->addWidget(pushButton_usrMoveDown, 1, 8, 1, 1);

        pushButton_usrMoveup = new QPushButton(centralWidget);
        pushButton_usrMoveup->setObjectName(QStringLiteral("pushButton_usrMoveup"));

        gridLayout->addWidget(pushButton_usrMoveup, 1, 7, 1, 1);

        pushButton_usrAddFromDir = new QPushButton(centralWidget);
        pushButton_usrAddFromDir->setObjectName(QStringLiteral("pushButton_usrAddFromDir"));

        gridLayout->addWidget(pushButton_usrAddFromDir, 2, 6, 1, 1);

        pushButton_usrAdd = new QPushButton(centralWidget);
        pushButton_usrAdd->setObjectName(QStringLiteral("pushButton_usrAdd"));

        gridLayout->addWidget(pushButton_usrAdd, 2, 5, 1, 1);

        pushButton_usrRedo = new QPushButton(centralWidget);
        pushButton_usrRedo->setObjectName(QStringLiteral("pushButton_usrRedo"));

        gridLayout->addWidget(pushButton_usrRedo, 2, 7, 1, 1);

        pushButton_usrUndo = new QPushButton(centralWidget);
        pushButton_usrUndo->setObjectName(QStringLiteral("pushButton_usrUndo"));

        gridLayout->addWidget(pushButton_usrUndo, 2, 8, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 4, 6, 1);

        sysPathList = new QWidget(centralWidget);
        sysPathList->setObjectName(QStringLiteral("sysPathList"));

        gridLayout->addWidget(sysPathList, 4, 0, 1, 4);

        pushButton_sysMoveDown = new QPushButton(centralWidget);
        pushButton_sysMoveDown->setObjectName(QStringLiteral("pushButton_sysMoveDown"));

        gridLayout->addWidget(pushButton_sysMoveDown, 1, 3, 1, 1);

        pushButton_sysAdd = new QPushButton(centralWidget);
        pushButton_sysAdd->setObjectName(QStringLiteral("pushButton_sysAdd"));

        gridLayout->addWidget(pushButton_sysAdd, 2, 0, 1, 1);

        pushButton_sysMoveUp = new QPushButton(centralWidget);
        pushButton_sysMoveUp->setObjectName(QStringLiteral("pushButton_sysMoveUp"));

        gridLayout->addWidget(pushButton_sysMoveUp, 1, 2, 1, 1);

        pushButton_sysUndo = new QPushButton(centralWidget);
        pushButton_sysUndo->setObjectName(QStringLiteral("pushButton_sysUndo"));

        gridLayout->addWidget(pushButton_sysUndo, 2, 3, 1, 1);

        pushButton_sysDel = new QPushButton(centralWidget);
        pushButton_sysDel->setObjectName(QStringLiteral("pushButton_sysDel"));

        gridLayout->addWidget(pushButton_sysDel, 1, 1, 1, 1);

        pushButton_sysAddFromDir = new QPushButton(centralWidget);
        pushButton_sysAddFromDir->setObjectName(QStringLiteral("pushButton_sysAddFromDir"));

        gridLayout->addWidget(pushButton_sysAddFromDir, 2, 1, 1, 1);

        pushButton_sysToClipBoard = new QPushButton(centralWidget);
        pushButton_sysToClipBoard->setObjectName(QStringLiteral("pushButton_sysToClipBoard"));

        gridLayout->addWidget(pushButton_sysToClipBoard, 0, 3, 1, 1);

        pushButton_usrBundle = new QPushButton(centralWidget);
        pushButton_usrBundle->setObjectName(QStringLiteral("pushButton_usrBundle"));

        gridLayout->addWidget(pushButton_usrBundle, 0, 7, 1, 1);

        pushButton_sysBundle = new QPushButton(centralWidget);
        pushButton_sysBundle->setObjectName(QStringLiteral("pushButton_sysBundle"));

        gridLayout->addWidget(pushButton_sysBundle, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 23));
        menuBar->setDefaultUp(false);
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QStringLiteral("menuLanguage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLanguage->menuAction());
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionChinese);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PathEditor", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        actionChinese->setText(QApplication::translate("MainWindow", "Chinese", Q_NULLPTR));
        usrLogBar->setText(QString());
        sysLogBar->setText(QString());
        pushButton_sysRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        pushButton_usrGet->setText(QApplication::translate("MainWindow", "Fetch", Q_NULLPTR));
        pushButton_usrToClipBoard->setText(QApplication::translate("MainWindow", "ToClipborad", Q_NULLPTR));
        pushButton_usrDel->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        pushButton_sysSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        pushButton_sysGet->setText(QApplication::translate("MainWindow", "Fetch", Q_NULLPTR));
        pushButton_usrSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        pushButton_usrMoveDown->setText(QApplication::translate("MainWindow", "Move Down", Q_NULLPTR));
        pushButton_usrMoveup->setText(QApplication::translate("MainWindow", "Move Up", Q_NULLPTR));
        pushButton_usrAddFromDir->setText(QApplication::translate("MainWindow", "Add From Dir", Q_NULLPTR));
        pushButton_usrAdd->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_usrRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        pushButton_usrUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        pushButton_sysMoveDown->setText(QApplication::translate("MainWindow", "Move Down", Q_NULLPTR));
        pushButton_sysAdd->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_sysMoveUp->setText(QApplication::translate("MainWindow", "Move Up", Q_NULLPTR));
        pushButton_sysUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        pushButton_sysDel->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        pushButton_sysAddFromDir->setText(QApplication::translate("MainWindow", "Add From Dir", Q_NULLPTR));
        pushButton_sysToClipBoard->setText(QApplication::translate("MainWindow", "ToClipborad", Q_NULLPTR));
        pushButton_usrBundle->setText(QApplication::translate("MainWindow", "Bundle(x)", Q_NULLPTR));
        pushButton_sysBundle->setText(QApplication::translate("MainWindow", "Bundle(x)", Q_NULLPTR));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
