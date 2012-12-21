/********************************************************************************
** Form generated from reading UI file 'XWidgetEditTimeUnit.ui'
**
** Created: Mon Jun 13 15:47:59 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWIDGETEDITTIMEUNIT_H
#define UI_XWIDGETEDITTIMEUNIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWidgetEditTimeUnit
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QLineEdit *name;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout2;
    QLineEdit *unit;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout3;
    QLineEdit *period;
    QDialogButtonBox *buttonBox;
    QSpacerItem *spacerItem;

    void setupUi(QWidget *XWidgetEditTimeUnit)
    {
        if (XWidgetEditTimeUnit->objectName().isEmpty())
            XWidgetEditTimeUnit->setObjectName(QString::fromUtf8("XWidgetEditTimeUnit"));
        XWidgetEditTimeUnit->resize(400, 278);
        vboxLayout = new QVBoxLayout(XWidgetEditTimeUnit);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(XWidgetEditTimeUnit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        name = new QLineEdit(groupBox);
        name->setObjectName(QString::fromUtf8("name"));

        vboxLayout1->addWidget(name);


        vboxLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(XWidgetEditTimeUnit);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout2 = new QVBoxLayout(groupBox_2);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        unit = new QLineEdit(groupBox_2);
        unit->setObjectName(QString::fromUtf8("unit"));

        vboxLayout2->addWidget(unit);


        vboxLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(XWidgetEditTimeUnit);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout3 = new QVBoxLayout(groupBox_3);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        period = new QLineEdit(groupBox_3);
        period->setObjectName(QString::fromUtf8("period"));

        vboxLayout3->addWidget(period);


        vboxLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(XWidgetEditTimeUnit);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        vboxLayout->addWidget(buttonBox);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);


        retranslateUi(XWidgetEditTimeUnit);

        QMetaObject::connectSlotsByName(XWidgetEditTimeUnit);
    } // setupUi

    void retranslateUi(QWidget *XWidgetEditTimeUnit)
    {
        XWidgetEditTimeUnit->setWindowTitle(QApplication::translate("XWidgetEditTimeUnit", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("XWidgetEditTimeUnit", "Time Unit Name", 0, QApplication::UnicodeUTF8));
        name->setText(QString());
        groupBox_2->setTitle(QApplication::translate("XWidgetEditTimeUnit", "Time Unit ", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("XWidgetEditTimeUnit", "Time Unit Period", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XWidgetEditTimeUnit: public Ui_XWidgetEditTimeUnit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWIDGETEDITTIMEUNIT_H
