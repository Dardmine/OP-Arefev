#ifndef ADDORDERWINDOW_H
#define ADDORDERWINDOW_H

#include <QDialog>
#include "data.h"


namespace Ui {
class AddOrderWindow;
}

class AddOrderWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrderWindow(QWidget *parent = nullptr);
    ~AddOrderWindow();

signals:
    void sendData(_Data data);

private slots:

    void clearInputData();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    //void on_reason_currentIndexChanged(int index);

    //void on_model_currentIndexChanged(int index);

    void on_rateLine_textChanged(const QString &arg1);

    void on_startDate_clicked(const QDate &date);

    void on_reason_currentTextChanged(const QString &arg1);

    void on_model_currentTextChanged(const QString &arg1);

    //void on_transmition_currentIndexChanged(int index);

    void on_transmition_currentTextChanged(const QString &arg1);

    void on_endDate_clicked(const QDate &date);

    void on_startDate_selectionChanged();

    void on_endDate_selectionChanged();



private:
    Ui::AddOrderWindow *ui;
};

#endif // ADDORDERWINDOW_H
