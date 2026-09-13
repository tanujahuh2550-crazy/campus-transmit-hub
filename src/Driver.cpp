#include "../include/Driver.h"
#include <iostream>
using namespace std;

Driver::Driver() : Person(), licenseNumber(""), assignedBusId("") {}

Driver::Driver(string id, string name, string password,
               string licenseNumber, string assignedBusId)
    : Person(id, name, password),
      licenseNumber(licenseNumber),
      assignedBusId(assignedBusId) {}

string Driver::getLicenseNumber() const {
    return licenseNumber;
}

string Driver::getAssignedBusId() const {
    return assignedBusId;
}

void Driver::setLicenseNumber(string licenseNumber) {
    this->licenseNumber = licenseNumber;
}

void Driver::setAssignedBusId(string assignedBusId) {
    this->assignedBusId = assignedBusId;
}

void Driver::displayInfo() const {
    cout << "\n--- Driver Information ---\n";
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "License Number: " << licenseNumber << endl;
    cout << "Assigned Bus ID: " << assignedBusId << endl;
}