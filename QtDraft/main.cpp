#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QtDraft" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    qApp->setStyle(QStyleFactory::create("DarkFusion"));
    qApp->setWindowIcon(QIcon(":/img/car.png"));

    QPalette dark_palette;

    dark_palette.setColor(QPalette::Link, QColor(220, 120, 60));
    dark_palette.setColor(QPalette::Highlight, QColor(220, 120, 60));
    dark_palette.setColor(QPalette::Accent, QColor(220, 120, 60));

    qApp->setPalette(dark_palette);

    MainWindow w;
    w.show();
    return a.exec();
}
