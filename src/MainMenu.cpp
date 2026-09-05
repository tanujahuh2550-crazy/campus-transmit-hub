#include <iostream>
#include "../include/MainMenu.h"

using namespace std;

void MainMenu::display()
{
    cout << "\n========================================\n";
    cout << "          CAMPUS TRANSMIT HUB\n";
    cout << "========================================\n";
    cout << "1. Student\n";
    cout << "2. Driver\n";
    cout << "3. Admin\n";
    cout << "4. Exit\n";
    cout << "========================================\n";
}

int MainMenu::getChoice()
{
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}