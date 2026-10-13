#ifndef TRANSMITSYSTEM_H
#define TRANSMITSYSTEM_H

#include "MainMenu.h"
#include "Student.h"
#include "Driver.h"
#include "Admin.h"
#include "FileManager.h"

class TransmitSystem
{
public:
    void run();

private:
    void studentSection();
    void driverSection();
    void adminSection();

    void studentLogin();
    void studentRegistration();

    void driverLogin();
    void driverRegistration();
    void adminLogin();

    MainMenu mainMenu;
    FileManager fileManager;
};

#endif