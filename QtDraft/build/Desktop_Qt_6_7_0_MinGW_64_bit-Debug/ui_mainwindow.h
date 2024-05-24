/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openFile;
    QAction *saveFile;
    QAction *report;
    QAction *diagram;
    QAction *sorting_model_AZ;
    QAction *sorting_model_ZA;
    QAction *actionAZ_2;
    QAction *actionZA_2;
    QAction *sorting_startDate_AZ;
    QAction *sorting_startDate_ZA;
    QAction *sorting_default;
    QAction *sorting_endDate_AZ;
    QAction *sorting_endDate_ZA;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *closeButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QCommandLinkButton *commandLinkButton;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxSearch;
    QLineEdit *SearchLine;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *deleteButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_6;
    QMenu *menu_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/car.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        openFile = new QAction(MainWindow);
        openFile->setObjectName("openFile");
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName("saveFile");
        report = new QAction(MainWindow);
        report->setObjectName("report");
        diagram = new QAction(MainWindow);
        diagram->setObjectName("diagram");
        sorting_model_AZ = new QAction(MainWindow);
        sorting_model_AZ->setObjectName("sorting_model_AZ");
        sorting_model_ZA = new QAction(MainWindow);
        sorting_model_ZA->setObjectName("sorting_model_ZA");
        actionAZ_2 = new QAction(MainWindow);
        actionAZ_2->setObjectName("actionAZ_2");
        actionZA_2 = new QAction(MainWindow);
        actionZA_2->setObjectName("actionZA_2");
        sorting_startDate_AZ = new QAction(MainWindow);
        sorting_startDate_AZ->setObjectName("sorting_startDate_AZ");
        sorting_startDate_ZA = new QAction(MainWindow);
        sorting_startDate_ZA->setObjectName("sorting_startDate_ZA");
        sorting_default = new QAction(MainWindow);
        sorting_default->setObjectName("sorting_default");
        sorting_endDate_AZ = new QAction(MainWindow);
        sorting_endDate_AZ->setObjectName("sorting_endDate_AZ");
        sorting_endDate_ZA = new QAction(MainWindow);
        sorting_endDate_ZA->setObjectName("sorting_endDate_ZA");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");

        horizontalLayout_4->addWidget(closeButton);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName("commandLinkButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon1);

        horizontalLayout_3->addWidget(commandLinkButton);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));

        horizontalLayout->addWidget(label);

        comboBoxSearch = new QComboBox(centralwidget);
        comboBoxSearch->addItem(QString());
        comboBoxSearch->addItem(QString());
        comboBoxSearch->addItem(QString());
        comboBoxSearch->addItem(QString());
        comboBoxSearch->setObjectName("comboBoxSearch");

        horizontalLayout->addWidget(comboBoxSearch);

        SearchLine = new QLineEdit(centralwidget);
        SearchLine->setObjectName("SearchLine");
        SearchLine->setEnabled(false);

        horizontalLayout->addWidget(SearchLine);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_2->addWidget(deleteButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setLineWidth(2);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setProperty("showDropIndicator", QVariant(false));
        tableView->setDragDropOverwriteMode(false);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setTextElideMode(Qt::ElideRight);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setWordWrap(false);

        gridLayout->addWidget(tableView, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menu);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menu);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName("menu_4");
        menu_6 = new QMenu(menu_3);
        menu_6->setObjectName("menu_6");
        menu_7 = new QMenu(menu_3);
        menu_7->setObjectName("menu_7");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(openFile);
        menu->addAction(saveFile);
        menu->addSeparator();
        menu->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu_2->addAction(report);
        menu_2->addAction(diagram);
        menu_3->addAction(menu_4->menuAction());
        menu_3->addAction(menu_6->menuAction());
        menu_3->addAction(menu_7->menuAction());
        menu_3->addAction(sorting_default);
        menu_4->addAction(sorting_model_AZ);
        menu_4->addAction(sorting_model_ZA);
        menu_6->addAction(sorting_startDate_AZ);
        menu_6->addAction(sorting_startDate_ZA);
        menu_7->addAction(sorting_endDate_AZ);
        menu_7->addAction(sorting_endDate_ZA);

        retranslateUi(MainWindow);

        comboBoxSearch->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\220\321\200\320\265\320\275\320\264\320\260 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        report->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\267\320\260\320\277\321\200\320\276\321\201\321\203", nullptr));
        diagram->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        sorting_model_AZ->setText(QCoreApplication::translate("MainWindow", "AZ", nullptr));
        sorting_model_ZA->setText(QCoreApplication::translate("MainWindow", "ZA", nullptr));
        actionAZ_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        actionZA_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));
        sorting_startDate_AZ->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        sorting_startDate_ZA->setText(QCoreApplication::translate("MainWindow", " \320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));
        sorting_default->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        sorting_endDate_AZ->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        sorting_endDate_ZA->setText(QCoreApplication::translate("MainWindow", " \320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\220\321\200\320\265\320\275\320\264\320\260 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\265\320\271", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\267\320\260\320\272\320\260\320\267\320\260 \320\277\320\276:", nullptr));
        comboBoxSearch->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\321\214 \320\277\320\276\320\265\320\267\320\264\320\272\320\270", nullptr));
        comboBoxSearch->setItemText(1, QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        comboBoxSearch->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\276\320\261\320\272\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\207", nullptr));
        comboBoxSearch->setItemText(3, QCoreApplication::translate("MainWindow", "\320\224\320\265\321\202\321\201\320\272\320\276\320\265 \320\272\321\200\320\265\321\201\320\273\320\276", nullptr));

        comboBoxSearch->setCurrentText(QString());
        comboBoxSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\273\321\216\321\207 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\321\221\321\202", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 ...", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\200\320\272\320\260", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260 \320\260\321\200\320\265\320\275\320\264\321\213", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\272\320\276\320\275\321\206\320\260 \320\260\321\200\320\265\320\275\320\264\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
