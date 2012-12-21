/********************************************************************************
** Form generated from reading UI file 'XWidgetEditVariable.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITVARIABLE_H
#define UI_XWIDGETEDITVARIABLE_H

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

class Ui_XWidgetEditVariable
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QLineEdit *type;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *name;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout3;
    QTextEdit *description;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditVariable)
    {
        if (XWidgetEditVariable->objectName().isEmpty())
            XWidgetEditVariable->setObjectName(QString::fromUtf8("XWidgetEditVariable"));
        XWidgetEditVariable->resize(400, 357);
        vboxLayout = new QVBoxLayout(XWidgetEditVariable);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditVariable);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        type = new QLineEdit(groupBox);
        type->setObjectName(QString::fromUtf8("type"));

        vboxLayout1->addWidget(type);


        vboxLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(XWidgetEditVariable);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout2 = new QVBoxLayout(groupBox_2);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        name = new QLineEdit(groupBox_2);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout2->addWidget(name);


        vboxLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(XWidgetEditVariable);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout3 = new QVBoxLayout(groupBox_3);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        description = new QTextEdit(groupBox_3);
        description->setObjectName(QString::fromUtf8("description"));

        vboxLayout3->addWidget(description);


        vboxLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(XWidgetEditVariable);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditVariable);

        QMetaObject::connectSlotsByName(XWidgetEditVariable);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditVariable)
    {
        XWidgetEditVariable->setWindowTitle(QApplication::translate("XWidgetEditVariable", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditVariable", "Variable Type", 0, QApplication::UnicodeUTF8));
        type->setText(QString());
        groupBox_2->setTitle(QApplication::translate("XWidgetEditVariable", "Variable Name", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditVariable", "Variable Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditVariable: public Ui_XWidgetEditVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITVARIABLE_H
