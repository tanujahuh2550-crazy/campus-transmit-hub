# campus-transmit-hub

# PROJECT_GUIDE.md

# 🚍 Campus Transit Hub

**Version:** 1.0
**Project Type:** Object-Oriented Programming (C++) Mini Application
**Team Size:** 4 Members

---

# 📌 Project Overview

## Project Title

**Campus Transit Hub – Smart Bus Information & Route Management System**

## Problem Statement

Students often face confusion regarding college bus schedules, half-day buses, cancelled buses, route modifications, and transport notices. Currently, this information is shared informally through WhatsApp groups, drivers, or friends, making it unreliable and time-consuming.

Campus Transit Hub provides a centralized platform where transport administrators and drivers can update transport information, allowing students to access the latest bus schedules and notifications.

---

# 🎯 Objectives

* Centralize campus transport information.
* Reduce confusion regarding bus availability.
* Allow transport staff to update bus status.
* Allow students to search buses and routes.
* Store transport information using file handling.
* Demonstrate OOP concepts in C++.

---

# 👥 Team Members

| Member   | Module                                               |
| -------- | ---------------------------------------------------- |
| Kavya    | Authentication & User Management                     |
| Yashasvi | Bus & Route Management                               |
| Tanuja   | File Handling, Integration, Main Menu, Documentation |
| Deeya    | Driver Dashboard, Notifications & Reports            |

---

# 🛠 Technology Stack

* Language: C++17
* IDE: Visual Studio Code
* Compiler: g++
* Version Control: Git & GitHub
* Storage: Text Files (.txt)
* Type: Console Application

---

# 📂 Proposed Folder Structure

```text
CampusTransitHub/

│
├── docs/
│   ├── Proposal.md
│   ├── SRS.md
│   ├── PPT/
│   ├── UML/
│   └── FinalReport/
│
├── include/
│
├── src/
│
├── data/
│
├── diagrams/
│
├── screenshots/
│
├── test/
│
├── assets/
│
├── README.md
│
└── PROJECT_GUIDE.md
```

---

# 🏛 Coding Standards

## Naming Convention

### Classes

Use PascalCase

Example

```cpp
class Bus
class Student
class Driver
```

### Variables

Use camelCase

```cpp
busNumber
driverName
routeName
```

### Functions

Use camelCase

```cpp
displayBus()

searchRoute()

updateStatus()
```

### Constants

```cpp
MAX_BUSES
```

---

# 📁 File Naming

Header

```text
Bus.h
```

Source

```text
Bus.cpp
```

Never

```text
buscode.cpp

newBus.cpp

busFinal.cpp
```

---

# 💬 Comment Style

Every function should have a short description.

Example

```cpp
// Displays all available buses.
```

---

# 📦 OOP Concepts to Demonstrate

* Classes & Objects
* Constructors
* Copy Constructor
* Destructor
* Inheritance
* Polymorphism
* Function Overloading
* Function Overriding
* Virtual Functions
* Friend Function (where meaningful)
* Operator Overloading
* File Handling
* Exception Handling
* STL
* Function Templates

---

# 📂 Project Modules

## Authentication

* Login
* Logout
* Change Password
* User Validation

---

## Bus Module

* Add Bus
* Delete Bus
* Update Bus
* Search Bus
* View Bus Details

---

## Route Module

* Add Route
* Update Route
* Search Route
* Display Stops

---

## Driver Dashboard

* View Assigned Bus
* Update Bus Status
* Update Route Changes

---

## Notification Module

* Create Notification
* Display Notifications
* Delete Notification

---

## Report Module

* Daily Report
* Weekly Report
* Monthly Report

---

## File Handling

* Save Data
* Load Data
* Update Records
* Delete Records

---

# 📄 Data Files

```text
students.txt

drivers.txt

admins.txt

buses.txt

routes.txt

notifications.txt

reports.txt
```

---

# 🔀 Git Workflow

## Branches

```text
main

authentication

bus-module

driver-module

integration
```

Each member works only on their assigned branch.

No direct commits to `main`.

---

# ✅ Commit Message Format

Examples

```text
feat: added bus search

fix: corrected login validation

docs: updated proposal

refactor: improved route class
```

---

# 🤖 AI Usage Guidelines

Before asking any AI for code, include:

* Project Overview
* Module Name
* Existing Class Names
* Coding Standards
* C++17
* Console Application
* No Global Variables
* Modular Code
* Header and Source Files
* Use STL where appropriate

Never ask AI to generate the entire project in one prompt.

Generate one class or one feature at a time.

---

# 📋 Development Workflow

1. Finalize documentation.
2. Design class architecture.
3. Create UML diagrams.
4. Create GitHub repository.
5. Create folder structure.
6. Create empty header and source files.
7. Develop modules independently.
8. Integrate modules.
9. Test.
10. Fix bugs.
11. Prepare presentation.
12. Final demonstration.

---

# 🧪 Testing Checklist

* Login
* Bus Search
* Route Search
* Driver Dashboard
* Notifications
* Reports
* File Saving
* File Loading
* Exception Handling

---

# 📊 Documentation Checklist

* Problem Statement
* Objectives
* Existing System
* Proposed System
* Features
* Scope
* Future Scope
* UML Diagrams
* Flowchart
* Screenshots
* Test Cases
* Conclusion

---

# 🚀 Future Scope

* GPS Tracking
* Mobile Application
* QR Bus Pass
* Push Notifications
* Google Maps Integration
* Live ETA
* RFID Attendance
* Analytics Dashboard

---

# 📜 Team Rules

1. Work only on your assigned module.
2. Push code frequently.
3. Pull latest changes before coding.
4. Follow coding standards.
5. Do not rename shared classes/functions without discussion.
6. Test your module before pushing.
7. Document every major feature.
8. Ask before changing another member's code.

---

# 🎯 Goal

Build a clean, modular, scalable C++ application that demonstrates object-oriented programming concepts while solving a real campus transportation problem.

> **"Code like a team. Think like engineers. Build like it's a real product."**
