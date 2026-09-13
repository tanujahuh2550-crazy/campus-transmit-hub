#include "../include/Person.h"
#include <iostream>
using namespace std;

Person::Person()
{
    id = "";
    name = "";
    password = "";
}

Person::Person(string id, string name, string password)
{
    this->id = id;
    this->name = name;
    this->password = password;
}

string Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

string Person::getPassword() const
{
    return password;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setPassword(string password)
{
    this->password = password;
}

void Person::displayInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
