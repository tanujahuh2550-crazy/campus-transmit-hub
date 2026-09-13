#include "../include/Notification.h"
#include <iostream>

using namespace std;

Notification::Notification()
{
    notificationId = "";
    message = "";
    date = "";
    targetRole = "";
}

Notification::Notification(string notificationId, string message,
                           string date, string targetRole)
{
    this->notificationId = notificationId;
    this->message = message;
    this->date = date;
    this->targetRole = targetRole;
}

string Notification::getNotificationId() const
{
    return notificationId;
}

string Notification::getMessage() const
{
    return message;
}

string Notification::getDate() const
{
    return date;
}

string Notification::getTargetRole() const
{
    return targetRole;
}

void Notification::setMessage(string message)
{
    this->message = message;
}

void Notification::setDate(string date)
{
    this->date = date;
}

void Notification::setTargetRole(string targetRole)
{
    this->targetRole = targetRole;
}

void Notification::displayNotification() const
{
    cout << "\n----- Notification -----" << endl;
    cout << "Notification ID: " << notificationId << endl;
    cout << "Message: " << message << endl;
    cout << "Date: " << date << endl;
    cout << "Target Role: " << targetRole << endl;
}