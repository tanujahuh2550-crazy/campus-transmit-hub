#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
using namespace std;

class Notification {
private:
    string id;
    string message;
    string date;
    string targetRole;

public:
    Notification();

    Notification(string id, string message,
                 string date, string targetRole);

    string getNotificationId() const;
    string getMessage() const;
    string getDate() const;
    string getTargetRole() const;

    void displayInfo() const;
};

#endif
