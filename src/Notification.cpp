#include "../include/Notification.h"
#include <iostream>

Notification::Notification() {}

Notification::Notification(string id, string message) {
    this->id = id;
    this->message = message;
}

void Notification::displayInfo() const {
    cout << "Notification " << id << ": " << message << endl;
}