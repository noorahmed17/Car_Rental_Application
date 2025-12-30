// #include <iostream>
// #include "Manager.h"
// #include "Driver.h"
// #include "Cars.h"
// #include "Customer.h"
// using namespace std;

// int main()
// {
//     loadFeedbacks(Feedback::feedbacks, "feedbacks.csv");
//     Cars temp;
//     temp.readFromFile("cars.csv", Cars::allCars);

//     Manager mgr;
//     mgr.readDataFromFile("users.csv"); // your Excel exported as CSV
//     // mgr.displayDrivers();

//     // Car Functionality
//     //mgr.addCar();
//     // mgr.viewAllCars();
//     // mgr.updateCar();
//     // mgr.deleteCar();

//     mgr.viewFeedbacks();

//     //  Add a driver
//     // Driver newDriver(12, "Taha Diaa", "pass999", "200000000", "driver", "6.77889E+13", true);
//     // mgr.addDriver(newDriver);

//     // Update driver
//     // mgr.updateDriver(6, "999999999");

//     // Delete driver
//     // mgr.deleteDriver(7);

//     // mgr.displayDrivers();
//     Customer c;
//     // c.viewAllAvaliableCars();
//     // c.reserveCar();
//     c.viewReservations();
//     c.createFeed();

//     return 0;
// }
// #include "conio2.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "AuthService.h"
#include "Customer.h"
using namespace std;

int showMainMenu()
{
    const char *options[] = {
        "Login",
        "Register (Customer Only)",
        "Exit"};

    int selected = 0;

    while (true)
    {
        system("cls");
        cout << "====== CAR RENTAL SYSTEM ======\n\n";

        for (int i = 0; i < 3; i++)
        {
            if (i == selected)
                cout << " > " << options[i] << endl;
            else
                cout << "   " << options[i] << endl;
        }
        char key = _getwch();
        if (key == 72 && selected > 0)
            selected--;
        else if (key == 80 && selected < 2)
            selected++;
        else if (key == 13)
            return selected;
    }
}

int main()
{
    while (true)
    {
        int choice = showMainMenu();
        if (choice == 0)
        {
            system("cls");
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            User *user = AuthService::authenticate(username, password);
            if (user)
            {
                user->login();
                user->showMenu();
                delete user;
            }
            else
            {
                cout << "Login failed!\n";
                system("pause");
            }
        }
        else if (choice == 1)
        {
            system("cls");
            Customer::Register();
            system("pause");
        }
        else
        {
            cout << "Thank You for Using Our System\n";
            break;
        }
    }
    return 0;
}

// GUI