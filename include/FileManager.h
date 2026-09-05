#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

#include "Student.h"
#include "Driver.h"
#include "Admin.h"
#include "Bus.h"
#include "Route.h"
#include "Schedule.h"
#include "Notification.h"
#include "Report.h"

using namespace std;

class FileManager {
public:
    // Student
    vector<Student> readStudents() const;
    void writeStudent(const Student& student) const;

    // Driver
    vector<Driver> readDrivers() const;
    void writeDriver(const Driver& driver) const;

    // Admin
    vector<Admin> readAdmins() const;
    void writeAdmin(const Admin& admin) const;

    // Bus
    vector<Bus> readBuses() const;
    void writeBus(const Bus& bus) const;

    // Route
    vector<Route> readRoutes() const;
    void writeRoute(const Route& route) const;

    // Schedule
    vector<Schedule> readSchedules() const;
    void writeSchedule(const Schedule& schedule) const;

    // Notification
    vector<Notification> readNotifications() const;
    void writeNotification(const Notification& notification) const;

    // Report
    vector<Report> readReports() const;
    void writeReport(const Report& report) const;
};

#endif