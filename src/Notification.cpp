#include "../include/Notification.h"
#include <iostream>
using namespace std;

Notification::Notification()
    : id(""), message(""), date(""), targetRole("") {}

Notification::Notification(string id, string message,
                           string date, string targetRole)
    : id(id), message(message), date(date),
      targetRole(targetRole) {}

string Notification::getNotificationId() const {
    return id;
}

string Notification::getMessage() const {
    return message;
}

string Notification::getDate() const {
    return date;
}

string Notification::getTargetRole() const {
    return targetRole;
}

void Notification::displayInfo() const {
    cout << "Notification ID: " << id << endl;
    cout << "Message: " << message << endl;
    cout << "Date: " << date << endl;
    cout << "Target Role: " << targetRole << endl;
}
