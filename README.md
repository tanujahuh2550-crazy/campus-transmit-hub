# 🚍 Campus Transit Hub

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
| **Deeya**    | Core Architecture, Main Menu, Integration, Testing & Documentation |
| **Kavya**    | Authentication, User Management & Notifications                    |
| **Yashasvi** | Bus & Route Management                                             |
| **Tanuja**   | File Handling & Reports                                            |

## 🛠️ Technology

* **Language:** C++17
* **Application:** Console-based
* **Compiler:** g++
* **IDE:** Visual Studio Code
* **Storage:** Text Files (`.txt`)
* **Version Control:** Git & GitHub

## 📂 Project Structure

```text
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

```text
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

The project demonstrates **OOP concepts, STL, file handling, exception handling, searching, sorting, validation, and modular programming** where appropriate.

## 💾 Data Files

```text
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

Each team member works on an assigned feature branch.

```text
main
├── feature/core-architecture
├── feature/authentication-notifications
├── feature/bus-route
└── feature/file-report
```

No direct commits are made to `main`. Completed features are tested and merged through Pull Requests.

## ▶️ How to Run

Clone the repository:

```bash
git clone <repository-url>
cd CampusTransitHub
```

Compile:

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o CampusTransitHub
```

Run:

```bash
./CampusTransitHub
```

On Windows:

```bash
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
