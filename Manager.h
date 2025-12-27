#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include "User.h"
#include "Driver.h"

using namespace std;

class Manager : public User {
public:
    vector<Driver> drivers;

    void readDataFromFile(const string& filename);
    void addDriver(Driver d);
    void updateDriver(int driverId, string newPhone);
    void deleteDriver(int driverId);
    void displayDrivers();
};

#endif

