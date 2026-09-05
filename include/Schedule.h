#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule {
private:
    string scheduleId;
    string busId;
    string routeId;
    string departureTime;

public:
    Schedule();
    Schedule(string scheduleId, string busId, string routeId,
             string departureTime);

    string getScheduleId() const;
    string getBusId() const;
    string getRouteId() const;
    string getDepartureTime() const;

    void setDepartureTime(string departureTime);

    void displaySchedule() const;
};

#endif