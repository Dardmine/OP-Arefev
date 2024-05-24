/********************************************************************************
** Form generated from reading UI file 'addorderwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDORDERWINDOW_H
#define UI_ADDORDERWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddOrderWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *reason;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *model;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *transmition;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QCalendarWidget *startDate;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QCalendarWidget *endDate;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *rateLine;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QCheckBox *haveBabyChair;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLineEdit *costLine;

    void setupUi(QDialog *AddOrderWindow)
    {
        if (AddOrderWindow->objectName().isEmpty())
            AddOrderWindow->setObjectName("AddOrderWindow");
        AddOrderWindow->resize(820, 532);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AddOrderWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(AddOrderWindow);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddOrderWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(AddOrderWindow);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        reason = new QComboBox(AddOrderWindow);
        reason->addItem(QString());
        reason->addItem(QString());
        reason->addItem(QString());
        reason->addItem(QString());
        reason->setObjectName("reason");
        reason->setEditable(false);

        horizontalLayout->addWidget(reason);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(AddOrderWindow);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        model = new QComboBox(AddOrderWindow);
        model->setObjectName("model");

        horizontalLayout_2->addWidget(model);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(AddOrderWindow);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        transmition = new QComboBox(AddOrderWindow);
        transmition->setObjectName("transmition");

        horizontalLayout_3->addWidget(transmition);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_6 = new QLabel(AddOrderWindow);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        startDate = new QCalendarWidget(AddOrderWindow);
        startDate->setObjectName("startDate");
        startDate->setCursor(QCursor(Qt::PointingHandCursor));
        startDate->setLayoutDirection(Qt::LeftToRight);
        startDate->setSelectedDate(QDate(2024, 5, 18));
        startDate->setDateEditEnabled(true);

        verticalLayout->addWidget(startDate);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_10 = new QLabel(AddOrderWindow);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        endDate = new QCalendarWidget(AddOrderWindow);
        endDate->setObjectName("endDate");
        endDate->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(endDate);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_5 = new QLabel(AddOrderWindow);
        label_5->setObjectName("label_5");

        horizontalLayout_9->addWidget(label_5);

        rateLine = new QLineEdit(AddOrderWindow);
        rateLine->setObjectName("rateLine");
        rateLine->setEnabled(false);

        horizontalLayout_9->addWidget(rateLine);

        label_7 = new QLabel(AddOrderWindow);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_9, 5, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddOrderWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setMouseTracking(false);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_9 = new QLabel(AddOrderWindow);
        label_9->setObjectName("label_9");

        horizontalLayout_6->addWidget(label_9);

        haveBabyChair = new QCheckBox(AddOrderWindow);
        haveBabyChair->setObjectName("haveBabyChair");

        horizontalLayout_6->addWidget(haveBabyChair);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_8 = new QLabel(AddOrderWindow);
        label_8->setObjectName("label_8");

        horizontalLayout_6->addWidget(label_8);

        costLine = new QLineEdit(AddOrderWindow);
        costLine->setObjectName("costLine");
        costLine->setEnabled(false);

        horizontalLayout_6->addWidget(costLine);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 2);


        retranslateUi(AddOrderWindow);

        reason->setCurrentIndex(-1);
        transmition->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(AddOrderWindow);
    } // setupUi

    void retranslateUi(QDialog *AddOrderWindow)
    {
        AddOrderWindow->setWindowTitle(QCoreApplication::translate("AddOrderWindow", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label->setText(QCoreApplication::translate("AddOrderWindow", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AddOrderWindow", "\320\246\320\265\320\273\321\214 \320\277\320\276\320\265\320\267\320\264\320\272\320\270", nullptr));
        reason->setItemText(0, QCoreApplication::translate("AddOrderWindow", "\320\221\320\270\320\267\320\275\320\265\321\201", nullptr));
        reason->setItemText(1, QCoreApplication::translate("AddOrderWindow", "\320\232\320\276\320\274\321\204\320\276\321\200\321\202", nullptr));
        reason->setItemText(2, QCoreApplication::translate("AddOrderWindow", "\320\234\320\270\320\275\320\270\320\262\320\265\320\275", nullptr));
        reason->setItemText(3, QCoreApplication::translate("AddOrderWindow", "\320\255\320\272\320\276\320\275\320\276\320\274", nullptr));

        reason->setCurrentText(QString());
        reason->setPlaceholderText(QCoreApplication::translate("AddOrderWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\206\320\265\320\273\321\214:", nullptr));
        label_3->setText(QCoreApplication::translate("AddOrderWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        model->setPlaceholderText(QCoreApplication::translate("AddOrderWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\276\320\264\320\265\320\273\321\214:", nullptr));
        label_4->setText(QCoreApplication::translate("AddOrderWindow", "\320\232\320\276\321\200\320\276\320\261\320\272\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\207", nullptr));
        transmition->setPlaceholderText(QCoreApplication::translate("AddOrderWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\232\320\237\320\237:", nullptr));
        label_6->setText(QCoreApplication::translate("AddOrderWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260 \320\260\321\200\320\265\320\275\320\264\321\213:", nullptr));
        label_10->setText(QCoreApplication::translate("AddOrderWindow", "\320\224\320\260\321\202\320\260 \320\272\320\276\320\275\321\206\320\260 \320\260\321\200\320\265\320\275\320\264\321\213:", nullptr));
        label_5->setText(QCoreApplication::translate("AddOrderWindow", "\320\242\320\260\321\200\320\270\321\204", nullptr));
        label_7->setText(QCoreApplication::translate("AddOrderWindow", "\321\200\321\203\320\261./\321\201\321\203\321\202.", nullptr));
        label_9->setText(QCoreApplication::translate("AddOrderWindow", "\320\224\320\265\321\202\321\201\320\272\320\276\320\265 \320\272\321\200\320\265\321\201\320\273\320\276", nullptr));
        haveBabyChair->setText(QCoreApplication::translate("AddOrderWindow", "\320\235\321\203\320\266\320\275\320\276", nullptr));
        label_8->setText(QCoreApplication::translate("AddOrderWindow", "\320\246\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddOrderWindow: public Ui_AddOrderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDORDERWINDOW_H
