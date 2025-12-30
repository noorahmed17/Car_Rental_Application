#include <iostream>
#include "Manager.h"
#include "Driver.h"
using namespace std;


    int main() {
        Manager mgr;
        mgr.readDataFromFile("users.csv"); // your Excel exported as CSV
        mgr.displayDrivers();

        // Add a driver
        Driver newDriver(13, "soha Diaa", "pass999", "200000000", "driver", "6.77889E+13", true);
        mgr.addDriver(newDriver);

        // Update driver
        mgr.updateDriver(6, "999999999");

        // Delete driver
        mgr.deleteDriver(7);

        mgr.saveDataToFile("users.csv");
        mgr.displayDrivers();
        return 0;
    }

