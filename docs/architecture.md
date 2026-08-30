# Campus Transmit Hub - Core Architecture

## Main Flow

main.cpp
    ↓
TransmitSystem
    ↓
Main Menu
    ↓
Student / Driver / Admin
    ↓
UserManager
    ↓
Login Authentication
    ↓
Role Dashboard

## Responsibilities

### TransmitSystem
- Controls the overall program flow
- Displays the main menu
- Handles navigation
- Opens Student, Driver and Admin dashboards

### UserManager
- Handles registration
- Handles login
- Validates user credentials
- Manages Student, Driver and Admin users

### Student
- Represents a student user

### Driver
- Represents a driver user

### Admin
- Represents an admin user

## UserManager Interface

bool loginStudent(string id, string password);

bool loginDriver(string id, string password);

bool loginAdmin(string id, string password);

bool registerStudent(string id, string name, string password);



## Bus Module
### Bus

Responsible for storing basic information about a bus.

Attributes:
- busId
- busNumber
- capacity
- availability
Main functions:
- getBusId()
- getBusNumber()
- getCapacity()
- isAvailable()
- setAvailability()
- displayBus()

### Route

Responsible for storing route information.

Attributes:
- routeId
- routeName
- stops
Main functions:
- getRouteId()
- getRouteName()
- getStops()
- displayRoute()
### Schedule

Responsible for storing bus schedule information.

Attributes:
- scheduleId
- busId
- routeId
- departureTime
Main functions:
- getScheduleId()
- getBusId()
- getRouteId()
- getDepartureTime()
- displaySchedule()

## Bus Module Operations

The Bus Module will provide:
- Bus search
- Route search
- Schedule viewing
- Bus sorting
- Availability checking




## File Handling Module

### FileManager

Responsible for reading and writing application data using text files.

Responsibilities:

- Read records from files
- Write new records to files
- Update existing records
- Delete records when required
- Maintain data between program runs

Data files:

- students.txt
- drivers.txt
- admins.txt
- buses.txt
- routes.txt
- schedules.txt
- notifications.txt
- reports.txt

Main functions:

- readStudents()
- writeStudent()
- readDrivers()
- readAdmins()
- readBuses()
- readRoutes()
- readSchedules()
- updateData()
- deleteData()

## Core System

### TransmitSystem

`TransmitSystem` is the main controller of the application.

Responsibilities:

- Start the application
- Display the main menu
- Handle user menu choices
- Open Student, Driver and Admin sections
- Connect UserManager with the menus
- Connect Bus Module with the menus
- Coordinate FileManager during integration
- Handle logout and return to the main menu
- Handle application exit

Main functions:

- run()
- displayMainMenu()
- studentSection()
- driverSection()
- adminSection()