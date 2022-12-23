#include <iostream>
#include "Student.h"

using namespace std;

string Student::getStudentID(){
    return this->_studentID;
}

void Student::setStudentID(string studentID){
    this->_studentID = studentID;
}
