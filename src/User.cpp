#include "../include/User.h"
#include <iostream>
using namespace std;

// Default constructor
User::User() {
    userId = 0;
    username = "";
    password = "";
    role = "";
    phone_number = "";
}

// Parameterized constructor
User::User(int id, string name, string pass, string r, string phone) {
    userId = id;
    username = name;
    password = pass;
    role = r;
    phone_number = phone;
}

User::User(int id, string uname, string pass,
    string phone, string r, string nid)
{
    userId = id;
    username = uname;
    password = pass;
    phone_number = phone;
    role = r;
    nationalId = nid;
}

// Setters
void User::setUserId(int id) {
    userId = id;
}

void User::setUsername(string name) {
    username = name;
}

void User::setPassword(string pass) {
    password = pass;
}

void User::setRole(string r) {
    role = r;
}

void User::setPhoneNumber(string phone) {
    phone_number = phone;
}

void User::setNationalId(string nid) {
    nationalId = nid;
}

// Getters
int User::getUserId() {
    return userId;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

string User::getRole() {
    return role;
}

string User::getPhoneNumber() {
    return phone_number;
}

string User::getNationalId() {
    return nationalId;
}

// Display
void User::display() {
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
    cout << "Phone: " << phone_number << endl;
}
