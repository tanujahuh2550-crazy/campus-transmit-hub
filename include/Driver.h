#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include <string>
using namespace std;

class Driver : public Person {
private:
    string license;
    string busId;

public:
    Driver();
    Driver(string id, string name, string password, string license, string busId);
    void displayInfo() const override;
};

#endif