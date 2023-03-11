#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person
{
private:
    string _studentID;
public:
    Student();
    Student(string);
    Student(string, string, string, string, string, string);
    ~Student();
    int getType();
    string getID();
    string getStudentID();
    void setStudentID(string);
    bool operator==(Student *other);
    bool operator!=(Student *other);
};
