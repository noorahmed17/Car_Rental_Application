// #ifndef USER_H
// #define USER_H
// #include <string>
// using namespace std;

// class User {
// protected:
//     int userId;
//     string username;
//     string password;
//     string role;          // customer, manager, driver
//     string phone_number;
//     string nationalId;

// public:
//     // Constructors
//     User();
//     User(int id, string name, string pass, string role, string phone);
//     User(int id, string uname, string pass,string phone, string r, string nid);

//     // Setters
//     void setUserId(int id);
//     void setUsername(string name);
//     void setPassword(string pass);
//     void setRole(string role);
//     void setPhoneNumber(string phone);
//     void setNationalId(string nationalId);

//     // Getters
//     int getUserId();
//     string getUsername();
//     string getPassword();
//     string getRole();
//     string getPhoneNumber();
//     string getNationalId();

//     // Display
//     void display();
// };

// #endif
#pragma once
#include <string>
using namespace std;
enum Role
{
    Role_Customer = 0,
    Role_Manager = 1,
    Role_Driver = 2

};
class User
{
public:
    virtual bool login() = 0;    // pure virtual
    virtual void showMenu() = 0; // pure virtual
    virtual ~User() {}

protected:
    int user_Id;
    string userName;
    string password;
    Role role;
};
