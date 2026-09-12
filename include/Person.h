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

    string getId() const;
    string getName() const;
    string getPassword() const;

    void setName(string name);
    void setPassword(string password);

    virtual void displayInfo() const = 0;

    virtual ~Person() {}
};

#endif