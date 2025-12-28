#include "Customer.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
using namespace std;
//Search available
void searchAvailableCars() {
    ifstream file("cars.txt", ios::in);

    if (!file) {
        cout << "Error opening cars file.\n";
        return;
    }

    string line;
    bool anyAvailable = false;  

    cout << "Available Cars:\n";

    while (getline(file, line)) {
        stringstream ss(line);

        string id, brand, model, year, price, status;

        getline(ss, id, ',');
        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, year, ',');
        getline(ss, price, ',');
        getline(ss, status, ',');



        if (status == "Available") {
            anyAvailable = true;
            cout << "---------------------\n";
            cout << "ID: " << id << endl;
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Price per day: $" << price << endl;
        }
    }

    if (!anyAvailable) {
        cout << "Dear,There is no available cars \n";
    }

    file.close();
}


void Customer::showAvailableCars(const vector<Car>& cars) {
    cout << "\nAvailable Cars:\n";
    for (auto& car : cars)
        if (car.isAvailable())
            car.showDetails();
}

int Customer::findCarIndexById(const vector<Car>& cars, int id) {
    for (int i = 0; i < cars.size(); i++)
        if (cars[i].carId == id && cars[i].isAvailable())
            return i;
    return -1;
}

void Customer::reserveCar() {
    vector<Car> cars = loadCars();
    showAvailableCars(cars);

    int chosenId;
    cout << "Enter Car ID to reserve: ";
    cin >> chosenId;

    int index = findCarIndexById(cars, chosenId);
    if (index == -1) { cout << "Car not available!\n"; return; }

    string start, end;
    cout << "Start Date: "; cin >> start;
    cout << "End Date: "; cin >> end;

    int days = 3; 
    double cost = days * cars[index].pricePerDay;

    Reservation r(rand() % 10000, customerId, cars[index].carId, start, end, days, cost);

    cars[index].reserve();
    saveCars(cars);
    saveReservation(r);

    cout << "\nReservation Successful!\n";
    cout << "Total Cost: " << r.totalCost << endl;
}

void Customer::cancelReservation() {
    vector<Reservation> reservations = loadReservations();
    vector<Car> cars = loadCars();

    int resId;
    cout << "\nEnter Reservation ID to cancel: ";
    cin >> resId;

    bool found = false;
    for (auto& r : reservations) {
        if (r.reservationId == resId &&
            r.customerId == customerId &&
            r.status == "Active") {

            r.status = "Canceled";
            found = true;

            for (auto& c : cars) {
                if (c.carId == r.carId) {
                    c.makeAvailable();
                    break;
                }
            }

            updateReservation(r);
            saveCars(cars);

            cout << "Reservation canceled successfully ✔\n";
            break;
        }
    }

    if (!found) cout << "Reservation not found or already canceled!\n";
}

void Customer::viewReservations() {
    vector<Reservation> reservations = loadReservations();
    bool hasRes = false;
    cout << "\nYour Reservations:\n";
    for (auto& r : reservations) {
        if (r.customerId == customerId) {
            cout << "ID: " << r.reservationId
                 << " | CarID: " << r.carId
                 << " | Status: " << r.status
                 << " | From: " << r.startDate
                 << " To: " << r.endDate
                 << " | Cost: " << r.totalCost << endl;
            hasRes = true;
        }
    }
    if (!hasRes) cout << "No reservations found.\n";
}
