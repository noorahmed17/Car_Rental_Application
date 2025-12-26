#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string managerMenu[] = {"1. Manage Cars",
                              "2. Manage Drivers",
                              "3. View Reservations",
                              "4. Assign Driver to Reservation",
                              "5. Generate Reports",
                              "6. Logout"};
enum Role
{
    manager,
    customer,
    driver
};

struct Users
{
    int userId;
    string userName;
    string password;
    Role role;
    string phoneNumber;
    string nationalID;
};

void loadFromUsersFile(vector<Users> &users)
{
    ifstream file("users.csv");
    if (!file.is_open())
    {
        cout << "Error in Finding file Location\n";
        return;
    }
    string line;
    getline(file, line);

    while (getline(file, line))
    {
        if (line.empty())
            continue;
        stringstream ss(line);
        string token;
        vector<string> data;

        while (getline(ss, token, ','))
        {
            data.push_back(token);
        }

        if (!line.empty() && line.back() == ',')
        {
            data.push_back("");
        }

        if (data.size() < 6)
            continue;

        if (data[4] != "manager")
            continue;

        Users u;
        u.userId = stoi(data[0]);
        u.userName = data[1];
        u.password = data[2];
        u.phoneNumber = data[3];
        u.role = manager;
        u.nationalID = data[5];

        users.push_back(u);
    }
    file.close();
    cout << "Loaded " << users.size() << " users from users.csv\n";
}

struct Cars
{
    int carId;
    string brand;
    string color;
    string model;
    int CarNum;
    bool isAvailable;
    double rentalPricePerDay;
};

void loadFromCarsFile(vector<Cars> &cars)
{
    ifstream file("cars.csv");
    if (!file.is_open())
    {
        cout << "Error in Finding file Location\n";
        return;
    }
    string line;
    getline(file, line);

    while (getline(file, line))
    {
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        if (line.empty())
            continue;
        stringstream ss(line);
        string token;
        vector<string> data;

        while (getline(ss, token, ','))
        {
            data.push_back(token);
        }

        Cars c;
        c.carId = stoi(data[0]);
        c.model = data[1];
        c.color = data[2];
        c.CarNum = stoi(data[3]);
        c.isAvailable = stoi(data[4]);
        c.rentalPricePerDay = stod(data[5]);

        cars.push_back(c);
    }
    file.close();
    cout << "Loaded " << cars.size() << " users from cars.csv\n";
}

void addToFileCars(Cars &newCar)
{
    ofstream file("cars.csv", ios::app);
    if (!file.is_open())
    {
        cout << "Error: Could not open cars.csv for writing!\n";
        return;
    }

    file << newCar.carId << ","
         << newCar.model << ","
         << newCar.color << ","
         << newCar.CarNum << ","
         << (newCar.isAvailable ? "1" : "0") << ","
         << newCar.rentalPricePerDay << "\n";

    file.close();
    cout << "Car added successfully to file with ID: " << newCar.carId << endl;
}

class Manager
{
    vector<Users> Managers;
    vector<Cars> cars;
    int nextCar = 1;

public:
    Manager()
    {
        loadFromUsersFile(Managers);
        loadFromCarsFile(cars);
    };

    void viewManagers()
    {
        cout << "\n--- List of Managers ---\n";
        for (const auto &m : Managers)
        {
            cout << "ID: " << m.userId
                 << " | Name: " << m.userName
                 << " | Password" << m.password
                 << " | Phone: " << m.phoneNumber << endl;
        }
    }
    void viewCars()
    { // Will be inhertied from class Car
        cout << "\n--- List of Cars ---\n";
        for (const auto &c : cars)
        {
            cout << "ID: " << c.carId
                 << " | Model: " << c.model
                 << " | Color: " << c.color
                 << " | Car Number: " << c.CarNum
                 << " | Rental Cost: " << c.rentalPricePerDay
                 << " | Status: " << (c.isAvailable == 1 ? "is Available" : "Not Available")
                 << endl;
        }
    }
    void addCar()
    {
        if (!cars.empty())
        {
            for (const auto &c : cars)
            {
                if (c.carId >= nextCar)
                    nextCar = c.carId + 1;
            }
        }
        
        Cars newCar;
        newCar.carId = nextCar;
        cout << "\n--- Add New Car To The System ---\n";
        cout << " Model: ";
        cin >> newCar.model;
        cout << " Color: ";
        cin >> newCar.color;
        cout << " Car Number: ";
        cin >> newCar.CarNum;
        cout << " Rental Cost: ";
        cin >> newCar.rentalPricePerDay;
        cout << " Status: ";
        cin >> newCar.isAvailable;

        cars.push_back(newCar);
        addToFileCars(newCar);
    }
};

int main()
{
    Manager m;
    //m.viewManagers();
    m.viewCars();
    //m.addCar();
    //      Manager Menu:
    //  1. Manage Cars
    //  2. Manage Drivers
    //  3. View Reservations
    //  4. Assign Driver to Reservation
    //  5. Generate Reports
    //  6. Logout
    return 0;
}