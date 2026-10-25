#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../include/TransmitSystem.h"

using namespace std;

// Main System

void TransmitSystem::run()
{
    int choice;

    do
    {
        mainMenu.display();
        choice = mainMenu.getChoice();

        switch (choice)
        {
            case 1: studentSection(); break;
            case 2: driverSection(); break;
            case 3: adminSection(); break;
            case 4: cout << "\nExiting Campus Transmit Hub...\n"; break;
            default: cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);
}

// Student Section

void TransmitSystem::studentSection()
{
    int choice;

    do
    {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Login\n2. Register\n3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: studentLogin(); break;
            case 2: studentRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 3);
}

void TransmitSystem::studentRegistration()
{
    string id, name, password, course;
    int semester;

    cout << "\n--- Student Registration ---\n";
    cout << "Student ID: ";
    cin >> id;

    vector<Student> students = fileManager.readStudents();

    for (const Student& student : students)
    {
        if (student.getId() == id)
        {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cout << "Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Password: ";
    cin >> password;

    cout << "Course: ";
    cin >> course;

    cout << "Semester: ";
    cin >> semester;

    if (semester < 1 || semester > 8)
    {
        cout << "Invalid semester. Enter 1 to 8.\n";
        return;
    }

    Student student(id, name, password, course, semester);
    fileManager.writeStudent(student);

    cout << "Registration successful!\n";
}

void TransmitSystem::studentLogin()
{
    string id, password;

    cout << "\n--- Student Login ---\n";
    cout << "Student ID: ";
    cin >> id;

    cout << "Password: ";
    cin >> password;

    vector<Student> students = fileManager.readStudents();

    for (const Student& student : students)
    {
        if (student.getId() == id &&
            student.getPassword() == password)
        {
            cout << "Login successful!\n";
            cout << "Welcome, " << student.getName() << "!\n";
            cout << "Course: " << student.getCourse() << "\n";
            cout << "Semester: " << student.getSemester() << "\n";
            return;
        }
    }

    cout << "Invalid Student ID or Password.\n";
}

// Driver Section

void TransmitSystem::driverSection()
{
    int choice;

    do
    {
        cout << "\n--- Driver Menu ---\n";
        cout << "1. Login\n2. Register\n3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: driverLogin(); break;
            case 2: driverRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 3);
}

void TransmitSystem::driverRegistration()
{
    string id, name, password, license, busId;

    cout << "\n--- Driver Registration ---\n";
    cout << "Driver ID: ";
    cin >> id;

    vector<Driver> drivers = fileManager.readDrivers();

    for (const Driver& driver : drivers)
    {
        if (driver.getId() == id)
        {
            cout << "Driver ID already exists!\n";
            return;
        }
    }

    cout << "Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Password: ";
    cin >> password;

    cout << "License Number: ";
    cin >> license;

    cout << "Assigned Bus ID: ";
    cin >> busId;

    Driver driver(id, name, password, license, busId);
    fileManager.writeDriver(driver);

    cout << "Driver registration successful!\n";
}

void TransmitSystem::driverLogin()
{
    string id, password;

    cout << "\n--- Driver Login ---\n";
    cout << "Driver ID: ";
    cin >> id;

    cout << "Password: ";
    cin >> password;

    vector<Driver> drivers = fileManager.readDrivers();

    for (const Driver& driver : drivers)
    {
        if (driver.getId() == id &&
            driver.getPassword() == password)
        {
            cout << "Login successful!\n";
            cout << "Welcome, " << driver.getName() << "!\n";
            cout << "License: " << driver.getLicenseNumber() << "\n";
            cout << "Assigned Bus: " << driver.getAssignedBusId() << "\n";
            return;
        }
    }

    cout << "Invalid Driver ID or Password.\n";
}

// Admin Section

void TransmitSystem::adminSection()
{
    int choice;

    do
    {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Login\n2. Register\n3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: adminLogin(); break;
            case 2: adminRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 3);
}

void TransmitSystem::adminRegistration()
{
    string id, name, password, adminId;

    cout << "\n--- Admin Registration ---\n";
    cout << "Admin ID: ";
    cin >> id;

    vector<Admin> admins = fileManager.readAdmins();

    for (const Admin& admin : admins)
    {
        if (admin.getId() == id)
        {
            cout << "Admin ID already exists!\n";
            return;
        }
    }

    cout << "Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Password: ";
    cin >> password;

    cout << "Admin Identification Code: ";
    cin >> adminId;

    Admin admin(id, name, password, adminId);
    fileManager.writeAdmin(admin);

    cout << "Admin registration successful!\n";
}

void TransmitSystem::adminLogin()
{
    string id, password;

    cout << "\n--- Admin Login ---\n";
    cout << "Admin ID: ";
    cin >> id;

    cout << "Password: ";
    cin >> password;

    vector<Admin> admins = fileManager.readAdmins();

    for (const Admin& admin : admins)
    {
        if (admin.getId() == id &&
            admin.getPassword() == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << admin.getName() << "!\n";
            cout << "Opening Admin Dashboard...\n";
            cout.flush();

            adminDashboard();
            return;
        }
    }

    cout << "Invalid Admin ID or Password.\n";
}

// Admin Dashboard

void TransmitSystem::adminDashboard()
{
    int choice;

    do
    {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Bus Management\n";
        cout << "2. Route Management\n";
        cout << "3. Schedule Management\n";
        cout << "4. Notification Management\n";
        cout << "5. Report Management\n";
        cout << "6. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: busManagement(); break;
            case 2: routeManagement(); break;
            case 3: scheduleManagement(); break;
            case 4: notificationManagement(); break;
            case 5: reportManagement(); break;
            case 6: cout << "Logged out successfully.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);
}

// Bus Management

void TransmitSystem::busManagement()
{
    int choice;

    do
    {
        cout << "\n--- Bus Management ---\n";
        cout << "1. Add Bus\n2. View Buses\n3. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string id, number, status;
                int capacity, available;

                cout << "Bus ID: ";
                cin >> id;

                vector<Bus> buses = fileManager.readBuses();
                bool exists = false;

                for (const Bus& bus : buses)
                {
                    if (bus.getBusId() == id)
                    {
                        exists = true;
                        break;
                    }
                }

                if (exists)
                {
                    cout << "Bus ID already exists!\n";
                    break;
                }

                cout << "Bus Number: ";
                cin >> number;

                cout << "Capacity: ";
                cin >> capacity;

                if (capacity <= 0)
                {
                    cout << "Invalid capacity.\n";
                    break;
                }

                cout << "Available? (1 = Yes, 0 = No): ";
                cin >> available;

                if (available != 0 && available != 1)
                {
                    cout << "Invalid availability choice.\n";
                    break;
                }

                cout << "Status (Active/Inactive/Maintenance): ";
                cin >> status;

                Bus bus(id, number, capacity, available == 1, status);
                fileManager.writeBus(bus);

                cout << "Bus added successfully!\n";
                break;
            }

            case 2:
            {
                vector<Bus> buses = fileManager.readBuses();

                if (buses.empty())
                {
                    cout << "No buses found.\n";
                    break;
                }

                for (const Bus& bus : buses)
                {
                    cout << "\nBus ID: " << bus.getBusId() << "\n";
                    cout << "Number: " << bus.getBusNumber() << "\n";
                    cout << "Capacity: " << bus.getCapacity() << "\n";
                    cout << "Availability: "
                         << (bus.isAvailable() ? "Available" : "Unavailable")
                         << "\n";
                    cout << "Status: " << bus.getStatus() << "\n";
                }

                break;
            }

            case 3:
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 3);
}

// Route Management

void TransmitSystem::routeManagement()
{
    int choice;

    do
    {
        cout << "\n========== ROUTE MANAGEMENT ==========\n";
        cout << "1. Add Route\n";
        cout << "2. View Routes\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string routeId, routeName;
            vector<string> stops;
            int numberOfStops;

            cout << "\nEnter Route ID: ";
            cin >> routeId;

            vector<Route> routes = fileManager.readRoutes();
            bool exists = false;

            for (const Route& route : routes)
            {
                if (route.getRouteId() == routeId)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Route ID already exists!\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Route Name: ";
            getline(cin, routeName);

            cout << "Enter number of stops: ";
            cin >> numberOfStops;

            if (numberOfStops <= 0)
            {
                cout << "Number of stops must be greater than zero.\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = 0; i < numberOfStops; i++)
            {
                string stop;

                cout << "Enter stop " << i + 1 << ": ";
                getline(cin, stop);

                stops.push_back(stop);
            }

            Route route(routeId, routeName, stops);
            fileManager.writeRoute(route);

            cout << "Route added successfully!\n";
        }
        else if (choice == 2)
        {
            vector<Route> routes = fileManager.readRoutes();

            if (routes.empty())
            {
                cout << "No routes found.\n";
            }
            else
            {
                cout << "\n========== SAVED ROUTES ==========\n";

                for (const Route& route : routes)
                {
                    cout << "\nRoute ID: " << route.getRouteId() << endl;
                    cout << "Route Name: " << route.getRouteName() << endl;
                    cout << "Stops: ";

                    vector<string> stops = route.getStops();

                    for (int i = 0; i < stops.size(); i++)
                    {
                        cout << stops[i];

                        if (i < stops.size() - 1)
                            cout << " -> ";
                    }

                    cout << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Returning to Admin Dashboard...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}

// Schedule Management

void TransmitSystem::scheduleManagement()
{
    int choice;

    do
    {
        cout << "\n========== SCHEDULE MANAGEMENT ==========\n";
        cout << "1. Add Schedule\n";
        cout << "2. View Schedules\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string scheduleId, busId, routeId, departureTime;

            cout << "\nEnter Schedule ID: ";
            cin >> scheduleId;

            vector<Schedule> schedules = fileManager.readSchedules();
            bool exists = false;

            for (const Schedule& schedule : schedules)
            {
                if (schedule.getScheduleId() == scheduleId)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Schedule ID already exists!\n";
                continue;
            }

            cout << "Enter Bus ID: ";
            cin >> busId;

            vector<Bus> buses = fileManager.readBuses();
            bool busExists = false;

            for (const Bus& bus : buses)
            {
                if (bus.getBusId() == busId)
                {
                    busExists = true;
                    break;
                }
            }

            if (!busExists)
            {
                cout << "Bus ID not found! Add the bus first.\n";
                continue;
            }

            cout << "Enter Route ID: ";
            cin >> routeId;

            vector<Route> routes = fileManager.readRoutes();
            bool routeExists = false;

            for (const Route& route : routes)
            {
                if (route.getRouteId() == routeId)
                {
                    routeExists = true;
                    break;
                }
            }

            if (!routeExists)
            {
                cout << "Route ID not found! Add the route first.\n";
                continue;
            }

            cout << "Enter Departure Time (e.g. 08:30 AM): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, departureTime);

            Schedule schedule(
                scheduleId,
                busId,
                routeId,
                departureTime
            );

            fileManager.writeSchedule(schedule);

            cout << "Schedule added successfully!\n";
        }
        else if (choice == 2)
        {
            vector<Schedule> schedules = fileManager.readSchedules();

            if (schedules.empty())
            {
                cout << "No schedules found.\n";
            }
            else
            {
                cout << "\n========== SAVED SCHEDULES ==========\n";

                for (const Schedule& schedule : schedules)
                {
                    cout << "\nSchedule ID: "
                         << schedule.getScheduleId() << endl;
                    cout << "Bus ID: "
                         << schedule.getBusId() << endl;
                    cout << "Route ID: "
                         << schedule.getRouteId() << endl;
                    cout << "Departure Time: "
                         << schedule.getDepartureTime() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Returning to Admin Dashboard...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}

// Notification Management

void TransmitSystem::notificationManagement()
{
    int choice;

    do
    {
        cout << "\n========== NOTIFICATION MANAGEMENT ==========\n";
        cout << "1. Add Notification\n";
        cout << "2. View Notifications\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string notificationId, message, date, targetRole;

            cout << "\nEnter Notification ID: ";
            cin >> notificationId;

            vector<Notification> notifications =
                fileManager.readNotifications();

            bool exists = false;

            for (const Notification& notification : notifications)
            {
                if (notification.getNotificationId() == notificationId)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Notification ID already exists!\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Notification Message: ";
            getline(cin, message);

            cout << "Enter Date (e.g. 13-10-2026): ";
            getline(cin, date);

            cout << "\nSelect Target Role:\n";
            cout << "1. Student\n";
            cout << "2. Driver\n";
            cout << "3. All\n";
            cout << "Enter choice: ";

            int roleChoice;
            cin >> roleChoice;

            if (roleChoice == 1)
            {
                targetRole = "Student";
            }
            else if (roleChoice == 2)
            {
                targetRole = "Driver";
            }
            else if (roleChoice == 3)
            {
                targetRole = "All";
            }
            else
            {
                cout << "Invalid role choice!\n";
                continue;
            }

            Notification notification(
                notificationId,
                message,
                date,
                targetRole
            );

            fileManager.writeNotification(notification);

            cout << "\nNotification added successfully!\n";
        }
        else if (choice == 2)
        {
            vector<Notification> notifications =
                fileManager.readNotifications();

            if (notifications.empty())
            {
                cout << "\nNo notifications found.\n";
            }
            else
            {
                cout << "\n========== SAVED NOTIFICATIONS ==========\n";

                for (const Notification& notification : notifications)
                {
                    cout << "\nNotification ID: "
                         << notification.getNotificationId() << endl;

                    cout << "Message: "
                         << notification.getMessage() << endl;

                    cout << "Date: "
                         << notification.getDate() << endl;

                    cout << "Target Role: "
                         << notification.getTargetRole() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Returning to Admin Dashboard...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}

// Report Management

void TransmitSystem::reportManagement()
{
    int choice;

    do
    {
        cout << "\n========== REPORT MANAGEMENT ==========\n";
        cout << "1. Generate Report\n";
        cout << "2. View Reports\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string reportId, reportType, generatedDate, content;

            cout << "\nEnter Report ID: ";
            cin >> reportId;

            vector<Report> reports = fileManager.readReports();
            bool exists = false;

            for (const Report& report : reports)
            {
                if (report.getReportId() == reportId)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Report ID already exists!\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Report Type: ";
            getline(cin, reportType);

            cout << "Enter Generated Date: ";
            getline(cin, generatedDate);

            cout << "Enter Report Content: ";
            getline(cin, content);

            Report report(
                reportId,
                reportType,
                generatedDate,
                content
            );

            fileManager.writeReport(report);

            cout << "Report generated successfully!\n";
        }
        else if (choice == 2)
        {
            vector<Report> reports = fileManager.readReports();

            if (reports.empty())
            {
                cout << "No reports found.\n";
            }
            else
            {
                cout << "\n========== SAVED REPORTS ==========\n";

                for (const Report& report : reports)
                {
                    cout << "\nReport ID: "
                         << report.getReportId() << endl;
                    cout << "Report Type: "
                         << report.getReportType() << endl;
                    cout << "Generated Date: "
                         << report.getGeneratedDate() << endl;
                    cout << "Content: "
                         << report.getContent() << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Returning to Admin Dashboard...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);
}