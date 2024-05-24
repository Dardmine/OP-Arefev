#include "data.h"
#include "QString"

bool Car::operator==(const Car& car) const {
    return this->driveGoal == car.driveGoal &&
           this->model == car.model &&
           this->transmission == car.transmission &&
           this->rate == car.rate;
}

bool StartDate::operator==(const StartDate& startDate) const {
    return this->day == startDate.day &&
           this->month == startDate.month &&
           this->year == startDate.year;
}

bool EndDate::operator==(const EndDate& endDate) const {
    return this->day == endDate.day &&
           this->month == endDate.month &&
           this->year == endDate.year;
}

_Data::_Data(const Car& car, const StartDate& startDate, const EndDate& endDate, double cost, bool babyChair)
    : car(car), startDate(startDate), endDate(endDate), cost(cost), babyChair(babyChair) {}

_Data::_Data() {}

Car _Data::getCar() const {
    return car;
}

StartDate _Data::getStartDate() const {
    return startDate;
}

EndDate _Data::getEndDate() const {
    return endDate;
}

double _Data::getCost() const {
    return cost;
}

bool _Data::getBabyChair() const {
    return babyChair;
}

void _Data::setCar(const Car& car) {
    this->car = car;
}

void _Data::setStartDate(const StartDate& startDate) {
    this->startDate = startDate;
}

void _Data::setEndDate(const EndDate& endDate) {
    this->endDate = endDate;
}

void _Data::setCost(double cost) {
    this->cost = cost;
}

void _Data::setBabyChair(bool babyChair) {
    this->babyChair = babyChair;
}

bool _Data::operator==(_Data d) const {
    return this->car == d.car &&
           this->startDate == d.startDate &&
           this->endDate == d.endDate &&
           this->cost == d.cost &&
           this->babyChair == d.babyChair;
}
