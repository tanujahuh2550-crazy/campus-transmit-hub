#include "../include/Student.h"
#include <iostream>
using namespace std;

Student::Student() : Person(), course(""), semester(0) {}

Student::Student(string id, string name, string password,
                 string course, int semester)
    : Person(id, name, password),
      course(course), semester(semester) {}

string Student::getCourse() const {
    return course;
}

int Student::getSemester() const {
    return semester;
}

void Student::setCourse(string course) {
    this->course = course;
}

void Student::setSemester(int semester) {
    this->semester = semester;
}

void Student::displayInfo() const {
    Person::displayInfo();
    cout << "Course: " << course << endl;
    cout << "Semester: " << semester << endl;
}