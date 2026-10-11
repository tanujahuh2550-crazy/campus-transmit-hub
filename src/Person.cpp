#include "../include/Person.h"
#include <iostream>

Person::Person() {}

Person::Person(string id, string name, string password)
    : id(id), name(name), password(password) {}

string Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getPassword() const {
    return password;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setPassword(string password) {
    this->password = password;
}

void Person::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}
