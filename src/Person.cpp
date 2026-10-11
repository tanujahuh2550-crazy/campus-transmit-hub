#include "../include/Person.h"
#include <iostream>

Person::Person() {}

Person::Person(string id, string name, string password)
    : id(id), name(name), password(password) {}

void Person::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}