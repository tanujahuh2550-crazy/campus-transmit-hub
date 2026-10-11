#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
using namespace std;

class Notification {
private:
    string id;
    string message;

public:
    Notification();
    Notification(string id, string message);
    void displayInfo() const;
};

#endif