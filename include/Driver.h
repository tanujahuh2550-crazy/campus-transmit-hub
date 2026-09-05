#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include <string>
using namespace std;

class Driver : public Person {
private:
    string licenseNumber;
    string assignedBusId;

public:
    Driver();
    Driver(string id, string name, string password,
           string licenseNumber, string assignedBusId);

    string getLicenseNumber() const;
    string getAssignedBusId() const;

    void setLicenseNumber(string licenseNumber);
    void setAssignedBusId(string assignedBusId);

    void displayInfo() const override;
};

#endif