#pragma once 
#include <string>
#include "Person.h"

using namespace std;

class Student : Person {
private:
    string _studentID;
public:
    string getStudentID();
    void setStudentID(string);
};
