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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_sysAdd;
    QPushButton *pushButton_sysBundle;
    QFrame *line_2;
    QPushButton *pushButton_sysAddFromDir;
    QPushButton *pushButton_usrGet;
    QPushButton *pushButton_usrToClipBoard;
    QPushButton *pushButton_usrDel;
    QPushButton *pushButton_usrBundle;
    QPushButton *pushButton_sysMoveUp;
    QPushButton *pushButton_sysRedo;
    QPushButton *pushButton_sysSave;
    QPushButton *pushButton_sysUndo;
    QPushButton *pushButton_sysMoveDown;
    QFrame *line_3;
    QPushButton *pushButton_sysGet;
    QPushButton *pushButton_sysToClipBoard;
    QPushButton *pushButton_usrSave;
    QPushButton *pushButton_usrMoveDown;
    QPushButton *pushButton_usrMoveup;
    QPushButton *pushButton_sysDel;
    QPushButton *pushButton_usrAddFromDir;
    QPushButton *pushButton_usrAdd;
    QPushButton *pushButton_usrRedo;
    QPushButton *pushButton_usrUndo;
    QFrame *line;
    QWidget *sysPathList;
    QLabel *usrLogBar;
    QWidget *usrPathList;
    QLabel *sysLogBar;
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
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_sysAdd = new QPushButton(centralWidget);
        pushButton_sysAdd->setObjectName(QStringLiteral("pushButton_sysAdd"));

        gridLayout->addWidget(pushButton_sysAdd, 2, 0, 1, 1);

        pushButton_sysBundle = new QPushButton(centralWidget);
        pushButton_sysBundle->setObjectName(QStringLiteral("pushButton_sysBundle"));

        gridLayout->addWidget(pushButton_sysBundle, 0, 2, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 4);

        pushButton_sysAddFromDir = new QPushButton(centralWidget);
        pushButton_sysAddFromDir->setObjectName(QStringLiteral("pushButton_sysAddFromDir"));

        gridLayout->addWidget(pushButton_sysAddFromDir, 2, 1, 1, 1);

        pushButton_usrGet = new QPushButton(centralWidget);
        pushButton_usrGet->setObjectName(QStringLiteral("pushButton_usrGet"));

        gridLayout->addWidget(pushButton_usrGet, 0, 5, 1, 1);

        pushButton_usrToClipBoard = new QPushButton(centralWidget);
        pushButton_usrToClipBoard->setObjectName(QStringLiteral("pushButton_usrToClipBoard"));

        gridLayout->addWidget(pushButton_usrToClipBoard, 0, 8, 1, 1);

        pushButton_usrDel = new QPushButton(centralWidget);
        pushButton_usrDel->setObjectName(QStringLiteral("pushButton_usrDel"));

        gridLayout->addWidget(pushButton_usrDel, 1, 6, 1, 1);

        pushButton_usrBundle = new QPushButton(centralWidget);
        pushButton_usrBundle->setObjectName(QStringLiteral("pushButton_usrBundle"));

        gridLayout->addWidget(pushButton_usrBundle, 0, 7, 1, 1);

        pushButton_sysMoveUp = new QPushButton(centralWidget);
        pushButton_sysMoveUp->setObjectName(QStringLiteral("pushButton_sysMoveUp"));

        gridLayout->addWidget(pushButton_sysMoveUp, 1, 2, 1, 1);

        pushButton_sysRedo = new QPushButton(centralWidget);
        pushButton_sysRedo->setObjectName(QStringLiteral("pushButton_sysRedo"));

        gridLayout->addWidget(pushButton_sysRedo, 2, 2, 1, 1);

        pushButton_sysSave = new QPushButton(centralWidget);
        pushButton_sysSave->setObjectName(QStringLiteral("pushButton_sysSave"));

        gridLayout->addWidget(pushButton_sysSave, 0, 1, 1, 1);

        pushButton_sysUndo = new QPushButton(centralWidget);
        pushButton_sysUndo->setObjectName(QStringLiteral("pushButton_sysUndo"));

        gridLayout->addWidget(pushButton_sysUndo, 2, 3, 1, 1);

        pushButton_sysMoveDown = new QPushButton(centralWidget);
        pushButton_sysMoveDown->setObjectName(QStringLiteral("pushButton_sysMoveDown"));

        gridLayout->addWidget(pushButton_sysMoveDown, 1, 3, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 3, 5, 1, 4);

        pushButton_sysGet = new QPushButton(centralWidget);
        pushButton_sysGet->setObjectName(QStringLiteral("pushButton_sysGet"));

        gridLayout->addWidget(pushButton_sysGet, 0, 0, 1, 1);

        pushButton_sysToClipBoard = new QPushButton(centralWidget);
        pushButton_sysToClipBoard->setObjectName(QStringLiteral("pushButton_sysToClipBoard"));

        gridLayout->addWidget(pushButton_sysToClipBoard, 0, 3, 1, 1);

        pushButton_usrSave = new QPushButton(centralWidget);
        pushButton_usrSave->setObjectName(QStringLiteral("pushButton_usrSave"));

        gridLayout->addWidget(pushButton_usrSave, 0, 6, 1, 1);

        pushButton_usrMoveDown = new QPushButton(centralWidget);
        pushButton_usrMoveDown->setObjectName(QStringLiteral("pushButton_usrMoveDown"));

        gridLayout->addWidget(pushButton_usrMoveDown, 1, 8, 1, 1);

        pushButton_usrMoveup = new QPushButton(centralWidget);
        pushButton_usrMoveup->setObjectName(QStringLiteral("pushButton_usrMoveup"));

        gridLayout->addWidget(pushButton_usrMoveup, 1, 7, 1, 1);

        pushButton_sysDel = new QPushButton(centralWidget);
        pushButton_sysDel->setObjectName(QStringLiteral("pushButton_sysDel"));

        gridLayout->addWidget(pushButton_sysDel, 1, 1, 1, 1);

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

        usrLogBar = new QLabel(centralWidget);
        usrLogBar->setObjectName(QStringLiteral("usrLogBar"));
        usrLogBar->setEnabled(true);
        usrLogBar->setTextFormat(Qt::RichText);
        usrLogBar->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(usrLogBar, 5, 5, 1, 4);

        usrPathList = new QWidget(centralWidget);
        usrPathList->setObjectName(QStringLiteral("usrPathList"));

        gridLayout->addWidget(usrPathList, 4, 5, 1, 4);

        sysLogBar = new QLabel(centralWidget);
        sysLogBar->setObjectName(QStringLiteral("sysLogBar"));
        sysLogBar->setTextFormat(Qt::RichText);
        sysLogBar->setScaledContents(true);
        sysLogBar->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(sysLogBar, 5, 0, 1, 4);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

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
        pushButton_sysAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_sysBundle->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_sysAddFromDir->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210-\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_usrGet->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", Q_NULLPTR));
        pushButton_usrToClipBoard->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260\345\211\252\345\210\207\346\235\277", Q_NULLPTR));
        pushButton_usrDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_usrBundle->setText(QApplication::translate("MainWindow", "\346\211\271\351\207\217 \345\276\205\345\256\236\347\216\260", Q_NULLPTR));
        pushButton_sysMoveUp->setText(QApplication::translate("MainWindow", "\344\270\212\347\247\273", Q_NULLPTR));
        pushButton_sysRedo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
        pushButton_sysSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_sysUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        pushButton_sysMoveDown->setText(QApplication::translate("MainWindow", "\344\270\213\347\247\273", Q_NULLPTR));
        pushButton_sysGet->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226", Q_NULLPTR));
        pushButton_sysToClipBoard->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272\345\210\260\345\211\252\345\210\207\346\235\277", Q_NULLPTR));
        pushButton_usrSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_usrMoveDown->setText(QApplication::translate("MainWindow", "\344\270\213\347\247\273", Q_NULLPTR));
        pushButton_usrMoveup->setText(QApplication::translate("MainWindow", "\344\270\212\347\247\273", Q_NULLPTR));
        pushButton_sysDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_usrAddFromDir->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210-\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_usrAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_usrRedo->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232", Q_NULLPTR));
        pushButton_usrUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        usrLogBar->setText(QString());
        sysLogBar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
