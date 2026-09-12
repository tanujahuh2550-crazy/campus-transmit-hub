#ifndef TRANSMITSYSTEM_H
#define TRANSMITSYSTEM_H

#include "MainMenu.h"

class TransmitSystem
{
public:
    void run();

private:
    void studentSection();
    void driverSection();
    void adminSection();

    MainMenu mainMenu;
};

#endif