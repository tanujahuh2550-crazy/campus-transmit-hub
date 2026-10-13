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

// Student Section

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

// Student Registration

void TransmitSystem::studentRegistration()
{
    string id, name, password, course;
    int semester;

    cout << "\n========== STUDENT REGISTRATION ==========\n";

    cout << "Enter Student ID: ";
    cin >> id;

    // Check whether the ID is already registered
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
    cin.ignore();
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

// Student Login

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

// Driver Section

void TransmitSystem::driverSection()
{
    int choice;

    do
    {
        cout << "\n========== DRIVER MENU ==========\n";
        cout << "1. Login\n";
        cout << "2. Back to Main Menu\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nDriver Login selected.\n";
                break;

            case 2:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 2);
}

// Admin Section

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
                cout << "\nAdmin Login selected.\n";
                break;

            case 2:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 2);
}