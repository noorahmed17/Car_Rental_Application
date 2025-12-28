#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include "User.h"
#include "Driver.h"
#include "Cars.h"
#include "File.h"

using namespace std;

class Manager : public User, public Cars
{
public:
    vector<Driver> drivers;

    Manager();
    void readDataFromFile(const string &filename);
    void addDriver(Driver d);
    void updateDriver(int driverId, string newPhone);
    void deleteDriver(int driverId);
    void displayDrivers();

    void addCar();
    void updateCar();
    void deleteCar();
};

#endif
