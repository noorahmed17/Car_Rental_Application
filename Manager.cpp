#include "Manager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Read data from CSV file
void Manager::readDataFromFile(const string& filename)
{
    ifstream file(filename);
    string line;

    getline(file, line); // skip header

    while (getline(file, line))
    {
        stringstream ss(line);
        string id, uname, pass, phone, r, nid;

        getline(ss, id, ',');
        getline(ss, uname, ',');
        getline(ss, pass, ',');
        getline(ss, phone, ',');
        getline(ss, r, ',');
        getline(ss, nid, ',');

        if (r == "driver")
        {
            drivers.push_back(
                Driver(stoi(id), uname, pass, phone, r, nid, true)
            );
        }
    }
}
void Manager::saveDataToFile(const string& filename)
{
    ofstream file(filename);
    file << "userId,username,password,phoneNumber,role,nationalID,status\n";

    for (auto& d : drivers)
    {
        file << d.getUserId() << ","
            << d.getUsername() << ","
            << d.getPassword() << ","
            << d.getPhoneNumber() << ","
            << d.getRole() << ","
            << d.getNationalId() << ","
            << d.getRole() << "\n";
    }

    file.close();
}

// Add driver
void Manager::addDriver(Driver d)
{
    drivers.push_back(d);
    cout << "Driver added: " << d.getUsername() << endl;
}

// Update driver
void Manager::updateDriver(int driverId, string newPhone)
{
    for (auto& d : drivers)
    {
        if (d.getUserId() == driverId)
        {
            d.setPhoneNumber(newPhone);
            cout << "Driver updated: " << d.getUsername() << endl;
            return;
        }
    }
    cout << "Driver not found!" << endl;
}

// Delete driver
void Manager::deleteDriver(int driverId)
{
    for (auto it = drivers.begin(); it != drivers.end(); ++it)
    {
        if (it->getUserId() == driverId)
        {
            cout << "Driver deleted: " << it->getUsername() << endl;
            drivers.erase(it);
            return;
        }
    }
    cout << "Driver not found!" << endl;
}

// Display drivers
void Manager::displayDrivers()
{
    for (auto& d : drivers)
    {
        cout << d.getUserId() << " "
            << d.getUsername() << " "
            << endl;
    }
}
