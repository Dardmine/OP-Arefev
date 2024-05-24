#include <iostream>
#include <tuple>
#ifndef DATA_H
#define DATA_H

#endif // DATA_H
#pragma once



struct Car {
    std::string driveGoal;
    std::string model;
    std::string transmission;
    float rate;

    bool operator==(const Car& car) const;
};

struct StartDate {
    int day = 0;
    int month = 0;
    int year = 0;

    bool operator==(const StartDate& startDate) const;
};

struct EndDate {
    int day = 0;
    int month = 0;
    int year = 0;

    bool operator==(const EndDate& endDate) const;
};

class _Data {
public:
    _Data(const Car& car, const StartDate& startDate, const EndDate& endDate, double cost, bool babyChair);
    _Data();

    Car getCar() const;
    StartDate getStartDate() const;
    EndDate getEndDate() const;
    double getCost() const;
    bool getBabyChair() const;

    void setCar(const Car& car);
    void setStartDate(const StartDate& startDate);
    void setEndDate(const EndDate& endDate);
    void setCost(double cost);
    void setBabyChair(bool babyChair);

    bool operator==(_Data d) const;

private:
    Car car;
    StartDate startDate;
    EndDate endDate;
    double cost;
    bool babyChair;
};
