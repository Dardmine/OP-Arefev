#include "diagram.h"
#include "ui_diagram.h"
#include <QtWidgets/QMainWindow>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QValueAxis>

QChartView *chartView;

Diagram::Diagram(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Diagram)
{
    ui->setupUi(this);
}

Diagram::~Diagram()
{
    delete ui;
}

void Diagram::recieveDiagramVector(std::vector<_Data> dataList){
    // Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("Бизнес");
    QBarSet *set1 = new QBarSet("Минивен");
    QBarSet *set2 = new QBarSet("Комфорт");
    QBarSet *set3 = new QBarSet("Эконом");

    int c0{}, c1{}, c2{}, c3{};
    for (int i=0; i<dataList.size(); i++){
        if(strcmp("Бизнес", dataList[i].getCar().driveGoal.c_str()) == 0){
            c0++;
        }
        if(strcmp("Минивен", dataList[i].getCar().driveGoal.c_str()) == 0){
            c1++;
        }
        if(strcmp("Комфорт", dataList[i].getCar().driveGoal.c_str()) == 0){
            c2++;
        }
        if(strcmp("Эконом", dataList[i].getCar().driveGoal.c_str()) == 0){
            c3++;
        }
    }

    // Assign values for each bar
    *set0 << c0;
    *set1 << c1;
    *set2 << c2;
    *set3 << c3;
    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Количество заказов");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "Тип машины";


    QValueAxis *axisY = new QValueAxis;
    axisY->setTickType(QValueAxis::TicksDynamic);
    axisY->setTickAnchor(0);
    axisY->setTickInterval(1);

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chartView = new QChartView(chart);
    chart->setAxisY(axisY, series);
    chart->setAxisX(axis, series);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the chartView as the central widget
    ui->horizontalLayout->addWidget(chartView);
}

void Diagram::on_Diagram_finished(int result)
{
    ui->horizontalLayout->removeWidget(chartView);
}
