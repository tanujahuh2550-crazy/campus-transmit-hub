# Campus Transmit Hub

**Smart Bus Information & Route Management System**

Campus Transmit Hub is a C++ console-based project for managing college transportation. It has separate sections for students, drivers, and admins. The admin can manage bus details, routes, schedules, notifications, and reports.

## Building

Compile the project from the root directory:

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o CampusTransmitHub
```

Run on Linux or Git Bash:

```bash
./CampusTransmitHub
```

On Windows, run `CampusTransmitHub.exe`.

## How the code is organised

The application is divided into classes, with each class handling a specific part of the project.

```text
                 main.cpp
                    |
                    v
              TransmitSystem
                    |
                    v
                 Main Menu
                    |
          +---------+---------+
          |         |         |
          v         v         v
       Student    Driver     Admin
       Section    Section    Section
                               |
                               v
                       Admin Dashboard
                               |
          +----------+---------+---------+----------+
          |          |         |         |          |
          v          v         v         v          v
         Bus       Route    Schedule Notification Report
      Management Management Management Management Management
          |          |         |         |          |
          +----------+---------+---------+----------+
                               |
                               v
                           FileManager
                               |
                               v
                           Text Files
```

`TransmitSystem` handles the main program flow and menu navigation. `Person` stores common user details and is the base class for `Student`, `Driver`, and `Admin`.

`Bus`, `Route`, and `Schedule` store transportation details. `Notification` and `Report` handle notification and report information. `FileManager` reads and writes records to text files.

## Data Storage

The application uses separate text files to store records.

| File | Purpose |
|---|---|
| `students.txt` | Student records |
| `drivers.txt` | Driver records |
| `admins.txt` | Admin records |
| `buses.txt` | Bus details |
| `routes.txt` | Route information |
| `schedules.txt` | Schedule details |
| `notifications.txt` | Notification records |
| `reports.txt` | Report records |

## Project Structure

```text
CampusTransmitHub/
├── include/     # Header files
├── src/         # Source files
├── README.md
└── architecture.md
```
