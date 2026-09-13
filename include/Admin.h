#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
using namespace std;

class Admin : public Person {
public:
    Admin();
    Admin(string id, string name, string password);

    void addBus();
    void removeBus();
    void updateBus();
    void viewAllBuses();

    void displayInfo() const override;
};

#endif