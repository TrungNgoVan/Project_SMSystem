
#include <iostream>
#include "Course.h"

using namespace std;

Course::Course(){
    this->_courseID = "MTH00000";
    this->_courseID = "Test";
    this->_year = 2000;
    this->_semester = 1;
    this->_start = 0;
    this->_end = 0;
    this->_from = 0;
    this->_to = 0;
    this->_dayOfWeek = "Monday";
}

Course::~Course(){
    //Do nothing
}

string Course:: getCourseID(){
    return this->_courseID;
}

