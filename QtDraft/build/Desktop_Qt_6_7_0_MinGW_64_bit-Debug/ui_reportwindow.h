/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReportWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *fullButton;
    QRadioButton *selectedButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ReportWindow)
    {
        if (ReportWindow->objectName().isEmpty())
            ReportWindow->setObjectName("ReportWindow");
        ReportWindow->resize(490, 121);
        gridLayout = new QGridLayout(ReportWindow);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ReportWindow);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(ReportWindow);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        fullButton = new QRadioButton(ReportWindow);
        fullButton->setObjectName("fullButton");

        verticalLayout_2->addWidget(fullButton);

        selectedButton = new QRadioButton(ReportWindow);
        selectedButton->setObjectName("selectedButton");

        verticalLayout_2->addWidget(selectedButton);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ReportWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(ReportWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ReportWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ReportWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ReportWindow);
    } // setupUi

    void retranslateUi(QDialog *ReportWindow)
    {
        ReportWindow->setWindowTitle(QCoreApplication::translate("ReportWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ReportWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        fullButton->setText(QCoreApplication::translate("ReportWindow", "\320\222\321\201\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        selectedButton->setText(QCoreApplication::translate("ReportWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\320\274\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWindow: public Ui_ReportWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
