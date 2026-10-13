#include "../include/FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Split a record into fields
static vector<string> splitString(const string& text, char delimiter)
{
    vector<string> fields;
    string field;
    stringstream ss(text);

    while (getline(ss, field, delimiter))
        fields.push_back(field);

    if (!text.empty() && text.back() == delimiter)
        fields.push_back("");

    return fields;
}

// Join route stops
static string joinStops(const vector<string>& stops)
{
    string result;

    for (size_t i = 0; i < stops.size(); i++)
    {
        if (i > 0)
            result += ";";

        result += stops[i];
    }

    return result;
}

// General file handling

bool FileManager::writeData(const string& filename,
                            const vector<string>& data) const
{
    ofstream file(filename);

    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    for (const string& line : data)
        file << line << '\n';

    return file.good();
}

bool FileManager::appendData(const string& filename,
                             const string& data) const
{
    ofstream file(filename, ios::app);

    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    file << data << '\n';
    return file.good();
}

vector<string> FileManager::readData(const string& filename) const
{
    vector<string> data;
    ifstream file(filename);
    string line;

    if (!file)
    {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    while (getline(file, line))
        if (!line.empty())
            data.push_back(line);

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

    for (const string& record : readData("data/students.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 5)
        {
            cerr << "Invalid student record: " << record << endl;
            continue;
        }

        try
        {
            students.emplace_back(
                f[0], f[1], f[2], f[3], stoi(f[4])
            );
        }
        catch (const exception&)
        {
            cerr << "Invalid student data: " << record << endl;
        }
    }

    return students;
}

void FileManager::writeStudent(const Student& s) const
{
    string record = s.getId() + "|" + s.getName() + "|" +
                    s.getPassword() + "|" + s.getCourse() + "|" +
                    to_string(s.getSemester());

    appendData("data/students.txt", record);
}

// Driver

vector<Driver> FileManager::readDrivers() const
{
    vector<Driver> drivers;

    for (const string& record : readData("data/drivers.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 5)
        {
            cerr << "Invalid driver record: " << record << endl;
            continue;
        }

        drivers.emplace_back(f[0], f[1], f[2], f[3], f[4]);
    }

    return drivers;
}

void FileManager::writeDriver(const Driver& d) const
{
    string record = d.getId() + "|" + d.getName() + "|" +
                    d.getPassword() + "|" + d.getLicenseNumber() + "|" +
                    d.getAssignedBusId();

    appendData("data/drivers.txt", record);
}

// Admin

vector<Admin> FileManager::readAdmins() const
{
    vector<Admin> admins;

    for (const string& record : readData("data/admins.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 4)
        {
            cerr << "Invalid admin record: " << record << endl;
            continue;
        }

        admins.emplace_back(f[0], f[1], f[2], f[3]);
    }

    return admins;
}

void FileManager::writeAdmin(const Admin& a) const
{
    string record = a.getId() + "|" + a.getName() + "|" +
                    a.getPassword() + "|" + a.getAdminId();

    appendData("data/admins.txt", record);
}

// Bus

vector<Bus> FileManager::readBuses() const
{
    vector<Bus> buses;

    for (const string& record : readData("data/buses.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 5)
        {
            cerr << "Invalid bus record: " << record << endl;
            continue;
        }

        try
        {
            bool available;

            if (f[3] == "1" || f[3] == "true")
                available = true;
            else if (f[3] == "0" || f[3] == "false")
                available = false;
            else
            {
                cerr << "Invalid bus availability: " << record << endl;
                continue;
            }

            buses.emplace_back(
                f[0], f[1], stoi(f[2]), available, f[4]
            );
        }
        catch (const exception&)
        {
            cerr << "Invalid bus data: " << record << endl;
        }
    }

    return buses;
}

void FileManager::writeBus(const Bus& b) const
{
    string record = b.getBusId() + "|" + b.getBusNumber() + "|" +
                    to_string(b.getCapacity()) + "|" +
                    (b.isAvailable() ? "1" : "0") + "|" + b.getStatus();

    appendData("data/buses.txt", record);
}

// Route

vector<Route> FileManager::readRoutes() const
{
    vector<Route> routes;

    for (const string& record : readData("data/routes.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 3)
        {
            cerr << "Invalid route record: " << record << endl;
            continue;
        }

        vector<string> stops;

        if (!f[2].empty())
            stops = splitString(f[2], ';');

        routes.emplace_back(f[0], f[1], stops);
    }

    return routes;
}

void FileManager::writeRoute(const Route& r) const
{
    string record = r.getRouteId() + "|" + r.getRouteName() + "|" +
                    joinStops(r.getStops());

    appendData("data/routes.txt", record);
}

// Schedule

vector<Schedule> FileManager::readSchedules() const
{
    vector<Schedule> schedules;

    for (const string& record : readData("data/schedules.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 4)
        {
            cerr << "Invalid schedule record: " << record << endl;
            continue;
        }

        schedules.emplace_back(f[0], f[1], f[2], f[3]);
    }

    return schedules;
}

void FileManager::writeSchedule(const Schedule& s) const
{
    string record = s.getScheduleId() + "|" + s.getBusId() + "|" +
                    s.getRouteId() + "|" + s.getDepartureTime();

    appendData("data/schedules.txt", record);
}

// Notification

vector<Notification> FileManager::readNotifications() const
{
    vector<Notification> notifications;

    for (const string& record : readData("data/notifications.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 4)
        {
            cerr << "Invalid notification record: " << record << endl;
            continue;
        }

        notifications.emplace_back(f[0], f[1], f[2], f[3]);
    }

    return notifications;
}

void FileManager::writeNotification(const Notification& n) const
{
    string record = n.getNotificationId() + "|" + n.getMessage() +
                    "|" + n.getDate() + "|" + n.getTargetRole();

    appendData("data/notifications.txt", record);
}

// Report

vector<Report> FileManager::readReports() const
{
    vector<Report> reports;

    for (const string& record : readData("data/reports.txt"))
    {
        vector<string> f = splitString(record, '|');

        if (f.size() != 4)
        {
            cerr << "Invalid report record: " << record << endl;
            continue;
        }

        reports.emplace_back(f[0], f[1], f[2], f[3]);
    }

    return reports;
}

void FileManager::writeReport(const Report& r) const
{
    string record = r.getReportId() + "|" + r.getReportType() + "|" +
                    r.getGeneratedDate() + "|" + r.getContent();

    appendData("data/reports.txt", record);
}