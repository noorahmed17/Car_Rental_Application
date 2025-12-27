#include "FileFunctions.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//================ Cars =================
vector<Car> loadCars() {
    vector<Car> cars;
    ifstream file("cars.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, year, price, status, brand, model;
        getline(ss, id, ',');
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, year, ',');
        getline(ss, price, ',');
        getline(ss, status);
        cars.push_back(Car(stoi(id), brand, model, stoi(year), stod(price), status));
    }
    return cars;
}

void saveCars(const vector<Car>& cars) {
    ofstream file("cars.txt");
    for (auto& c : cars)
        file << c.carId << "," << c.brand << "," << c.model << ","
             << c.year << "," << c.pricePerDay << "," << c.availabilityStatus << endl;
}

//================ Reservations =================
vector<Reservation> loadReservations() {
    vector<Reservation> reservations;
    ifstream file("reservations.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Reservation r;
        string id, custId, carId, days, cost;
        getline(ss, id, ','); r.reservationId = stoi(id);
        getline(ss, custId, ','); r.customerId = stoi(custId);
        getline(ss, carId, ','); r.carId = stoi(carId);
        getline(ss, r.startDate, ',');
        getline(ss, r.endDate, ',');
        getline(ss, days, ','); r.totalDays = stoi(days);
        getline(ss, cost, ','); r.totalCost = stod(cost);
        getline(ss, r.status);
        reservations.push_back(r);
    }
    return reservations;
}

void saveReservation(const Reservation& r) {
    ofstream file("reservations.txt", ios::app);
    file << r.reservationId << "," << r.customerId << ","
         << r.carId << "," << r.startDate << "," << r.endDate << ","
         << r.totalDays << "," << r.totalCost << "," << r.status << endl;
}

void updateReservation(const Reservation& updatedRes) {
    vector<Reservation> reservations = loadReservations();
    bool found = false;
    for (auto& r : reservations) {
        if (r.reservationId == updatedRes.reservationId) {
            r = updatedRes;
            found = true;
            break;
        }
    }
    if (!found) { cout << "Reservation not found!\n"; return; }

    ofstream file("reservations.txt");
    for (auto& r : reservations) {
        file << r.reservationId << "," << r.customerId << ","
             << r.carId << "," << r.startDate << "," << r.endDate << ","
             << r.totalDays << "," << r.totalCost << "," << r.status << endl;
    }
}
