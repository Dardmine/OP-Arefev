#include "addorderwindow.h"
#include "ui_addorderwindow.h"
#include <QMessageBox>
#include <ctime>


float transmissionСoefficient {};
float buffRate {};
int dateDifference = 0;


AddOrderWindow::AddOrderWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddOrderWindow)
{
    ui->setupUi(this);
}

AddOrderWindow::~AddOrderWindow()
{
    delete ui;
}

// Очистка Введенных Данных
void AddOrderWindow::clearInputData(){
    ui->reason->setCurrentIndex(-1);
    ui->model->setCurrentIndex(-1);
    ui->transmition->setCurrentIndex(-1);
    ui->startDate->clearMinimumDate();
    ui->startDate->clearMaximumDate();
    ui->endDate->clearMinimumDate();
    ui->endDate->clearMaximumDate();
    ui->haveBabyChair->setChecked(false);
    ui->costLine->clear();
}



void AddOrderWindow::on_buttonBox_rejected()
{
    clearInputData();
    AddOrderWindow::close();
}

// Добавление Записи
void AddOrderWindow::on_buttonBox_accepted()
{
    // clear все окна
    //ui->startDate->clearMinimumDate();

    char temp[10] = {};
    StartDate startDateValid;
    const char* formatYear = "%Y";
    const char* formatMonth = "%m";
    const char* formatDay = "%d";

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    strftime(temp, 5, formatYear, timeinfo);
    startDateValid.year = atoi(temp);
    strftime(temp, 5, formatMonth, timeinfo);
    startDateValid.month = atoi(temp);
    strftime(temp, 5, formatDay, timeinfo);
    startDateValid.day = atoi(temp);

    ui->startDate->setMinimumDate(QDate(startDateValid.year, startDateValid.month, startDateValid.day));
    if (ui->startDate->monthShown() + 1 == 13) {
        startDateValid.year++;
        startDateValid.month = 1;
        ui->startDate->setMaximumDate(QDate(startDateValid.year, startDateValid.month, startDateValid.day));
    }


    ui->endDate->setMinimumDate(QDate(startDateValid.year, startDateValid.month, startDateValid.day+1));

    bool isError = false;
    QString error = "";

    if(ui->reason->currentText() =="") {error.append("Выберите Цель!\t\n"); isError=1;};
    if(ui->model->currentText() =="") {error.append("Выберите модель!\t\n");isError=1;};
    if(ui->transmition->currentText() =="") {error.append("Введите КПП!\t\n");isError=1;};
    //if(ui->startDate->updatesEnabled()) {error.append("Введите дату начала аренды!\t\n");isError=1;};
    //if(ui->endDate->updatesEnabled()) {error.append("Введите дату конца аренды!\t\n");isError=1;};

    if(isError){
        QMessageBox::warning(this, "Ошибка!", error);
    }else{
        Car car;
        StartDate startDate;
        EndDate endDate;
        double cost = 0.0;
        bool babyChair = false;


        car.driveGoal = ui->reason->currentText().toStdString();
        car.model = ui->model->currentText().toStdString();
        car.transmission = ui->transmition->currentText().toStdString();
        car.rate = buffRate * transmissionСoefficient;
        ui->startDate->selectedDate().getDate(&startDate.year, &startDate.month, &startDate.day);
        ui->endDate->selectedDate().getDate(&endDate.year, &endDate.month, &endDate.day);

        cost = dateDifference * car.rate;
        babyChair = ui->haveBabyChair->checkState();

        _Data data(car,startDate, endDate, cost, babyChair);
        clearInputData();
        // Отправка Данных в Основное окно
        sendData(data);
        AddOrderWindow::close();
    }
}


void AddOrderWindow::on_rateLine_textChanged(const QString &arg1)
{
    //ui->costLine->setText(QString::number(buffRate, 'f', 2));
}

// Формирование Списка Моделей (Зависит от Выбора Цели поездки)
void AddOrderWindow::on_reason_currentTextChanged(const QString &arg1)
{
    ui->model->clear();
    ui->transmition->clear();
    ui->rateLine->clear();
    ui->costLine->clear();
    dateDifference = 0;

    if (arg1 == "Бизнес") {
        ui->model->addItem("BMW_5_Series");
        ui->model->addItem("Mercedes-Benz_E-Class");
        ui->model->addItem("Audi_A6");
        ui->model->addItem("Lexus_ES");
    }
    else if (arg1 == "Комфорт") {
        ui->model->addItem("Toyota_Camry");
        ui->model->addItem("Honda_Accord");
        ui->model->addItem("Volkswagen_Passat");
        ui->model->addItem("Nissan_Altima");
    }
    else if (arg1 == "Минивен") {
        ui->model->addItem("Chrysler_Pacifica");
        ui->model->addItem("Honda_Odyssey");
        ui->model->addItem("Kia_Carnival");
        ui->model->addItem("Toyota_Sienna");
    }
    else if (arg1 == "Эконом") {
        ui->model->addItem("Toyota_Corolla");
        ui->model->addItem("Hyundai_Elantra");
        ui->model->addItem("Nissan_Sentra");
        ui->model->addItem("Honda_Civic");
    }
}

void AddOrderWindow::on_model_currentTextChanged(const QString &arg1)
{
    ui->transmition->clear();
    ui->rateLine->clear();
    ui->costLine->clear();
    ui->transmition->addItem("Механическая");
    ui->transmition->addItem("Автоматическая");
    ui->transmition->addItem("Электрокар");
    dateDifference = 0;

    if (arg1 == "BMW_5_Series") {
        buffRate = 6720;
    }
    else if (arg1 == "Mercedes-Benz_E-Class") {
        buffRate = 6700;
    }
    else if (arg1 == "Audi_A6") {
        buffRate = 6600;
    }
    else if (arg1 == "Lexus_ES") {
        buffRate = 6800;
    }
    else if (arg1 == "Toyota_Camry") {
        buffRate = 4790;
    }
    else if (arg1 == "Honda_Accord") {
        buffRate = 4500;
    }
    else if (arg1 == "Volkswagen_Passat") {
        buffRate = 4450;
    }
    else if (arg1 == "Nissan_Altima") {
        buffRate = 4510;
    }
    else if (arg1 == "Chrysler_Pacifica") {
        buffRate = 4100;
    }
    else if (arg1 == "Honda_Odyssey") {
        buffRate = 3990;
    }
    else if (arg1 == "Kia_Carnival") {
        buffRate = 4120;
    }
    else if (arg1 == "Toyota_Sienna") {
        buffRate = 4400;
    }
    else if (arg1 == "Toyota_Corolla") {
        buffRate = 3830;
    }
    else if (arg1 == "Hyundai_Elantra") {
        buffRate = 3790;
    }
    else if (arg1 == "Nissan_Sentra") {
        buffRate = 3800;
    }
    else if (arg1 == "Honda_Civic") {
        buffRate = 3990;
    }

}

void AddOrderWindow::on_transmition_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Механическая") {
        transmissionСoefficient = 1;
    }
    else if (arg1 == "Автоматическая") {
        transmissionСoefficient = 1.1;
    }
    else if (arg1 == "Электрокар") {
        transmissionСoefficient = 1.2;
    }
    ui->rateLine->setText(QString::number(buffRate * transmissionСoefficient, 'f', 2));



    dateDifference = ui->endDate->selectedDate().dayOfYear() - ui->startDate->selectedDate().dayOfYear();
    if (dateDifference < 0){
        dateDifference = ui->startDate->selectedDate().daysInYear()-ui->startDate->selectedDate().dayOfYear()+ui->endDate->selectedDate().dayOfYear();
    }
    ui->costLine->setText(QString::number(buffRate * transmissionСoefficient * dateDifference, 'f', 2));
}





void AddOrderWindow::on_startDate_clicked(const QDate &date)
{
    char temp[10] = {};
    StartDate startDateValid;
    const char* formatYear = "%Y";
    const char* formatMonth = "%m";
    const char* formatDay = "%d";

    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    strftime(temp, 5, formatYear, timeinfo);
    startDateValid.year = atoi(temp);
    strftime(temp, 5, formatMonth, timeinfo);
    startDateValid.month = atoi(temp);
    strftime(temp, 5, formatDay, timeinfo);
    startDateValid.day = atoi(temp);

    StartDate *currentDate = new StartDate();
    currentDate->day = startDateValid.day;
    currentDate->month = startDateValid.month;
    currentDate->year = startDateValid.year;

    ui->startDate->clearMinimumDate();
    ui->startDate->setMinimumDate(QDate(currentDate->year, currentDate->month, currentDate->day));


    dateDifference = ui->endDate->selectedDate().dayOfYear() - ui->startDate->selectedDate().dayOfYear();
    if (dateDifference < 0){
        dateDifference = ui->startDate->selectedDate().daysInYear()-ui->startDate->selectedDate().dayOfYear()+ui->endDate->selectedDate().dayOfYear();
    }
    ui->costLine->setText(QString::number(buffRate * transmissionСoefficient * dateDifference, 'f', 2));
}


void AddOrderWindow::on_endDate_clicked(const QDate &date)
{

    EndDate *currentDate = new EndDate();
    currentDate->day = ui->startDate->selectedDate().day();
    currentDate->month = ui->startDate->selectedDate().month();
    currentDate->year = ui->startDate->selectedDate().year();

    ui->endDate->clearMinimumDate();
    ui->endDate->clearMaximumDate();

    ui->endDate->setMinimumDate(ui->startDate->selectedDate().addDays(1));
    ui->endDate->setMaximumDate(ui->startDate->selectedDate().addMonths(1));
    dateDifference = ui->endDate->selectedDate().dayOfYear() - ui->startDate->selectedDate().dayOfYear();
    if (dateDifference < 0){
        dateDifference = ui->startDate->selectedDate().daysInYear()-ui->startDate->selectedDate().dayOfYear()+ui->endDate->selectedDate().dayOfYear();
    }

    ui->costLine->setText(QString::number(buffRate * transmissionСoefficient * dateDifference, 'f', 2));
}


void AddOrderWindow::on_startDate_selectionChanged()
{
    ui->endDate->setMinimumDate(ui->startDate->selectedDate().addDays(1));
    ui->endDate->setMaximumDate(ui->startDate->selectedDate().addMonths(1));
    dateDifference = ui->endDate->selectedDate().dayOfYear() - ui->startDate->selectedDate().dayOfYear();
    if (dateDifference < 0){
        dateDifference = ui->startDate->selectedDate().daysInYear()-ui->startDate->selectedDate().dayOfYear()+ui->endDate->selectedDate().dayOfYear();
    }
}


void AddOrderWindow::on_endDate_selectionChanged()
{
    ui->endDate->setMinimumDate(ui->startDate->selectedDate().addDays(1));
    ui->endDate->setMaximumDate(ui->startDate->selectedDate().addMonths(1));
    dateDifference = ui->endDate->selectedDate().dayOfYear() - ui->startDate->selectedDate().dayOfYear();
    if (dateDifference < 0){
        dateDifference = ui->startDate->selectedDate().daysInYear()-ui->startDate->selectedDate().dayOfYear()+ui->endDate->selectedDate().dayOfYear();
    }
}

