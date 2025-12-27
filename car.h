#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car {
public:
    int carId;
    string brand;
    string model;
    int year;
    double pricePerDay;
    string availabilityStatus;

    Car() {}
    Car(int id, string b, string m, int y, double p, string s) {
        carId = id;
        brand = b;
        model = m;
        year = y;
        pricePerDay = p;
        availabilityStatus = s;
    }

    void reserve() { availabilityStatus = "Reserved"; }
    void makeAvailable() { availabilityStatus = "Available"; }
    bool isAvailable() const { return availabilityStatus == "Available"; }

    void showDetails() const {
        cout << carId << " - " << brand << " " << model
             << " (" << year << ") Price/Day: " << pricePerDay
             << " Status: " << availabilityStatus << endl;
    }
};

#endif