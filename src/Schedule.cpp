#include "../include/Schedule.h"
#include <iostream>

using namespace std;

// Default constructor
Schedule::Schedule()
{
    scheduleId = "";
    busId = "";
    routeId = "";
    departureTime = "";
}

// Parameterized constructor
Schedule::Schedule(string scheduleId, string busId, string routeId, string departureTime)
{
    this->scheduleId = scheduleId;
    this->busId = busId;
    this->routeId = routeId;
    this->departureTime = departureTime;
}

// Getter for schedule ID
string Schedule::getScheduleId() const
{
    return scheduleId;
}

// Getter for bus ID
string Schedule::getBusId() const
{
    return busId;
}

// Getter for route ID
string Schedule::getRouteId() const
{
    return routeId;
}

// Getter for departure time
string Schedule::getDepartureTime() const
{
    return departureTime;
}

// Setter for departure time
void Schedule::setDepartureTime(string departureTime)
{
    this->departureTime = departureTime;
}

// Display schedule details
void Schedule::displaySchedule() const
{
    cout << "Schedule ID: " << scheduleId << endl;
    cout << "Bus ID: " << busId << endl;
    cout << "Route ID: " << routeId << endl;
    cout << "Departure Time: " << departureTime << endl;
}