/********************************************************************************
** Form generated from reading UI file 'XWidgetEditDataType.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITDATATYPE_H
#define UI_XWIDGETEDITDATATYPE_H

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

class Ui_XWidgetEditDataType
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

    void setupUi(QWidget *XWidgetEditDataType)
    {
        if (XWidgetEditDataType->objectName().isEmpty())
            XWidgetEditDataType->setObjectName(QString::fromUtf8("XWidgetEditDataType"));
        XWidgetEditDataType->resize(400, 251);
        vboxLayout = new QVBoxLayout(XWidgetEditDataType);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditDataType);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout1->addWidget(name);


        vboxLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(XWidgetEditDataType);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout2 = new QVBoxLayout(groupBox_3);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        description = new QTextEdit(groupBox_3);
        description->setObjectName(QString::fromUtf8("description"));

        vboxLayout2->addWidget(description);


        vboxLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(XWidgetEditDataType);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditDataType);

        QMetaObject::connectSlotsByName(XWidgetEditDataType);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditDataType)
    {
        XWidgetEditDataType->setWindowTitle(QApplication::translate("XWidgetEditDataType", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditDataType", "Data Type Name", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditDataType", "Data Type Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditDataType: public Ui_XWidgetEditDataType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITDATATYPE_H
