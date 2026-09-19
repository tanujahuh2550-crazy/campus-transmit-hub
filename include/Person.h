#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string id;
    string name;
    string password;

public:
    Person();
    Person(string id, string name, string password);
    virtual void displayInfo() const;
};

#endif