/********************************************************************************
** Form generated from reading UI file 'XWidgetEditFunction.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITFUNCTION_H
#define UI_XWIDGETEDITFUNCTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "Qsci/qsciscintilla.h"

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditFunction
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *vboxLayout1;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout2;
    QLineEdit *name;
    QGroupBox *groupBox_2;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *currentState;
    QLabel *label_2;
    QLineEdit *nextState;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout3;
    QsciScintilla *description;
    QWidget *tab_3;
    QVBoxLayout *vboxLayout4;
    QTextEdit *condition;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout5;
    QTextEdit *code;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditFunction)
    {
        if (XWidgetEditFunction->objectName().isEmpty())
            XWidgetEditFunction->setObjectName(QString::fromUtf8("XWidgetEditFunction"));
        XWidgetEditFunction->resize(400, 407);
        vboxLayout = new QVBoxLayout(XWidgetEditFunction);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tabWidget = new QTabWidget(XWidgetEditFunction);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        vboxLayout1 = new QVBoxLayout(tab);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout2 = new QVBoxLayout(groupBox);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout2->addWidget(name);


        vboxLayout1->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        hboxLayout = new QHBoxLayout(groupBox_2);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        currentState = new QLineEdit(groupBox_2);
        currentState->setObjectName(QString::fromUtf8("currentState"));

        hboxLayout->addWidget(currentState);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout->addWidget(label_2);

        nextState = new QLineEdit(groupBox_2);
        nextState->setObjectName(QString::fromUtf8("nextState"));

        hboxLayout->addWidget(nextState);


        vboxLayout1->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout3 = new QVBoxLayout(groupBox_3);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        description = new QsciScintilla(groupBox_3);
        description->setObjectName(QString::fromUtf8("description"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferDefault);
        description->setFont(font);

        vboxLayout3->addWidget(description);


        vboxLayout1->addWidget(groupBox_3);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        vboxLayout4 = new QVBoxLayout(tab_3);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        condition = new QTextEdit(tab_3);
        condition->setObjectName(QString::fromUtf8("condition"));

        vboxLayout4->addWidget(condition);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        vboxLayout5 = new QVBoxLayout(tab_2);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        code = new QTextEdit(tab_2);
        code->setObjectName(QString::fromUtf8("code"));

        vboxLayout5->addWidget(code);

        tabWidget->addTab(tab_2, QString());

        vboxLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(XWidgetEditFunction);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditFunction);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(XWidgetEditFunction);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditFunction)
    {
        XWidgetEditFunction->setWindowTitle(QApplication::translate("XWidgetEditFunction", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditFunction", "Function Name", 0, QApplication::UnicodeUTF8));
        name->setText(QString());
        groupBox_2->setTitle(QApplication::translate("XWidgetEditFunction", "States", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("XWidgetEditFunction", "Current", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("XWidgetEditFunction", "Next", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditFunction", "Function Description", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        description->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        description->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("XWidgetEditFunction", "Function Information", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("XWidgetEditFunction", "Condition", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("XWidgetEditFunction", "Code Implementation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditFunction: public Ui_XWidgetEditFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITFUNCTION_H
