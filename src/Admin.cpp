#include "../include/Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() : Person() {}

Admin::Admin(string id, string name, string password)
    : Person(id, name, password) {}

void Admin::displayInfo() const {
    cout << "\n--- Admin Information ---\n";
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
}

// Admin module functions
void Admin::addBus() {
    cout << "Add Bus function\n";
}

void Admin::removeBus() {
    cout << "Remove Bus function\n";
}

void Admin::updateBus() {
    cout << "Update Bus function\n";
}

void Admin::viewAllBuses() {
    cout << "View All Buses function\n";
}