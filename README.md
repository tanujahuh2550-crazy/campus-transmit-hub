# 🚍 Campus Transmit Hub

**Campus Transit Hub – Smart Bus Information & Route Management System**

A **console-based C++17 application** designed to centralize campus transportation information. Students can search and view buses, routes, schedules, and notifications, while authorized staff and drivers can manage transport information.

## 🎯 Objectives

* Centralize campus transport information
* Reduce confusion about bus schedules and availability
* Allow staff and drivers to update transport information
* Allow students to search buses and routes
* Store transport information using file handling
* Demonstrate C++ OOP concepts

## ✨ Features

* 🔐 User registration and login
* 🚌 Bus management
* 🛣️ Route and stop management
* 🕐 Bus schedules
* 👨‍✈️ Driver dashboard
* 📢 Transport notifications
* 📊 Daily, weekly, and monthly reports
* 🔎 Bus and route search
* ↕️ Sorting and availability checking
* 💾 File-based data storage
* ✅ Input validation and exception handling

## 👥 Team

| Member       | Responsibility                                                     |
| ------------ | ------------------------------------------------------------------ |
| **Kavya**    | Authentication, User Management & Notifications                    |
| **Yashasvi** | Bus & Route Management                                             |
| **Tanuja**   | File Handling & Reports                                            |
| **Deeya**    | Core Architecture, Main Menu, Integration, Testing & Documentation |

## 🛠️ Technology

* **Language:** C++17
* **Application:** Console-based
* **Compiler:** g++
* **IDE:** Visual Studio Code
* **Storage:** Text Files (`.txt`)
* **Version Control:** Git & GitHub

## 📂 Project Structure

```text id="w2w8u4"
CampusTransitHub/
│
├── docs/          # Project documentation
├── include/       # Header files
├── src/           # Source files
├── data/          # Text-based data storage
├── diagrams/      # UML and flowcharts
├── screenshots/   # Project screenshots
├── test/          # Testing files
├── assets/        # Supporting files
│
├── README.md
└── PROJECT_GUIDE.md
```

## 🏛️ Main Classes

```text id="1j3m4d"
User
├── Student
├── Driver
└── Admin

Bus
Route
Schedule
Notification
Report
FileManager
TransitSystem
```

The project uses **encapsulation, inheritance, polymorphism, constructors, function overloading/overriding, STL, file handling, and exception handling** where appropriate.

## 💾 Data Files

The application stores information using text files:

```text id="m8y3v5"
students.txt
drivers.txt
admins.txt
buses.txt
routes.txt
schedules.txt
notifications.txt
reports.txt
```

## 🔀 Git Workflow

Each team member works on their assigned feature branch.

```text id="k4p0dx"
main
├── feature/authentication-notifications
├── feature/bus-route
├── feature/file-report
└── feature/core-architecture
```

No direct commits are made to `main`. Completed features are tested and merged through Pull Requests.

## ▶️ How to Run

Clone the repository:

```bash id="1w9h5m"
git clone <repository-url>
cd CampusTransitHub
```

Compile:

```bash id="7y4q9p"
g++ -std=c++17 src/*.cpp -Iinclude -o CampusTransitHub
```

Run:

```bash id="g8x4n2"
./CampusTransitHub
```

On Windows:

```bash id="j2q7mw"
CampusTransitHub.exe
```

## 🚀 Future Scope

* GPS-based bus tracking
* Mobile application
* QR bus passes
* Push notifications
* Google Maps integration
* Live ETA
* RFID attendance
* Transport analytics

## 📌 Project Status

**Currently under development.**

> **Code like a team. Think like engineers. Build like it's a real product.**
