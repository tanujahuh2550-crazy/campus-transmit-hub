#include "../include/Driver.h"
#include <iostream>
using namespace std;

Driver::Driver() : Person(), license(""), busId("") {}

Driver::Driver(string id, string name, string password,
               string license, string busId)
    : Person(id, name, password),
      license(license), busId(busId) {}

string Driver::getLicenseNumber() const {
    return license;
}

string Driver::getAssignedBusId() const {
    return busId;
}

void Driver::displayInfo() const {
    Person::displayInfo();
    cout << "License: " << license << endl;
    cout << "Bus ID: " << busId << endl;
}
