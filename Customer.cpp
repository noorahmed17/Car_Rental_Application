#include "Customer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

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
