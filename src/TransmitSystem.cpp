#include <iostream>
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
                cout << "\nStudent Login selected.\n";
                break;

            case 2:
                cout << "\nStudent Registration selected.\n";
                break;

            case 3:
                cout << "\nReturning to Main Menu...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while(choice != 3);
}


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