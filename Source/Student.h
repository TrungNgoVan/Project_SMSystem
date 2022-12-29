#pragma once 
#include <string>
#include "Person.h"

using namespace std;

class Student : Person {
private:
    string _studentID;
public:
    Student();
    ~Student();
    string getStudentID();
    void setStudentID(string);
};
