#include <iostream>
#include "Manager.h"
#include "Driver.h"
#include "Cars.h"
#include "Customer.h"
using namespace std;

int main()
{
    loadFeedbacks(Feedback::feedbacks, "feedbacks.csv");
    Cars temp;
    temp.readFromFile("cars.csv", Cars::allCars);

    Manager mgr;
    mgr.readDataFromFile("users.csv"); // your Excel exported as CSV
    // mgr.displayDrivers();

    // Car Functionality
    //mgr.addCar();
    // mgr.viewAllCars();
    // mgr.updateCar();
    // mgr.deleteCar();

    mgr.viewFeedbacks();

    //  Add a driver
    // Driver newDriver(12, "Taha Diaa", "pass999", "200000000", "driver", "6.77889E+13", true);
    // mgr.addDriver(newDriver);

    // Update driver
    // mgr.updateDriver(6, "999999999");

    // Delete driver
    // mgr.deleteDriver(7);

    // mgr.displayDrivers();
    Customer c;
    // c.viewAllAvaliableCars();
    // c.reserveCar();
    c.viewReservations();
    c.createFeed();

    return 0;
}
