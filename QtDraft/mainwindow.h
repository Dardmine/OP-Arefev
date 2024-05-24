#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "addorderwindow.h"
#include "data.h"
#include "diagram.h"
#include "reportwindow.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendSelectedData(_Data data);
    void sendVector(vector<_Data> dataList, vector<_Data> dataSearch, string line, bool isSorted);
    void sendDiagramVector(vector<_Data> dataList);

public slots:
    void recieveData(_Data data);
    void recieveEditedData(_Data data);

private slots:
    void TableLoad(vector<_Data> data);

    void on_commandLinkButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_openFile_triggered();

    void searching();

    void on_SearchLine_textChanged(const QString &arg1);

    void on_saveFile_triggered();

    void closeEvent(QCloseEvent *event);

    void on_sorting_default_triggered();

    void on_sorting_model_AZ_triggered();

    void on_sorting_model_ZA_triggered();

    void on_sorting_startDate_AZ_triggered();

    void on_sorting_startDate_ZA_triggered();

    void on_sorting_endDate_AZ_triggered();

    void on_sorting_endDate_ZA_triggered();

    void on_deleteButton_clicked();

    void on_closeButton_clicked();

    void on_diagram_triggered();

    void on_report_triggered();

    void on_comboBoxSearch_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    AddOrderWindow* ptrAdd{};
    Diagram* ptrDiagram{};
    ReportWindow* ptrReport{};

};
#endif // MAINWINDOW_H
