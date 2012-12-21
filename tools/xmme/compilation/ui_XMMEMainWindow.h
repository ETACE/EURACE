/********************************************************************************
** Form generated from reading UI file 'XMMEMainWindow.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMMEMAINWINDOW_H
#define UI_XMMEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../src/XModelView.h"

QT_BEGIN_NAMESPACE

class Ui_XMMEMainWindow
{
public:
    QAction *actionQuoit;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QAction *actionNew;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout;
    XModelView *modelView;
    QTabWidget *tabWidget;
    QWidget *editing;
    QWidget *XMM;
    QVBoxLayout *vboxLayout1;
    QTextBrowser *informationView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *XMMEMainWindow)
    {
        if (XMMEMainWindow->objectName().isEmpty())
            XMMEMainWindow->setObjectName(QString::fromUtf8("XMMEMainWindow"));
        XMMEMainWindow->resize(584, 323);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(XMMEMainWindow->sizePolicy().hasHeightForWidth());
        XMMEMainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/xmme/images/euracelogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        XMMEMainWindow->setWindowIcon(icon);
        actionQuoit = new QAction(XMMEMainWindow);
        actionQuoit->setObjectName(QString::fromUtf8("actionQuoit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/xmme/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuoit->setIcon(icon1);
        actionAbout = new QAction(XMMEMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/xmme/images/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionSave = new QAction(XMMEMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/xmme/images/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionSave_As = new QAction(XMMEMainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionOpen = new QAction(XMMEMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/xmme/images/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon4);
        actionNew = new QAction(XMMEMainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/xmme/images/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon5);
        centralwidget = new QWidget(XMMEMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout = new QVBoxLayout(groupBox);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        modelView = new XModelView(groupBox);
        modelView->setObjectName(QString::fromUtf8("modelView"));

        vboxLayout->addWidget(modelView);

        splitter->addWidget(groupBox);

        hboxLayout->addWidget(splitter);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        editing = new QWidget();
        editing->setObjectName(QString::fromUtf8("editing"));
        tabWidget->addTab(editing, QString());
        XMM = new QWidget();
        XMM->setObjectName(QString::fromUtf8("XMM"));
        vboxLayout1 = new QVBoxLayout(XMM);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        informationView = new QTextBrowser(XMM);
        informationView->setObjectName(QString::fromUtf8("informationView"));

        vboxLayout1->addWidget(informationView);

        tabWidget->addTab(XMM, QString());

        hboxLayout->addWidget(tabWidget);

        XMMEMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(XMMEMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 584, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        XMMEMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(XMMEMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        XMMEMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(XMMEMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        XMMEMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionQuoit);
        menuHelp->addAction(actionAbout);

        retranslateUi(XMMEMainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XMMEMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *XMMEMainWindow)
    {
        XMMEMainWindow->setWindowTitle(QApplication::translate("XMMEMainWindow", "AgentGUI", 0, QApplication::UnicodeUTF8));
        actionQuoit->setText(QApplication::translate("XMMEMainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("XMMEMainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("XMMEMainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("XMMEMainWindow", "Save &As", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("XMMEMainWindow", "&Open", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("XMMEMainWindow", "&New", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XMMEMainWindow", "X Machines Model Hierarchy", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(editing), QApplication::translate("XMMEMainWindow", "Edit Properties", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(XMM), QApplication::translate("XMMEMainWindow", "XMML Information", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("XMMEMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("XMMEMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("XMMEMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XMMEMainWindow: public Ui_XMMEMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMMEMAINWINDOW_H
