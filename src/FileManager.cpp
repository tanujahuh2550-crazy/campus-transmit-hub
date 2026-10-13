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

class FileManager
{
public:
    // General file handling
    bool writeData(const std::string& filename,
                   const std::vector<std::string>& data) const;

    bool appendData(const std::string& filename,
                    const std::string& data) const;

    std::vector<std::string> readData(
        const std::string& filename) const;

    bool fileExists(const std::string& filename) const;

    // Student
    std::vector<Student> readStudents() const;
    void writeStudent(const Student& student) const;

    // Driver
    std::vector<Driver> readDrivers() const;
    void writeDriver(const Driver& driver) const;

    // Admin
    std::vector<Admin> readAdmins() const;
    void writeAdmin(const Admin& admin) const;

    // Bus
    std::vector<Bus> readBuses() const;
    void writeBus(const Bus& bus) const;

    // Route
    std::vector<Route> readRoutes() const;
    void writeRoute(const Route& route) const;

    // Schedule
    std::vector<Schedule> readSchedules() const;
    void writeSchedule(const Schedule& schedule) const;

    // Notification
    std::vector<Notification> readNotifications() const;
    void writeNotification(const Notification& notification) const;

    // Report
    std::vector<Report> readReports() const;
    void writeReport(const Report& report) const;
};

#endif