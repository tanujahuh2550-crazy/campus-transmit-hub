#ifndef BUS_H
#define BUS_H

#include <string>
using namespace std;

class Bus {
private:
    string busId;
    string busNumber;
    int capacity;
    bool availability;
    string status;

public:
    Bus();
    Bus(string busId, string busNumber, int capacity,
        bool availability, string status);

    string getBusId() const;
    string getBusNumber() const;
    int getCapacity() const;
    bool isAvailable() const;
    string getStatus() const;

    void setAvailability(bool availability);
    void setStatus(string status);

    void displayBus() const;
    void displayStatus() const;
};

#endif