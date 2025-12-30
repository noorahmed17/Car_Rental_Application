#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Cars.h"
#include "Reservation.h"
#include "FileFunctions.h"
#include "Feedbacks.h"
using namespace std;

class Customer
{
private:
    Cars allCars;
    Feedback feeds;
    Reservation res;

public:
    int customerId;
    string name;

    Customer();
    // void showAvailableCars(const vector<Car> &cars);
    void viewAllAvaliableCars();
    int findCarIndexById(const vector<Cars> &cars, int id);
    void reserveCar();
    void cancelReservation();
    void viewReservations();

    void createFeed();
};

#endif
