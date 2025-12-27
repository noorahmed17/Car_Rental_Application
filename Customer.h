#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Car.h"
#include "Reservation.h"
#include "FileFunctions.h"
using namespace std;

class Customer {
public:
    int customerId;
    string name;

    void showAvailableCars(const vector<Car>& cars);
    int findCarIndexById(const vector<Car>& cars, int id);
    void reserveCar();
    void cancelReservation();
    void viewReservations();
};

#endif
