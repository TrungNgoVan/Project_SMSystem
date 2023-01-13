#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{
    this->_studentID = "00000001";
}

Student::Student(string studentID){
    this->_studentID = studentID;
}

Student::~Student()
{
}

int Student::getType(){
    return 1;
}

string Student::getID()
{
    return this->_studentID;
}

string Student::getStudentID()
{
    return this->_studentID;
}

void Student::setStudentID(string studentID)
{
    this->_studentID = studentID;
}

bool Student::operator==(Student *other){
    bool result = true;
    if (this->_studentID != other->_studentID) result = false;
    return result;
}
