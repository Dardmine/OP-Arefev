#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addorderwindow.h"
#include "QMessageBox"
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>
#include <QCloseEvent>
#include "QString"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int indexCurrent ={-1};
bool isSaved = {true};
bool isSorted = {false};
bool closeButtonIsPressed {};
vector<_Data> dataList;
vector<_Data> dataSearch;
vector<string> carList;

// Сохранение Бинарного Файла
void FileSave() {
    ofstream fout("data.bin", ios::binary);
    if (fout.is_open()) {
        for (int i = 0; i < dataList.size(); i++) {
            Car car = dataList[i].getCar();
            StartDate startDate = dataList[i].getStartDate();
            EndDate endDate = dataList[i].getEndDate();
            double cost = dataList[i].getCost();
            bool babyChair = dataList[i].getBabyChair();

            unsigned strLen = car.driveGoal.size();
            fout.write((char*)&strLen, sizeof(unsigned));
            fout.write((char*)car.driveGoal.c_str(), car.driveGoal.size());

            strLen = car.model.size();
            fout.write((char*)&strLen, sizeof(unsigned));
            fout.write((char*)car.model.c_str(), car.model.size());

            strLen = car.transmission.size();
            fout.write((char*)&strLen, sizeof(unsigned));
            fout.write((char*)car.transmission.c_str(), car.transmission.size());

            fout.write((char*)&car.rate, sizeof(float));

            fout.write((char*)&startDate.day, sizeof(int));
            fout.write((char*)&startDate.month, sizeof(int));
            fout.write((char*)&startDate.year, sizeof(int));

            fout.write((char*)&endDate.day, sizeof(int));
            fout.write((char*)&endDate.month, sizeof(int));
            fout.write((char*)&endDate.year, sizeof(int));

            fout.write((char*)&cost, sizeof(double));

            fout.write((char*)&babyChair, sizeof(bool));
        }
    }
    fout.close();
    isSaved = true;
}

// Загрузка Бинарного Файла
void FileLoad() {
    dataList.clear();
    ifstream fin("data.bin", ios::binary);
    if (fin.is_open()) {
        Car car;
        StartDate startDate;
        EndDate endDate;
        double cost;
        bool babyChair;

        unsigned strLen{};

        while (fin.read((char*)&strLen, sizeof(unsigned))) {
            car.driveGoal.resize(strLen);
            fin.read((char*)car.driveGoal.data(), strLen);

            fin.read((char*)&strLen, sizeof(unsigned));
            car.model.resize(strLen);
            fin.read((char*)car.model.data(), strLen);

            fin.read((char*)&strLen, sizeof(unsigned));
            car.transmission.resize(strLen);
            fin.read((char*)car.transmission.data(), strLen);

            fin.read((char*)&car.rate, sizeof(float));

            fin.read((char*)&startDate.day, sizeof(int));
            fin.read((char*)&startDate.month, sizeof(int));
            fin.read((char*)&startDate.year, sizeof(int));

            fin.read((char*)&endDate.day, sizeof(int));
            fin.read((char*)&endDate.month, sizeof(int));
            fin.read((char*)&endDate.year, sizeof(int));

            fin.read((char*)&cost, sizeof(double));

            fin.read((char*)&babyChair, sizeof(bool));

            _Data data(car, startDate, endDate, cost, babyChair);
            dataList.push_back(data);
        }
    }
    fin.close();
    isSaved = true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TableLoad(dataList);

    ptrAdd = new AddOrderWindow;
    ptrReport = new ReportWindow;
    ptrDiagram = new Diagram;

    connect(ptrAdd, &AddOrderWindow::sendData, this, &MainWindow::recieveData);
    connect(this, &MainWindow::sendVector, ptrReport, &ReportWindow::recieveVector);
    connect(this, &MainWindow::sendDiagramVector, ptrDiagram, &Diagram::recieveDiagramVector);
}

// Открытие окна "Добавить заказ"
void MainWindow::on_commandLinkButton_clicked()
{
    ptrAdd->setWindowTitle("Добавление заказа");
    ptrAdd->setWindowIcon(QIcon(":/img/car.png"));
    ptrAdd->exec();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieveData(_Data data)
{
    dataList.push_back(data);
    searching();
    isSaved = false;
}

void MainWindow::recieveEditedData(_Data data)
{
    dataList[indexCurrent].setCar(data.getCar());
    dataList[indexCurrent].setStartDate(data.getStartDate());
    dataList[indexCurrent].setEndDate(data.getEndDate());
    dataList[indexCurrent].setCost(data.getCost());
    dataList[indexCurrent].setBabyChair(data.getBabyChair());

    searching();
    isSaved = false;
}

// Установка Заголовка Таблицы
void TableHeader(QStandardItemModel *model){
    model->setHeaderData(0, Qt::Horizontal, "Цель поездки");
    model->setHeaderData(1, Qt::Horizontal, "Марка");
    model->setHeaderData(2, Qt::Horizontal, "КПП");
    model->setHeaderData(3, Qt::Horizontal, "Тариф");
    model->setHeaderData(4, Qt::Horizontal, "Дата начала");
    model->setHeaderData(5, Qt::Horizontal, "Дата конца");
    model->setHeaderData(6, Qt::Horizontal, "Цена");
    model->setHeaderData(7, Qt::Horizontal, "Детское кресло");
}

// Загрузка Таблицы
void MainWindow::TableLoad(vector<_Data> data){
    // Определяем Данные для таблицы
    QStandardItemModel* model=  new QStandardItemModel(data.size(), 7);
    for(int i=0; i<data.size(); i++){
        model->setItem(i, 0, new QStandardItem(data[i].getCar().driveGoal.c_str()));
        model->setItem(i, 1, new QStandardItem(data[i].getCar().model.c_str()));
        model->setItem(i, 2, new QStandardItem(data[i].getCar().transmission.c_str()));


        QString startDate = QString::fromStdString(to_string(data[i].getStartDate().day) + "." + to_string(data[i].getStartDate().month) + "." + to_string(data[i].getStartDate().year));
        model->setItem(i, 4, new QStandardItem(startDate));

        QString endDate = QString::fromStdString(to_string(data[i].getEndDate().day) + "." + to_string(data[i].getEndDate().month) + "." + to_string(data[i].getEndDate().year));
        model->setItem(i, 5, new QStandardItem(endDate));

        QString rate = QString::number(data[i].getCar().rate, 'f', 2);
        model->setItem(i, 3, new QStandardItem(rate));

        QString cost = QString::number(data[i].getCost(), 'f', 2);
        model->setItem(i, 6, new QStandardItem(cost));

        QString babyChair = QString::fromStdString(to_string(data[i].getBabyChair()));
        model->setItem(i, 7, new QStandardItem(babyChair));

        ui->tableView ->horizontalHeader()->resizeSection(0,100);
        ui->tableView ->horizontalHeader()->resizeSection(1,100);
        ui->tableView ->horizontalHeader()->resizeSection(2,100);
        ui->tableView ->horizontalHeader()->resizeSection(3,100);
        ui->tableView ->horizontalHeader()->resizeSection(4,218);
        ui->tableView ->horizontalHeader()->resizeSection(5,218);
        ui->tableView ->horizontalHeader()->resizeSection(6,164);
        ui->tableView ->horizontalHeader()->setSectionResizeMode (QHeaderView::ResizeMode());
    }

    // Установка Заголовка
    TableHeader(model);

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->setStyleSheet( "QTableView { gridline-color: Orange; }" );

    ui->deleteButton->setEnabled(false);
}

// Выделение Записи
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int indexTemp = index.row();
    if(ui->SearchLine->text() == "" and !isSorted){
        indexCurrent = indexTemp;
    }else{
        for(int i=0; i<dataList.size(); i++){
            if(dataList[i] == dataSearch[indexTemp]){
                indexCurrent = i;
                break;
            }
        }
    }

    ui->deleteButton->setEnabled(true);
}

// Поиск
void MainWindow::searching(){
    dataSearch.clear();

    switch (ui->comboBoxSearch->currentIndex()) {
    case 0: {
        QString goal = ui->SearchLine->text();
        for (int i = 0; i < dataList.size(); i++) {
            QString goalI = QString::fromStdString(dataList[i].getCar().driveGoal);
            if (goalI.contains(goal, Qt::CaseInsensitive) == true) {
                dataSearch.push_back(dataList[i]);
            }
        }
        break;
    }
    case 1:
    {
        QString model = ui->SearchLine->text();
        for (int i = 0; i < dataList.size(); i++) {
            QString modelI = QString::fromStdString(dataList[i].getCar().model);
            if (modelI.contains(model, Qt::CaseInsensitive) == true) {
                dataSearch.push_back(dataList[i]);
            }
        }
        break;
    }
    case 2:
    {
        QString transmission = ui->SearchLine->text();
        for (int i = 0; i < dataList.size(); i++) {
            QString transmissionI = QString::fromStdString(dataList[i].getCar().transmission);
            if (transmissionI.contains(transmission, Qt::CaseInsensitive) == true) {
                dataSearch.push_back(dataList[i]);
            }
        }
        break;
    }

    case 3:{
        QString babyChair = ui->SearchLine->text();
        for (int i = 0; i < dataList.size(); i++) {
            QString babyChairI = QString::fromStdString(to_string(dataList[i].getBabyChair()));
            if (babyChairI.contains(babyChair, Qt::CaseInsensitive) == true) {
                dataSearch.push_back(dataList[i]);
            }
        }
        break;
    }
    default:
        QString model = ui->SearchLine->text();
        for (int i = 0; i < dataList.size(); i++) {
            QString modelI = QString::fromStdString(dataList[i].getCar().model);
            if (modelI.contains(model, Qt::CaseInsensitive) == true) {
                dataSearch.push_back(dataList[i]);
            }
        }
        break;
    }

    TableLoad(dataSearch);
}

void MainWindow::on_SearchLine_textChanged(const QString &arg1)
{
    searching();
    isSorted = false;
}

// Кнопка "Закрыть"
void MainWindow::on_closeButton_clicked()
{
    closeButtonIsPressed =true;
    if (isSaved == false){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Сохранить изменения в таблице?", QMessageBox::Yes | QMessageBox::No);
        // if ::YES - сохранить
        if (reply == QMessageBox::Yes){
            FileSave();
            QApplication::quit();
        } else QApplication::quit();
    }else QApplication::quit();
}


// Закрытие на "крестик"
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!isSaved && !isSorted && !closeButtonIsPressed){
        event->ignore();
        if (QMessageBox::Yes == QMessageBox::question(this, "Сохранение", "Вы хотите сохранить изменения перед выходом?", QMessageBox::Yes | QMessageBox::No))
        {
            FileSave();
        }
        event->accept();
    }
}

// "Открыть" в меню
void MainWindow::on_openFile_triggered()
{
    FileLoad();
    ui->SearchLine->setText("");
    TableLoad(dataList);
}

// "Сохранить" в меню
void MainWindow::on_saveFile_triggered()
{
    if(dataList.empty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите сохранить пустой файл?", QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            FileSave();
        }
    }else{
        FileSave();
    }
    isSaved = true;
}

// Сортировка по умолчанию
void MainWindow::on_sorting_default_triggered()
{
    if(ui->SearchLine->text() != ""){
        TableLoad(dataSearch);
    }else{
        TableLoad(dataList);
    }

    isSorted=false;
}

// Сортировка модели по возрастанию (алфавиту)
void MainWindow::on_sorting_model_AZ_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if (dataSearch[j].getCar().model.compare( dataSearch[j + 1].getCar().model ) > 0) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted=true;
}

// Сортировка модели по убыванию (алфавита)
void MainWindow::on_sorting_model_ZA_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if (dataSearch[j].getCar().model.compare(dataSearch[j + 1].getCar().model) < 0) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted = true;
}

// Сортировка даты начала по возрастанию
void MainWindow::on_sorting_startDate_AZ_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if ((dataSearch[j].getStartDate().year > dataSearch[j + 1].getStartDate().year) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month > dataSearch[j + 1].getStartDate().month) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month == dataSearch[j + 1].getStartDate().month && dataSearch[j].getStartDate().day > dataSearch[j + 1].getStartDate().day)) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted = true;
}

// Сортировка даты начала по убыванию
void MainWindow::on_sorting_startDate_ZA_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if ((dataSearch[j].getStartDate().year < dataSearch[j + 1].getStartDate().year) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month < dataSearch[j + 1].getStartDate().month) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month == dataSearch[j + 1].getStartDate().month && dataSearch[j].getStartDate().day < dataSearch[j + 1].getStartDate().day)) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted = true;
}

// Сортировка даты конца по возрастанию
void MainWindow::on_sorting_endDate_AZ_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if ((dataSearch[j].getStartDate().year > dataSearch[j + 1].getStartDate().year) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month > dataSearch[j + 1].getStartDate().month) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month == dataSearch[j + 1].getStartDate().month && dataSearch[j].getStartDate().day > dataSearch[j + 1].getStartDate().day)) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted = true;
}

// Сортировка даты конца по убыванию
void MainWindow::on_sorting_endDate_ZA_triggered()
{
    if(ui->SearchLine->text() == ""){
        dataSearch = dataList;
    }

    _Data dataTempor;
    for (int i = 0; i < dataSearch.size(); i++) {
        for (int j = 0; j < dataSearch.size() - i - 1; j++) {
            if ((dataSearch[j].getStartDate().year < dataSearch[j + 1].getStartDate().year) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month < dataSearch[j + 1].getStartDate().month) ||
                (dataSearch[j].getStartDate().year == dataSearch[j + 1].getStartDate().year && dataSearch[j].getStartDate().month == dataSearch[j + 1].getStartDate().month && dataSearch[j].getStartDate().day < dataSearch[j + 1].getStartDate().day)) {
                dataTempor = dataSearch[j];
                dataSearch[j] = dataSearch[j + 1];
                dataSearch[j + 1] = dataTempor;
            }
        }
    }
    TableLoad(dataSearch);

    isSorted = true;
}

// Удаление записи
void MainWindow::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить запись?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        dataList.erase(dataList.begin()+indexCurrent);
        searching();

        ui->deleteButton->setEnabled(false);
        isSaved = false;
    }
}

// Открытие окна "Диаграмма"
void MainWindow::on_diagram_triggered()
{
    ptrDiagram->setWindowTitle("Диаграмма");
    sendDiagramVector(dataList);
    ptrDiagram->exec();
}

// Открытие окна "Отчёт по запросу"
void MainWindow::on_report_triggered()
{
    ptrReport->setWindowTitle("");
    ptrReport->setWindowIcon(QIcon(":/img/car.png"));
    sendVector(dataList, dataSearch, ui->SearchLine->text().toStdString(), isSorted);
    ptrReport->exec();
}


void MainWindow::on_comboBoxSearch_currentTextChanged(const QString &arg1)
{
    ui->SearchLine->clear();
    ui->SearchLine->setEnabled(true);

}

