#pragma once 
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
private:
    string _studentID;
public:
    Student();
    Student(string);
    ~Student();
    int getType();
    string getID();
    void setStudentID(string);
    bool operator==(Student *other);
};
