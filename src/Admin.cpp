#include "../include/Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() : Person(), adminId("") {}

Admin::Admin(string id, string name, string password, string adminId)
    : Person(id, name, password), adminId(adminId) {}

string Admin::getAdminId() const {
    return adminId;
}

void Admin::displayInfo() const {
    Person::displayInfo();
    cout << "Admin ID: " << adminId << endl;
}
