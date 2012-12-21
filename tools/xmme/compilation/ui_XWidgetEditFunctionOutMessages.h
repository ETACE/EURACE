/********************************************************************************
** Form generated from reading UI file 'XWidgetEditFunctionOutMessages.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITFUNCTIONOUTMESSAGES_H
#define UI_XWIDGETEDITFUNCTIONOUTMESSAGES_H

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

class Ui_XWidgetEditFunctionOutMessages
{
public:
    QVBoxLayout *vboxLayout;
    QListWidget *messagesList;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditFunctionOutMessages)
    {
        if (XWidgetEditFunctionOutMessages->objectName().isEmpty())
            XWidgetEditFunctionOutMessages->setObjectName(QString::fromUtf8("XWidgetEditFunctionOutMessages"));
        XWidgetEditFunctionOutMessages->resize(400, 373);
        vboxLayout = new QVBoxLayout(XWidgetEditFunctionOutMessages);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        messagesList = new QListWidget(XWidgetEditFunctionOutMessages);
        messagesList->setObjectName(QString::fromUtf8("messagesList"));

        vboxLayout->addWidget(messagesList);

        buttonBox = new QDialogButtonBox(XWidgetEditFunctionOutMessages);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditFunctionOutMessages);

        QMetaObject::connectSlotsByName(XWidgetEditFunctionOutMessages);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditFunctionOutMessages)
    {
        XWidgetEditFunctionOutMessages->setWindowTitle(QApplication::translate("XWidgetEditFunctionOutMessages", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditFunctionOutMessages: public Ui_XWidgetEditFunctionOutMessages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITFUNCTIONOUTMESSAGES_H
