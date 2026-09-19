#include "../include/Admin.h"
#include <iostream>

Admin::Admin() {}

Admin::Admin(string id, string name, string password, string adminId)
    : Person(id, name, password) {
    this->adminId = adminId;
}

void Admin::displayInfo() const {
    Person::displayInfo();
    cout << "Admin ID: " << adminId << endl;
}