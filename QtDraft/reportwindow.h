#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>
#include "data.h"
#include <vector>
using namespace std;


namespace Ui {
class ReportWindow;
}

class ReportWindow : public QDialog
{
    Q_OBJECT

public slots:
    void recieveVector(vector<_Data> dataList, vector<_Data> dataSearch, string line, bool isSorted);

public:
    explicit ReportWindow(QWidget *parent = nullptr);
    ~ReportWindow();

    vector<_Data> dataFull;
    vector<_Data> dataSelected;

private slots:
    void FileCreate(vector<_Data> dataList, string name);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ReportWindow *ui;
};

#endif // REPORTWINDOW_H
