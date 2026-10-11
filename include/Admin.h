#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <string>
using namespace std;

class Admin : public Person {
private:
    string adminId;

public:
    Admin();
    Admin(string id, string name, string password, string adminId);

    string getAdminId() const;

    void displayInfo() const override;
};

#endif
