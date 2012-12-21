/********************************************************************************
** Form generated from reading UI file 'XWidgetEditFunctionInMessages.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITFUNCTIONINMESSAGES_H
#define UI_XWIDGETEDITFUNCTIONINMESSAGES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditFunctionInMessages
{
public:
    QVBoxLayout *vboxLayout;
    QListWidget *messagesList;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditFunctionInMessages)
    {
        if (XWidgetEditFunctionInMessages->objectName().isEmpty())
            XWidgetEditFunctionInMessages->setObjectName(QString::fromUtf8("XWidgetEditFunctionInMessages"));
        XWidgetEditFunctionInMessages->resize(400, 373);
        vboxLayout = new QVBoxLayout(XWidgetEditFunctionInMessages);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        messagesList = new QListWidget(XWidgetEditFunctionInMessages);
        messagesList->setObjectName(QString::fromUtf8("messagesList"));

        vboxLayout->addWidget(messagesList);

        buttonBox = new QDialogButtonBox(XWidgetEditFunctionInMessages);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditFunctionInMessages);

        QMetaObject::connectSlotsByName(XWidgetEditFunctionInMessages);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditFunctionInMessages)
    {
        XWidgetEditFunctionInMessages->setWindowTitle(QApplication::translate("XWidgetEditFunctionInMessages", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditFunctionInMessages: public Ui_XWidgetEditFunctionInMessages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITFUNCTIONINMESSAGES_H
