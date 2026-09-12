#include "../include/Bus.h"
#include <iostream>

using namespace std;

// Default constructor
Bus::Bus()
{
    busId = "";
    busNumber = "";
    capacity = 0;
    availability = false;
    status = "";
}

// Parameterized constructor
Bus::Bus(string busId, string busNumber, int capacity,
         bool availability, string status)
{
    this->busId = busId;
    this->busNumber = busNumber;
    this->capacity = capacity;
    this->availability = availability;
    this->status = status;
}

// Get bus ID
string Bus::getBusId() const
{
    return busId;
}

// Get bus number
string Bus::getBusNumber() const
{
    return busNumber;
}

// Get bus capacity
int Bus::getCapacity() const
{
    return capacity;
}

// Check whether bus is available
bool Bus::isAvailable() const
{
    return availability;
}

// Get bus status
string Bus::getStatus() const
{
    return status;
}

// Set bus availability
void Bus::setAvailability(bool availability)
{
    this->availability = availability;
}

// Set bus status
void Bus::setStatus(string status)
{
    this->status = status;
}

// Display complete bus information
void Bus::displayBus() const
{
    cout << "Bus ID: " << busId << endl;
    cout << "Bus Number: " << busNumber << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Availability: "
         << (availability ? "Available" : "Not Available") << endl;
    cout << "Status: " << status << endl;
}

// Display bus status
void Bus::displayStatus() const
{
    cout << "Bus Number: " << busNumber << endl;
    cout << "Availability: "
         << (availability ? "Available" : "Not Available") << endl;
    cout << "Status: " << status << endl;
}