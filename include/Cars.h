#ifndef CARS_H
#define CARS_H
#include <iostream>
#include <vector>
#include "File.h"
using namespace std;

class Cars : public File<Cars>
{

public:
    int carId;
    string model;
    string color;
    int carNum;
    bool availibility_status;
    double carRentalCost;
    static vector<Cars> allCars;
    Cars();

    void viewAllCars();
    void viewAllAvaliableCars();
    void viewCarInfo(int id);
    // void setAvailability(vector<Cars> cars, int id) ;
};

#endif
