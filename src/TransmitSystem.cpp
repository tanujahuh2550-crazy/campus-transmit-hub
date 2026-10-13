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
            case 1:
                studentSection();
                break;

            case 2:
                driverSection();
                break;

            case 3:
                adminSection();
                break;

            case 4:
                cout << "\nExiting Campus Transmit Hub...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 4);
}

// ==================== STUDENT SECTION ====================

void TransmitSystem::studentSection()
{
    int choice;

    do
    {
        cout << "\n========== STUDENT MENU ==========\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Back to Main Menu\n";
        cout << "==================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                studentLogin();
                break;

            case 2:
                studentRegistration();
                break;

            case 3:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 3);
}

// ==================== STUDENT REGISTRATION ====================

void TransmitSystem::studentRegistration()
{
    string id, name, password, course;
    int semester;

    cout << "\n========== STUDENT REGISTRATION ==========\n";

    cout << "Enter Student ID: ";
    cin >> id;

    vector<Student> students = fileManager.readStudents();

    for(const Student& student : students)
    {
        if(student.getId() == id)
        {
            cout << "\nStudent ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Course: ";
    cin >> course;

    cout << "Enter Semester: ";
    cin >> semester;

    if(semester < 1 || semester > 8)
    {
        cout << "\nInvalid semester!\n";
        return;
    }

    Student student(id, name, password, course, semester);

    fileManager.writeStudent(student);

    cout << "\nRegistration completed successfully!\n";
}

// ==================== STUDENT LOGIN ====================

void TransmitSystem::studentLogin()
{
    string id, password;

    cout << "\n========== STUDENT LOGIN ==========\n";

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    vector<Student> students = fileManager.readStudents();

    for(const Student& student : students)
    {
        if(student.getId() == id &&
           student.getPassword() == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << student.getName() << "!\n";
            cout << "Course: " << student.getCourse() << "\n";
            cout << "Semester: " << student.getSemester() << "\n";
            return;
        }
    }

    cout << "\nInvalid Student ID or Password.\n";
}

// ==================== DRIVER SECTION ====================

void TransmitSystem::driverSection()
{
    int choice;

    do
    {
        cout << "\n========== DRIVER MENU ==========\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Back to Main Menu\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                driverLogin();
                break;

            case 2:
                driverRegistration();
                break;

            case 3:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 3);
}

// ==================== DRIVER REGISTRATION ====================

void TransmitSystem::driverRegistration()
{
    string id, name, password, license, busId;

    cout << "\n========== DRIVER REGISTRATION ==========\n";

    cout << "Enter Driver ID: ";
    cin >> id;

    vector<Driver> drivers = fileManager.readDrivers();

    for(const Driver& driver : drivers)
    {
        if(driver.getId() == id)
        {
            cout << "\nDriver ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, name);

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter License Number: ";
    cin >> license;

    cout << "Enter Assigned Bus ID: ";
    cin >> busId;

    Driver driver(id, name, password, license, busId);

    fileManager.writeDriver(driver);

    cout << "\nDriver registered successfully!\n";
}

// ==================== DRIVER LOGIN ====================

void TransmitSystem::driverLogin()
{
    string id, password;

    cout << "\n========== DRIVER LOGIN ==========\n";

    cout << "Enter Driver ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    vector<Driver> drivers = fileManager.readDrivers();

    for(const Driver& driver : drivers)
    {
        if(driver.getId() == id &&
           driver.getPassword() == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << driver.getName() << "!\n";
            cout << "License: " << driver.getLicenseNumber() << "\n";
            cout << "Assigned Bus: " << driver.getAssignedBusId() << "\n";
            return;
        }
    }

    cout << "\nInvalid Driver ID or Password.\n";
}

// ==================== ADMIN SECTION ====================

void TransmitSystem::adminSection()
{
    int choice;

    do
    {
        cout << "\n========== ADMIN MENU ==========\n";
        cout << "1. Login\n";
        cout << "2. Back to Main Menu\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                adminLogin();
                break;

            case 2:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 2);
}

// ==================== ADMIN LOGIN ====================

void TransmitSystem::adminLogin()
{
    string id, password;

    cout << "\n========== ADMIN LOGIN ==========\n";

    cout << "Enter Admin ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    vector<Admin> admins = fileManager.readAdmins();

    for(const Admin& admin : admins)
    {
        if(admin.getId() == id &&
           admin.getPassword() == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << admin.getName() << "!\n";
            cout << "Admin ID: " << admin.getAdminId() << "\n";
            return;
        }
    }

    cout << "\nInvalid Admin ID or Password.\n";
}