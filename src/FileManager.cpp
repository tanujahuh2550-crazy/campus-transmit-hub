#include "../include/FileManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Helper function to split a string using a delimiter
static vector<string> splitString(const string& text, char delimiter)
{
    vector<string> result;
    string item;
    stringstream ss(text);

    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }

    // Preserve an empty final field when the record ends with a delimiter
    if (!text.empty() && text.back() == delimiter)
    {
        result.push_back("");
    }

    return result;
}

// Helper function to join route stops
static string joinStops(const vector<string>& stops)
{
    string result;

    for (size_t i = 0; i < stops.size(); i++)
    {
        if (i > 0)
        {
            result += ";";
        }

        result += stops[i];
    }

    return result;
}

// General file handling

bool FileManager::writeData(
    const string& filename,
    const vector<string>& data) const
{
    ofstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file for writing: "
             << filename << endl;
        return false;
    }

    for (const string& line : data)
    {
        file << line << '\n';
    }

    return file.good();
}

bool FileManager::appendData(
    const string& filename,
    const string& data) const
{
    ofstream file(filename, ios::app);

    if (!file)
    {
        cerr << "Error: Unable to open file for appending: "
             << filename << endl;
        return false;
    }

    file << data << '\n';

    return file.good();
}

vector<string> FileManager::readData(
    const string& filename) const
{
    vector<string> data;
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file for reading: "
             << filename << endl;
        return data;
    }

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            data.push_back(line);
        }
    }

    return data;
}

bool FileManager::fileExists(const string& filename) const
{
    ifstream file(filename);
    return file.good();
}

// Student

vector<Student> FileManager::readStudents() const
{
    vector<Student> students;
    vector<string> records = readData("data/students.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 5)
        {
            cerr << "Invalid student record: " << record << endl;
            continue;
        }

        try
        {
            Student student(
                fields[0],
                fields[1],
                fields[2],
                fields[3],
                stoi(fields[4])
            );

            students.push_back(student);
        }
        catch (...)
        {
            cerr << "Error reading student record: "
                 << record << endl;
        }
    }

    return students;
}

void FileManager::writeStudent(const Student& student) const
{
    string record =
        student.getId() + "|" +
        student.getName() + "|" +
        student.getPassword() + "|" +
        student.getCourse() + "|" +
        to_string(student.getSemester());

    appendData("data/students.txt", record);
}

// Driver

vector<Driver> FileManager::readDrivers() const
{
    vector<Driver> drivers;
    vector<string> records = readData("data/drivers.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 5)
        {
            cerr << "Invalid driver record: " << record << endl;
            continue;
        }

        Driver driver(
            fields[0],
            fields[1],
            fields[2],
            fields[3],
            fields[4]
        );

        drivers.push_back(driver);
    }

    return drivers;
}

void FileManager::writeDriver(const Driver& driver) const
{
    string record =
        driver.getId() + "|" +
        driver.getName() + "|" +
        driver.getPassword() + "|" +
        driver.getLicenseNumber() + "|" +
        driver.getAssignedBusId();

    appendData("data/drivers.txt", record);
}

// Admin

vector<Admin> FileManager::readAdmins() const
{
    vector<Admin> admins;
    vector<string> records = readData("data/admins.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 4)
        {
            cerr << "Invalid admin record: " << record << endl;
            continue;
        }

        Admin admin(
            fields[0],
            fields[1],
            fields[2],
            fields[3]
        );

        admins.push_back(admin);
    }

    return admins;
}

void FileManager::writeAdmin(const Admin& admin) const
{
    string record =
        admin.getId() + "|" +
        admin.getName() + "|" +
        admin.getPassword() + "|" +
        admin.getAdminId();

    appendData("data/admins.txt", record);
}

// Bus

vector<Bus> FileManager::readBuses() const
{
    vector<Bus> buses;
    vector<string> records = readData("data/buses.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 5)
        {
            cerr << "Invalid bus record: " << record << endl;
            continue;
        }

        try
        {
            bool availability;

            if (fields[3] == "1" || fields[3] == "true")
            {
                availability = true;
            }
            else if (fields[3] == "0" || fields[3] == "false")
            {
                availability = false;
            }
            else
            {
                cerr << "Invalid bus availability: "
                     << record << endl;
                continue;
            }

            Bus bus(
                fields[0],
                fields[1],
                stoi(fields[2]),
                availability,
                fields[4]
            );

            buses.push_back(bus);
        }
        catch (...)
        {
            cerr << "Error reading bus record: "
                 << record << endl;
        }
    }

    return buses;
}

void FileManager::writeBus(const Bus& bus) const
{
    string record =
        bus.getBusId() + "|" +
        bus.getBusNumber() + "|" +
        to_string(bus.getCapacity()) + "|" +
        (bus.isAvailable() ? "1" : "0") + "|" +
        bus.getStatus();

    appendData("data/buses.txt", record);
}

// Route

vector<Route> FileManager::readRoutes() const
{
    vector<Route> routes;
    vector<string> records = readData("data/routes.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 3)
        {
            cerr << "Invalid route record: " << record << endl;
            continue;
        }

        vector<string> stops = splitString(fields[2], ';');

        if (fields[2].empty())
        {
            stops.clear();
        }

        Route route(
            fields[0],
            fields[1],
            stops
        );

        routes.push_back(route);
    }

    return routes;
}

void FileManager::writeRoute(const Route& route) const
{
    string record =
        route.getRouteId() + "|" +
        route.getRouteName() + "|" +
        joinStops(route.getStops());

    appendData("data/routes.txt", record);
}

// Schedule

vector<Schedule> FileManager::readSchedules() const
{
    vector<Schedule> schedules;
    vector<string> records = readData("data/schedules.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 4)
        {
            cerr << "Invalid schedule record: "
                 << record << endl;
            continue;
        }

        Schedule schedule(
            fields[0],
            fields[1],
            fields[2],
            fields[3]
        );

        schedules.push_back(schedule);
    }

    return schedules;
}

void FileManager::writeSchedule(const Schedule& schedule) const
{
    string record =
        schedule.getScheduleId() + "|" +
        schedule.getBusId() + "|" +
        schedule.getRouteId() + "|" +
        schedule.getDepartureTime();

    appendData("data/schedules.txt", record);
}

// Notification

vector<Notification> FileManager::readNotifications() const
{
    vector<Notification> notifications;
    vector<string> records = readData("data/notifications.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 4)
        {
            cerr << "Invalid notification record: "
                 << record << endl;
            continue;
        }

        Notification notification(
            fields[0],
            fields[1],
            fields[2],
            fields[3]
        );

        notifications.push_back(notification);
    }

    return notifications;
}

void FileManager::writeNotification(
    const Notification& notification) const
{
    string record =
        notification.getNotificationId() + "|" +
        notification.getMessage() + "|" +
        notification.getDate() + "|" +
        notification.getTargetRole();

    appendData("data/notifications.txt", record);
}

// Report

vector<Report> FileManager::readReports() const
{
    vector<Report> reports;
    vector<string> records = readData("data/reports.txt");

    for (const string& record : records)
    {
        vector<string> fields = splitString(record, '|');

        if (fields.size() != 4)
        {
            cerr << "Invalid report record: " << record << endl;
            continue;
        }

        Report report(
            fields[0],
            fields[1],
            fields[2],
            fields[3]
        );

        reports.push_back(report);
    }

    return reports;
}

void FileManager::writeReport(const Report& report) const
{
    string record =
        report.getReportId() + "|" +
        report.getReportType() + "|" +
        report.getGeneratedDate() + "|" +
        report.getContent();

    appendData("data/reports.txt", record);
}
