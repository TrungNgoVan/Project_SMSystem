#pragma once 
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
private:
    string _studentID;
public:
    Student();
    ~Student();
    int getType();
    string getStudentID();
    void setStudentID(string);
};
