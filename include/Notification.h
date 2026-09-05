#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
using namespace std;

class Notification {
private:
    string notificationId;
    string message;
    string date;
    string targetRole;

public:
    Notification();
    Notification(string notificationId, string message,
                 string date, string targetRole);

    string getNotificationId() const;
    string getMessage() const;
    string getDate() const;
    string getTargetRole() const;

    void setMessage(string message);
    void setDate(string date);
    void setTargetRole(string targetRole);

    void displayNotification() const;
};

#endif