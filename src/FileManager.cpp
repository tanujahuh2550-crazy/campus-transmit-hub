#include "../include/FileManager.h"
#include <fstream>
#include <sstream>

using namespace std;

bool FileManager::writeData(const string& filename,
                            const vector<string>& data) const
{
    ofstream file(filename);

    if (!file.is_open())
        return false;

    for (const string& line : data)
        file << line << endl;

    return true;
}

bool FileManager::appendData(const string& filename,
                             const string& data) const
{
    ofstream file(filename, ios::app);

    if (!file.is_open())
        return false;

    file << data << endl;
    return true;
}

vector<string> FileManager::readData(const string& filename) const
{
    vector<string> data;
    ifstream file(filename);
    string line;

    while (getline(file, line))
        data.push_back(line);

    return data;
}

bool FileManager::fileExists(const string& filename) const
{
    ifstream file(filename);
    return file.good();
}

vector<Student> FileManager::readStudents() const
{
    vector<Student> students;
    vector<string> data = readData("students.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, name, password, course, semester;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, password, '|');
        getline(ss, course, '|');
        getline(ss, semester, '|');

        try
        {
            students.push_back(Student(id, name, password, course, stoi(semester)));
        }
        catch (...)
        {
            continue;
        }
    }

    return students;
}

void FileManager::writeStudent(const Student& student) const
{
    string data = student.getId() + "|" + student.getName() + "|" +
                  student.getPassword() + "|" + student.getCourse() + "|" +
                  to_string(student.getSemester());

    appendData("students.txt", data);
}

vector<Driver> FileManager::readDrivers() const
{
    vector<Driver> drivers;
    vector<string> data = readData("drivers.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, name, password, license, busId;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, password, '|');
        getline(ss, license, '|');
        getline(ss, busId, '|');

        drivers.push_back(Driver(id, name, password, license, busId));
    }

    return drivers;
}

void FileManager::writeDriver(const Driver& driver) const
{
    string data = driver.getId() + "|" + driver.getName() + "|" +
                  driver.getPassword() + "|" + driver.getLicenseNumber() + "|" +
                  driver.getAssignedBusId();

    appendData("drivers.txt", data);
}

vector<Admin> FileManager::readAdmins() const
{
    vector<Admin> admins;
    vector<string> data = readData("admins.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, name, password, adminId;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, password, '|');
        getline(ss, adminId, '|');

        admins.push_back(Admin(id, name, password, adminId));
    }

    return admins;
}

void FileManager::writeAdmin(const Admin& admin) const
{
    string data = admin.getId() + "|" + admin.getName() + "|" +
                  admin.getPassword() + "|" + admin.getAdminId();

    appendData("admins.txt", data);
}

vector<Bus> FileManager::readBuses() const
{
    vector<Bus> buses;
    vector<string> data = readData("buses.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, number, capacity, availability, status;

        getline(ss, id, '|');
        getline(ss, number, '|');
        getline(ss, capacity, '|');
        getline(ss, availability, '|');
        getline(ss, status, '|');

        try
        {
            buses.push_back(Bus(id, number, stoi(capacity),
                                availability == "1", status));
        }
        catch (...)
        {
            continue;
        }
    }

    return buses;
}

void FileManager::writeBus(const Bus& bus) const
{
    string data = bus.getBusId() + "|" + bus.getBusNumber() + "|" +
                  to_string(bus.getCapacity()) + "|" +
                  (bus.isAvailable() ? "1" : "0") + "|" + bus.getStatus();

    appendData("buses.txt", data);
}

vector<Route> FileManager::readRoutes() const
{
    vector<Route> routes;
    vector<string> data = readData("routes.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, name, stopsText, stop;
        vector<string> stops;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, stopsText, '|');

        stringstream stopStream(stopsText);

        while (getline(stopStream, stop, ';'))
            stops.push_back(stop);

        routes.push_back(Route(id, name, stops));
    }

    return routes;
}

void FileManager::writeRoute(const Route& route) const
{
    string stopsText;
    vector<string> stops = route.getStops();

    for (size_t i = 0; i < stops.size(); i++)
    {
        if (i > 0)
            stopsText += ";";

        stopsText += stops[i];
    }

    string data = route.getRouteId() + "|" + route.getRouteName() + "|" +
                  stopsText;

    appendData("routes.txt", data);
}

vector<Schedule> FileManager::readSchedules() const
{
    vector<Schedule> schedules;
    vector<string> data = readData("schedules.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, busId, routeId, departureTime;

        getline(ss, id, '|');
        getline(ss, busId, '|');
        getline(ss, routeId, '|');
        getline(ss, departureTime, '|');

        schedules.push_back(Schedule(id, busId, routeId, departureTime));
    }

    return schedules;
}

void FileManager::writeSchedule(const Schedule& schedule) const
{
    string data = schedule.getScheduleId() + "|" + schedule.getBusId() +
                  "|" + schedule.getRouteId() + "|" +
                  schedule.getDepartureTime();

    appendData("schedules.txt", data);
}

vector<Notification> FileManager::readNotifications() const
{
    vector<Notification> notifications;
    vector<string> data = readData("notifications.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, message, date, targetRole;

        getline(ss, id, '|');
        getline(ss, message, '|');
        getline(ss, date, '|');
        getline(ss, targetRole, '|');

        notifications.push_back(Notification(id, message, date, targetRole));
    }

    return notifications;
}

void FileManager::writeNotification(const Notification& notification) const
{
    string data = notification.getId() + "|" + notification.getMessage() +
                  "|" + notification.getDate() + "|" +
                  notification.getTargetRole();

    appendData("notifications.txt", data);
}

vector<Report> FileManager::readReports() const
{
    vector<Report> reports;
    vector<string> data = readData("reports.txt");

    for (const string& line : data)
    {
        stringstream ss(line);
        string id, type, date, content;

        getline(ss, id, '|');
        getline(ss, type, '|');
        getline(ss, date, '|');
        getline(ss, content, '|');

        reports.push_back(Report(id, type, date, content));
    }

    return reports;
}

void FileManager::writeReport(const Report& report) const
{
    string data = report.getReportId() + "|" + report.getReportType() +
                  "|" + report.getGeneratedDate() + "|" + report.getContent();

    appendData("reports.txt", data);
}