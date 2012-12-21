/********************************************************************************
** Form generated from reading UI file 'XWidgetEditIOMessage.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITIOMESSAGE_H
#define UI_XWIDGETEDITIOMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditIOMessage
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout1;
    QTextEdit *filter;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditIOMessage)
    {
        if (XWidgetEditIOMessage->objectName().isEmpty())
            XWidgetEditIOMessage->setObjectName(QString::fromUtf8("XWidgetEditIOMessage"));
        XWidgetEditIOMessage->resize(400, 251);
        vboxLayout = new QVBoxLayout(XWidgetEditIOMessage);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox_3 = new QGroupBox(XWidgetEditIOMessage);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout1 = new QVBoxLayout(groupBox_3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        filter = new QTextEdit(groupBox_3);
        filter->setObjectName(QString::fromUtf8("filter"));

        vboxLayout1->addWidget(filter);


        vboxLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(XWidgetEditIOMessage);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditIOMessage);

        QMetaObject::connectSlotsByName(XWidgetEditIOMessage);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditIOMessage)
    {
        XWidgetEditIOMessage->setWindowTitle(QApplication::translate("XWidgetEditIOMessage", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditIOMessage", "Filter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditIOMessage: public Ui_XWidgetEditIOMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITIOMESSAGE_H
