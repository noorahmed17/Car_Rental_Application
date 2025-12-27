#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"
#include <string>

using namespace std;

class Driver : public User
{
public:
    bool status;   // Available or not

    Driver();
    Driver(int id, string uname, string pass, string phone,
        string r, string nid, bool s);
};

#endif
