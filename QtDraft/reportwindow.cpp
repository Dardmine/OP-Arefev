#include "reportwindow.h"
#include "ui_reportwindow.h"
#include <fstream>
#include <QMessageBox>

ReportWindow::ReportWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReportWindow)
{
    ui->setupUi(this);
}

ReportWindow::~ReportWindow()
{
    delete ui;
}

// Получение Данных из Основного окна
void ReportWindow::recieveVector(vector<_Data> dataList, vector<_Data> dataSearch, string line, bool isSorted){
    dataFull = dataList;
    dataSelected = dataSearch;

    if(dataList.empty()){
        ui->fullButton->setDisabled(true);
        ui->lineEdit->setDisabled(true);
    }else{
        ui->fullButton->setDisabled(false);
        ui->lineEdit->setDisabled(false);
        ui->fullButton->setChecked(true);
    }

    if(dataSearch.empty() or (line=="" and !isSorted)){
        ui->selectedButton->setDisabled(true);
    }else{
        ui->selectedButton->setDisabled(false);
    }

    ui->lineEdit->setText("");
}

// Создание Файла
void ReportWindow::FileCreate(vector<_Data> dataList, string name){
    ofstream fout(name+".txt", ios::out);
    if(fout.is_open()){
        for(int i=0; i<dataList.size(); i++){
            string line = dataList[i].getCar().driveGoal + ";  " + dataList[i].getCar().model + ";  " + dataList[i].getCar().transmission + ";  " + to_string(dataList[i].getCar().rate)  + ";  ";
            line += to_string(dataList[i].getStartDate().day) + "." + to_string(dataList[i].getStartDate().month) + "." + to_string(dataList[i].getStartDate().year) + ";  ";
            line += to_string(dataList[i].getEndDate().day) + "." + to_string(dataList[i].getEndDate().month) + "." + to_string(dataList[i].getEndDate().year) + ";  ";

            line += to_string(dataList[i].getCost()) + ";  ";
            line += to_string(dataList[i].getBabyChair());

            fout << line << "\n";
        }
    }else{
        QMessageBox::warning(this, "Ошибка!", "Ошибка при создании файла!");
    }
}

void ReportWindow::on_buttonBox_accepted()
{
    QString line = ui->lineEdit->text();
    if(line == "" or line.contains("*") or line.contains("/") or line.contains("\\") or line.contains("<") or line.contains(">") or line.contains(":") or line.contains("|") or line.contains("?")){
        QMessageBox::warning(this, "Ошибка!", "Некорректное имя файла!");
    }else{
        if(ui->fullButton->isChecked()){
            FileCreate(dataFull, line.toStdString());
        }else{
            FileCreate(dataSelected, line.toStdString());
        }
        QMessageBox::information(this, "Запрос", "Файл успешно создан\n" + line + ".txt");
        ReportWindow::close();
    }
}


void ReportWindow::on_buttonBox_rejected()
{
    ReportWindow::close();
}

