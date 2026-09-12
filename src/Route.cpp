#include "../include/Route.h"
#include <iostream>

using namespace std;

// Default constructor
Route::Route()
{
    routeId = "";
    routeName = "";
    stops.clear();
}

// Parameterized constructor
Route::Route(string routeId, string routeName, vector<string> stops)
{
    this->routeId = routeId;
    this->routeName = routeName;
    this->stops = stops;
}

// Get route ID
string Route::getRouteId() const
{
    return routeId;
}

// Get route name
string Route::getRouteName() const
{
    return routeName;
}

// Get stops
vector<string> Route::getStops() const
{
    return stops;
}

// Set route name
void Route::setRouteName(string routeName)
{
    this->routeName = routeName;
}

// Set stops
void Route::setStops(vector<string> stops)
{
    this->stops = stops;
}

// Display route details
void Route::displayRoute() const
{
    cout << "Route ID: " << routeId << endl;
    cout << "Route Name: " << routeName << endl;

    cout << "Stops: ";

    if (stops.empty())
    {
        cout << "No stops";
    }
    else
    {
        for (size_t i = 0; i < stops.size(); i++)
        {
            cout << stops[i];

            if (i < stops.size() - 1)
            {
                cout << " -> ";
            }
        }
    }

    cout << endl;
}