# Campus Transmit Hub - Architecture

## 1. Overview

Campus Transmit Hub is a C++17 console-based application for managing college bus information. It includes student, driver, and admin sections, along with options to manage buses, routes, schedules, notifications, and reports.

## 2. System Architecture

The application starts from `main.cpp`. The `TransmitSystem` class manages the program flow, while `FileManager` handles data storage.

```text
                       main.cpp
                           |
                           v
                    TransmitSystem
                           |
                           v
                       Main Menu
                           |
              +------------+------------+
              |            |            |
              v            v            v
           Student       Driver        Admin
           Section       Section       Section
              |            |            |
              v            v            v
         Registration  Registration  Registration
         and Login     and Login     and Login
                                        |
                                        v
                                 Admin Dashboard
                                        |
              +------------+------------+------------+------------+
              |            |            |            |            |
              v            v            v            v            v
             Bus         Route       Schedule    Notification   Report
          Management  Management   Management   Management   Management
              |            |            |            |            |
              +------------+------------+------------+------------+
                                        |
                                        v
                                    FileManager
                                        |
                                        v
                                    Text Files
```

## 3. Main Components

### TransmitSystem

`TransmitSystem` controls the main program flow and connects the different sections.

Important functions:

- `run()` — Starts the application.
- `studentSection()` — Opens the student menu.
- `driverSection()` — Opens the driver menu.
- `adminSection()` — Opens the admin menu.
- `studentLogin()` and `studentRegistration()` — Handle student login and registration.
- `driverLogin()` and `driverRegistration()` — Handle driver login and registration.
- `adminLogin()` and `adminRegistration()` — Handle admin login and registration.
- `adminDashboard()` — Displays the admin management options.

### MainMenu

Displays the main menu and allows users to select a section.

### Person, Student, Driver and Admin

`Person` is the base class for `Student`, `Driver`, and `Admin`. It stores common user details, such as ID, name, and password.

The three derived classes represent the different types of users and provide their own implementation of `displayInfo()`.

## 4. Management Modules

### Bus Management

The `Bus` class stores bus ID, bus number, capacity, availability, and status.

Important functions:
- `getBusId()`
- `getBusNumber()`
- `getCapacity()`
- `isAvailable()`
- `getStatus()`
- `displayBus()`

The admin can add buses and view their details.

### Route Management

The `Route` class stores route ID, route name, and stops.

Important functions:
- `getRouteId()`
- `getRouteName()`
- `getStops()`
- `displayRoute()`

The admin can add routes, define their stops, and view route details.

### Schedule Management

The `Schedule` class stores schedule ID, bus ID, route ID, and departure time.

Important functions:
- `getScheduleId()`
- `getBusId()`
- `getRouteId()`
- `getDepartureTime()`
- `displaySchedule()`

The admin can create and view schedules. Each schedule connects a bus with a route and departure time.

### Notification Management

The `Notification` class stores the notification ID, message, date, and target audience.

Important functions:
- `getNotificationId()`
- `getMessage()`
- `getDate()`
- `getTargetRole()`
- `displayInfo()`

The admin can add and view notifications for students, drivers, or all users.

### Report Management

The `Report` class stores the report ID, report type, generated date, and content.

The admin can generate reports and view saved report details.

## 5. File Handling

### FileManager

`FileManager` handles reading and writing data to text files. This allows the application to retain records between program runs.

The class provides functions for reading and writing records for the different modules.

### Data Files

| File | Purpose |
|---|---|
| `students.txt` | Stores student records |
| `drivers.txt` | Stores driver records |
| `admins.txt` | Stores admin records |
| `buses.txt` | Stores bus details |
| `routes.txt` | Stores route details and stops |
| `schedules.txt` | Stores schedule details |
| `notifications.txt` | Stores notification records |
| `reports.txt` | Stores report records |

## 6. Program Flow

1. The application starts from `main.cpp`.
2. `TransmitSystem` displays the main menu.
3. The user selects the student, driver, or admin section.
4. Students and drivers can register or log in.
5. After a successful admin login, the admin dashboard opens.
6. The admin selects a management module.
7. `FileManager` reads or writes the required data.
8. The user can return to the previous menu or exit the application.

## 7. Technologies Used

- C++17
- Object-Oriented Programming
- File Handling
- Git and GitHub
