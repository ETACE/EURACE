/********************************************************************************
** Form generated from reading UI file 'XWidgetEditModel.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITMODEL_H
#define UI_XWIDGETEDITMODEL_H

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
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditModel
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QLineEdit *name;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *version;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout3;
    QTextEdit *description;
    QGroupBox *groupBox_4;
    QHBoxLayout *hboxLayout;
    QLineEdit *filePath;
    QPushButton *selectButton;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditModel)
    {
        if (XWidgetEditModel->objectName().isEmpty())
            XWidgetEditModel->setObjectName(QString::fromUtf8("XWidgetEditModel"));
        XWidgetEditModel->resize(400, 399);
        vboxLayout = new QVBoxLayout(XWidgetEditModel);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditModel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout1->addWidget(name);


        vboxLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(XWidgetEditModel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout2 = new QVBoxLayout(groupBox_2);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        version = new QLineEdit(groupBox_2);
        version->setObjectName(QString::fromUtf8("version"));

        vboxLayout2->addWidget(version);


        vboxLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(XWidgetEditModel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout3 = new QVBoxLayout(groupBox_3);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        description = new QTextEdit(groupBox_3);
        description->setObjectName(QString::fromUtf8("description"));

        vboxLayout3->addWidget(description);


        vboxLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(XWidgetEditModel);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        hboxLayout = new QHBoxLayout(groupBox_4);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        filePath = new QLineEdit(groupBox_4);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setReadOnly(true);

        hboxLayout->addWidget(filePath);

        selectButton = new QPushButton(groupBox_4);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setEnabled(false);

        hboxLayout->addWidget(selectButton);


        vboxLayout->addWidget(groupBox_4);

        buttonBox = new QDialogButtonBox(XWidgetEditModel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(382, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditModel);

        QMetaObject::connectSlotsByName(XWidgetEditModel);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditModel)
    {
        XWidgetEditModel->setWindowTitle(QApplication::translate("XWidgetEditModel", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditModel", "Model Name", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("XWidgetEditModel", "Model Version", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditModel", "Model Description", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("XWidgetEditModel", "File Path", 0, QApplication::UnicodeUTF8));
        selectButton->setText(QApplication::translate("XWidgetEditModel", "Select File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditModel: public Ui_XWidgetEditModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITMODEL_H
