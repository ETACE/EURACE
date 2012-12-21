/********************************************************************************
** Form generated from reading UI file 'XWidgetEditAgent.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITAGENT_H
#define UI_XWIDGETEDITAGENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditAgent
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QLineEdit *name;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout2;
    QTextEdit *description;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditAgent)
    {
        if (XWidgetEditAgent->objectName().isEmpty())
            XWidgetEditAgent->setObjectName(QString::fromUtf8("XWidgetEditAgent"));
        XWidgetEditAgent->resize(400, 251);
        vboxLayout = new QVBoxLayout(XWidgetEditAgent);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditAgent);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout1->addWidget(name);


        vboxLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(XWidgetEditAgent);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout2 = new QVBoxLayout(groupBox_3);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        description = new QTextEdit(groupBox_3);
        description->setObjectName(QString::fromUtf8("description"));

        vboxLayout2->addWidget(description);


        vboxLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(XWidgetEditAgent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditAgent);

        QMetaObject::connectSlotsByName(XWidgetEditAgent);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditAgent)
    {
        XWidgetEditAgent->setWindowTitle(QApplication::translate("XWidgetEditAgent", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditAgent", "Agent Type Name", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditAgent", "Agent Type Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditAgent: public Ui_XWidgetEditAgent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITAGENT_H
