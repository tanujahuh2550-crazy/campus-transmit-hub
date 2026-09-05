#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    string course;
    int semester;

public:
    Student();
    Student(string id, string name, string password,
            string course, int semester);

    string getCourse() const;
    int getSemester() const;

    void setCourse(string course);
    void setSemester(int semester);

    void displayInfo() const override;
};

#endif