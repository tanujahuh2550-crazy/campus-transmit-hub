# 🚍 Campus Transmit Hub

**Campus Transmit Hub – Smart Bus Information & Route Management System**

A **console-based C++17 application** for managing campus transportation. Students can view buses, routes, schedules, and notifications, while authorized staff can manage transport information.

## ✨ Features

* 🔐 User registration and login
* 🚌 Bus and route management
* 🕐 Schedule management
* 👨‍✈️ Driver dashboard
* 📢 Transport notifications
* 🔎 Bus and route search
* ↕️ Sorting and availability checking
* 📊 Transport reports
* 💾 File-based data storage
* ✅ Input validation and exception handling

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
TransmitSystem
```

The project demonstrates **OOP, STL, inheritance, file handling, searching, sorting, validation, and modular programming**.

## 📂 Project Structure

```text
CampusTransmitHub/
├── docs/
├── include/
├── src/
├── data/
├── diagrams/
├── screenshots/
├── test/
├── assets/
├── README.md
└── PROJECT_GUIDE.md
```

## 👥 Team

| Member       | Responsibility                                          |
| ------------ | ------------------------------------------------------- |
| **Deeya**    | Core Architecture, Integration, Testing & Documentation |
| **Kavya**    | Authentication, User Management & Notifications         |
| **Yashasvi** | Bus & Route Management                                  |
| **Tanuja**   | File Handling & Reports                                 |

## 🛠️ Tech Stack

* **C++17**
* **g++**
* **Visual Studio Code**
* **Git & GitHub**
* **Text files for storage**

## 🔀 Git Workflow

Each feature is developed on a separate branch and merged into `main` through a Pull Request after testing.

```text
main
├── feature/core-architecture
├── feature/authentication-notifications
├── feature/bus-route
└── feature/file-report
```

## ▶️ How to Run

```bash
git clone <repository-url>
cd CampusTransmitHub
g++ -std=c++17 src/*.cpp -Iinclude -o CampusTransmitHub
./CampusTransmitHub
```

**Windows:**

```bash
CampusTransmitHub.exe
```

## 🚀 Future Scope

* GPS-based tracking
* Mobile application
* QR bus passes
* Live ETA
* Transport analytics
