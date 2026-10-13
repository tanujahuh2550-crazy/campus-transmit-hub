#include <iostream>
#include <string>
#include <vector>
#include "../include/TransmitSystem.h"

using namespace std;

void TransmitSystem::run()
{
    int choice;

    do
    {
        mainMenu.display();
        choice = mainMenu.getChoice();

        switch(choice)
        {
            case 1: studentSection(); break;
            case 2: driverSection(); break;
            case 3: adminSection(); break;
            case 4: cout << "\nExiting Campus Transmit Hub...\n"; break;
            default: cout << "\nInvalid choice.\n";
        }

    } while(choice != 4);
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

        switch(choice)
        {
            case 1: studentLogin(); break;
            case 2: studentRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 3);
}

void TransmitSystem::studentRegistration()
{
    string id, name, password, course;
    int semester;

    cout << "\n--- Student Registration ---\n";
    cout << "Student ID: ";
    cin >> id;

    vector<Student> students = fileManager.readStudents();

    for(const Student& student : students)
    {
        if(student.getId() == id)
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

    if(semester < 1 || semester > 8)
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

    for(const Student& student : students)
    {
        if(student.getId() == id &&
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

        switch(choice)
        {
            case 1: driverLogin(); break;
            case 2: driverRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 3);
}

void TransmitSystem::driverRegistration()
{
    string id, name, password, license, busId;

    cout << "\n--- Driver Registration ---\n";
    cout << "Driver ID: ";
    cin >> id;

    vector<Driver> drivers = fileManager.readDrivers();

    for(const Driver& driver : drivers)
    {
        if(driver.getId() == id)
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

    for(const Driver& driver : drivers)
    {
        if(driver.getId() == id &&
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

        switch(choice)
        {
            case 1: adminLogin(); break;
            case 2: adminRegistration(); break;
            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 3);
}

void TransmitSystem::adminRegistration()
{
    string id, name, password, adminId;

    cout << "\n--- Admin Registration ---\n";
    cout << "Admin ID: ";
    cin >> id;

    vector<Admin> admins = fileManager.readAdmins();

    for(const Admin& admin : admins)
    {
        if(admin.getId() == id)
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

    for(const Admin& admin : admins)
    {
        if(admin.getId() == id &&
           admin.getPassword() == password)
        {
            cout << "Login successful!\n";
            cout << "Welcome, " << admin.getName() << "!\n";

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

        switch(choice)
        {
            case 1: busManagement(); break;
            case 2: routeManagement(); break;
            case 3: scheduleManagement(); break;
            case 4: notificationManagement(); break;
            case 5: reportManagement(); break;
            case 6: cout << "Logged out successfully.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 6);
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

        switch(choice)
        {
            case 1:
            {
                string id, number, status;
                int capacity, available;

                cout << "Bus ID: ";
                cin >> id;

                vector<Bus> buses = fileManager.readBuses();

                bool exists = false;

                for(const Bus& bus : buses)
                {
                    if(bus.getBusId() == id)
                    {
                        exists = true;
                        break;
                    }
                }

                if(exists)
                {
                    cout << "Bus ID already exists!\n";
                    break;
                }

                cout << "Bus Number: ";
                cin >> number;

                cout << "Capacity: ";
                cin >> capacity;

                if(capacity <= 0)
                {
                    cout << "Invalid capacity.\n";
                    break;
                }

                cout << "Available? (1 = Yes, 0 = No): ";
                cin >> available;

                if(available != 0 && available != 1)
                {
                    cout << "Invalid availability choice.\n";
                    break;
                }

                cout << "Status: ";
                cin >> status;

                Bus bus(id, number, capacity, available == 1, status);
                fileManager.writeBus(bus);

                cout << "Bus added successfully!\n";
                break;
            }

            case 2:
            {
                vector<Bus> buses = fileManager.readBuses();

                if(buses.empty())
                {
                    cout << "No buses found.\n";
                    break;
                }

                for(const Bus& bus : buses)
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

            case 3: break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 3);
}

// Other Modules

void TransmitSystem::routeManagement()
{
    cout << "\nRoute Management is coming next.\n";
}

void TransmitSystem::scheduleManagement()
{
    cout << "\nSchedule Management is coming next.\n";
}

void TransmitSystem::notificationManagement()
{
    cout << "\nNotification Management is coming next.\n";
}

void TransmitSystem::reportManagement()
{
    cout << "\nReport Management is coming next.\n";
}