#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

class Route {
private:
    string routeId;
    string routeName;
    vector<string> stops;

public:
    Route();
    Route(string routeId, string routeName, vector<string> stops);

    string getRouteId() const;
    string getRouteName() const;
    vector<string> getStops() const;

    void setRouteName(string routeName);
    void setStops(vector<string> stops);

    void displayRoute() const;
};

#endif