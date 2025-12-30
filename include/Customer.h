// #ifndef CUSTOMER_H
// #define CUSTOMER_H

// #include <string>
// #include <vector>
// #include "Cars.h"
// #include "Reservation.h"
// #include "FileFunctions.h"
// #include "Feedbacks.h"
// using namespace std;

// class Customer
// {
// private:
//     Cars allCars;
//     Feedback feeds;
//     Reservation res;

// public:
//     int customerId;
//     string name;

//     //Customer();
//     // void showAvailableCars(const vector<Car> &cars);
//     void viewAllAvaliableCars();
//     int findCarIndexById(const vector<Cars> &cars, int id);
//     void reserveCar();
//     void cancelReservation();
//     void viewReservations();

//     void createFeed();
// };

// #endif

#pragma once
#include "User.h"
#include "Cars.h"
#include "Reservation.h"
#include "FileFunctions.h"
#include "Feedbacks.h"
#include <vector>
#include <string>
using namespace std;
class Customer : public User
{
private:
    Cars allCars;
    Feedback feeds;
    Reservation res;

public:
    Customer();

    Customer(int userId,
             const string &username,
             const string &fullName,
             const string &phone,
             const string &nationalId);

    bool login() override;
    void showMenu() override;
    static bool Register();
    void viewAllAvaliableCars();
    void reserveCar();
    void cancelReservation();
    void viewReservations();
    void createFeed();
    int getCustomerId() const;
    string getFullName() const;
    string getPhone() const;
    string getNationalId() const;


private:
    int customerId;
    string fullName;
    string phone;
    string nationalId;
    int findCarIndexById(const vector<Cars> &cars, int id);
};