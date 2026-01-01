#include <iostream>
#include <cstdlib>
#include "CustomerService.h"
#include "FileFunctions.h"

using namespace std;
// MERGE customer and customerService
CustomerService::CustomerService() : allCars() {}

void CustomerService::viewAllAvaliableCars()
{
    allCars.viewAllAvaliableCars();
}
int CustomerService::findCarIndexById(const vector<Cars> &cars, int id)
{
    for (int i = 0; i < cars.size(); i++)
        if (cars[i].carId == id && cars[i].isAvailable())
            return i;
    return -1;
}
void CustomerService::reserveCar()
{ // update status after
    vector<Cars> cars = loadCars();
    allCars.viewAllAvaliableCars();

    int chosenId;
    cout << "Enter Car ID to reserve: ";
    cin >> chosenId;

    int index = findCarIndexById(cars, chosenId);
    if (index == -1)
    {
        cout << "Car not available!\n";
        return;
    }
    string start, end;
    cout << "Start Date: ";
    cin >> start;
    cout << "End Date: ";
    cin >> end;

    int days = 3;
    double cost = days * cars[index].carRentalCost;
    // Reservation r(rand() % 10000, customerId,
    //     cars[index].carId, start, end, days, cost);
    Reservation r(customerId,
                  cars[index].carId, start, end, days, cost);
    cars[index].reserve();
    saveCars(cars);
    // saveReservation(r);

    cout << "\nReservation Successful!\n";
    cout << "Total Cost: " << r.totalCost << endl;
}

void CustomerService::cancelReservation()
{
    vector<Reservation> reservations = loadReservations();
    vector<Cars> cars = loadCars();

    int resId;
    cout << "\nEnter Reservation ID to cancel: ";
    cin >> resId;

    bool found = false;
    for (auto &r : reservations)
    {
        if (r.reservationId == resId &&
            r.customerId == customerId &&
            r.status == "Active")
        {

            r.status = "Canceled";
            found = true;

            for (auto &c : cars)
            {
                if (c.carId == r.carId)
                {
                    c.makeAvailable();
                    break;
                }
            }
            //updateReservation(r);
            saveReservations(reservations);
            saveCars(cars);

            cout << "Reservation canceled successfully \n";
            break;
        }
    }

    if (!found)
        cout << "Reservation not found or already canceled!\n";
}

void CustomerService::viewReservations()
{
    vector<Reservation> reservations = loadReservations();
    bool hasRes = false;

    cout << "\nYour Reservations:\n";
    for (auto &r : reservations)
    {
        if (r.customerId == customerId)
        {
            cout << "ID: " << r.reservationId
                 << " | CarID: " << r.carId
                 << " | Status: " << r.status
                 << " | From: " << r.startDate
                 << " To: " << r.endDate
                 << " | Cost: " << r.totalCost << endl;
            hasRes = true;
        }
    }

    if (!hasRes)
        cout << "No reservations found.\n";
}