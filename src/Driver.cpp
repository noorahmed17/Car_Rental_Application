#include "../include/Driver.h"

// Default constructor
Driver::Driver() : User()
{
    status = true;
}

// Parameterized constructor
Driver::Driver(int id, string uname, string pass, string phone,
    string r, string nid, bool s)
    : User(id, uname, pass, phone, r, nid)
{
    status = s;
}
