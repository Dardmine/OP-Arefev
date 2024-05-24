/********************************************************************************
** Form generated from reading UI file 'diagram.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAM_H
#define UI_DIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diagram
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *Diagram)
    {
        if (Diagram->objectName().isEmpty())
            Diagram->setObjectName("Diagram");
        Diagram->resize(900, 600);
        horizontalLayoutWidget = new QWidget(Diagram);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 881, 581));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Diagram);

        QMetaObject::connectSlotsByName(Diagram);
    } // setupUi

    void retranslateUi(QDialog *Diagram)
    {
        Diagram->setWindowTitle(QCoreApplication::translate("Diagram", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diagram: public Ui_Diagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAM_H
