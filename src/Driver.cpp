#include "../include/Driver.h"
#include <iostream>

Driver::Driver() {}

Driver::Driver(string id, string name, string password, string license, string busId)
    : Person(id, name, password) {
    this->license = license;
    this->busId = busId;
}

void Driver::displayInfo() const {
    Person::displayInfo();
    cout << "License: " << license << endl;
    cout << "Bus ID: " << busId << endl;
}