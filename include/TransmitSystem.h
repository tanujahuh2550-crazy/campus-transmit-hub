#ifndef TRANSMITSYSTEM_H
#define TRANSMITSYSTEM_H

class TransmitSystem
{
public:
    void run();

private:
    void displayMainMenu();
    void studentSection();
    void driverSection();
    void adminSection();
};

#endif