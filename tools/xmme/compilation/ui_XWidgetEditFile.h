/********************************************************************************
** Form generated from reading UI file 'XWidgetEditFile.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITFILE_H
#define UI_XWIDGETEDITFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditFile
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout;
    QLineEdit *filePath;
    QPushButton *selectButton;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditFile)
    {
        if (XWidgetEditFile->objectName().isEmpty())
            XWidgetEditFile->setObjectName(QString::fromUtf8("XWidgetEditFile"));
        XWidgetEditFile->resize(387, 130);
        vboxLayout = new QVBoxLayout(XWidgetEditFile);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditFile);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        hboxLayout = new QHBoxLayout(groupBox);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        filePath = new QLineEdit(groupBox);
        filePath->setObjectName(QString::fromUtf8("filePath"));

        hboxLayout->addWidget(filePath);

        selectButton = new QPushButton(groupBox);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        hboxLayout->addWidget(selectButton);


        vboxLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(XWidgetEditFile);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditFile);

        QMetaObject::connectSlotsByName(XWidgetEditFile);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditFile)
    {
        XWidgetEditFile->setWindowTitle(QApplication::translate("XWidgetEditFile", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditFile", "File Path", 0, QApplication::UnicodeUTF8));
        selectButton->setText(QApplication::translate("XWidgetEditFile", "Select File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditFile: public Ui_XWidgetEditFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITFILE_H
