#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    this->_studentID = "00000001";
}

Student::~Student()
{
}

int Student::getType(){
    return 1;
}

string Student::getStudentID()
{
    return this->_studentID;
}

void Student::setStudentID(string studentID)
{
    this->_studentID = studentID;
}
