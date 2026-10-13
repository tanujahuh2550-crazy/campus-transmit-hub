# Campus Transmit Hub

**Smart Bus Information & Route Management System**

Campus Transmit Hub is a C++17 console-based project for managing college transportation. It provides separate sections for students, drivers, and admins, with features for managing buses, routes, schedules, notifications, and reports.

## Building

Compile the project from the root directory:

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o CampusTransmitHub
```

Run the application:

```bash
./CampusTransmitHub
```

On Windows, run `CampusTransmitHub.exe`.

## How the code is organised

The project is divided into classes, with each class handling a specific part of the system.

```text
                 TransmitSystem
                       |
                   Main Menu
                       |
          +------------+------------+
          |            |            |
       Student       Driver        Admin
       Section       Section       Section
                                     |
                                     v
                              Admin Dashboard
                                     |
             +-----------+-----------+-----------+
             |           |           |           |
            Bus         Route      Schedule   Notifications
          Management  Management  Management  Management
                                     |
                                     v
                              Report Management
                                     |
                                     v
                                 FileManager
                                     |
                                     v
                                  Text Files
```

`TransmitSystem` handles the main menus and connects the different parts of the application. `Person` stores the common details shared by `Student`, `Driver`, and `Admin`.

The `Bus`, `Route`, and `Schedule` classes store transportation details. `Notification` and `Report` handle their respective records, while `FileManager` reads and writes data to text files.

## Data storage

The application stores its records in separate text files:

| File | Stores |
|---|---|
| `students.txt` | Student details |
| `drivers.txt` | Driver details |
| `admins.txt` | Admin details |
| `buses.txt` | Bus information |
| `routes.txt` | Routes and stops |
| `schedules.txt` | Bus schedules |
| `notifications.txt` | Transport notifications |
| `reports.txt` | Report records |

## Project files

- `src/` — C++ source files
- `include/` — Header files
- `docs/` — Project documentation
- `data/` — Data files
- `diagrams/` — Project diagrams
- `screenshots/` — Application screenshots
- `test/` — Tests
- `assets/` — Supporting files

For more details about the classes and their responsibilities, see [`architecture.md`](architecture.md).
