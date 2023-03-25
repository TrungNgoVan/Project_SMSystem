
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

Course::Course(string courseID, string courseName, string lecturerID){
    this->_courseID = courseID;
    this->_courseName = courseName;
    this->_lecturerID = lecturerID;
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
string Course::getLecturerID()
{
    return this->_lecturerID;
}

int Course::getYear()
{
    return this->_year;
}

int Course::getSemester()
{
    return this->_semester;
}

void Course::setLecturerID(string lecturerID)
{
    this->_lecturerID = lecturerID;
}

void Course::displayCourse()
{
    cout << "Course ID: " << this->getCourseID() << endl;
    cout << "Course name: " << this->getCourseName() << endl;
    cout << "Lecturer ID: " << this->getLecturerID() << endl;
    cout << "Year: " << this->getYear() << endl;
    cout << "Semester: " << this->getSemester() << endl;
    cout << "\n";
}

bool Course::operator==(Course *other)
{
    bool result = true;
    if (this->getCourseID() != other->getCourseID()) result = false;
    return result;
}
