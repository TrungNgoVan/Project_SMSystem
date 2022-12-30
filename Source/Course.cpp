
#include <iostream>
#include "Course.h"

using namespace std;

Course::Course()
{
    this->_courseID = "MTH00000";
    this->_courseName = "Test";
    this->_lecturerID = "L0000001";
    this->_year = 2000;
    this->_semester = 1;
    this->_start = 0;
    this->_end = 0;
    this->_from = 0;
    this->_to = 0;
    this->_dayOfWeek = "Monday";
}

Course::~Course()
{
    // Do nothing
}

string Course::getCourseID()
{
    return this->_courseID;
}

string Course::getCourseName()
{
    return this->_courseName;
}
string Course::getLecturerID(){
    return this->_lecturerID;
}

void Course::setLecturerID(string lecturerID){
    this->_lecturerID = lecturerID;
}
