#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include "User.h"
#include "Driver.h"
#include "Cars.h"
#include "File.h"
#include "reservation.h"

using namespace std;

class Manager : public User
{
private:
    Cars carManager;
    Reservation res;

public:
    vector<Driver> drivers;

    Manager();
    void readDataFromFile(const string &filename);
    void addDriver(Driver d);
    void saveDataToFile(const string& filename);
    void updateDriver(int driverId, string newPhone);
    void deleteDriver(int driverId);
    void displayDrivers();

    void viewAllCars();
    void addCar();
    void updateCar();
    void deleteCar();

    void viewReservation();
};

#endif
