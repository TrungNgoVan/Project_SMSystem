#include <iostream>
#include "Staff.h"
#include "SchoolManager.h"



using namespace std;

Staff::Staff()
{
    this->_staffID = "S0000001";
}

Staff::Staff(string staffID)
{
    this->_staffID = staffID;
}

// staffID,userName,password,fullName,email,phoneNumber
Staff::Staff(string staffID, string userName, string password, string fullName, string email, string phoneNumber)
    : Person(userName, password, fullName, email, phoneNumber)
{
    this->_staffID = staffID;
}

Staff::~Staff()
{
}

int Staff::getType()
{
    return 3;
}

string Staff::getID()
{
    return this->_staffID;
}

string Staff::getStaffID()
{
    return this->_staffID;
}

void Staff::setStaffID(string staffID)
{
    this->_staffID = staffID;
}

void Staff::viewProfile()
{
    cout << "Staff ID: " << this->_staffID << endl;
    cout << "Full name: " << this->getFullName() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "Phone number: " << this->getPhoneNumber() << endl;
}

void Staff::viewListStudent()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    map<string, Student> students = schoolManager->getDataStudent();
    map<string, Student>::iterator it;
    for (it = students.begin(); it != students.end(); it++)
    {
        cout << "Student ID: " << it->second.getID() << endl;
        cout << "Full name: " << it->second.getFullName() << endl;
        cout << "Email: " << it->second.getEmail() << endl;
        cout << "Phone number: " << it->second.getPhoneNumber() << endl;
        cout << "\n";
    }
    if (students.size() == 0)
    {
        cout << "There is no student in the system" << endl;
    }
}

void Staff::viewListCourse()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    map<string, Course> courses = schoolManager->getDataCourse();
    map<string, Course>::iterator it;
    for (it = courses.begin(); it != courses.end(); it++)
    {
        cout << "Course ID: " << it->second.getCourseID() << "\n";
        cout << "Course name: " << it->second.getCourseName() << "\n";
    }
    if (courses.size() == 0)
    {
        cout << "There is no course in the system" << endl;
    }
}

void Staff::viewListLecturer()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    map<string, Lecturer> lecturers = schoolManager->getDataLecturer();
    map<string, Lecturer>::iterator it;
    for (it = lecturers.begin(); it != lecturers.end(); it++)
    {
        cout << "Lecturer ID: " << it->second.getID() << endl;
        cout << "Full name: " << it->second.getFullName() << endl;
        cout << "Email: " << it->second.getEmail() << endl;
        cout << "Phone number: " << it->second.getPhoneNumber() << endl;
        cout << "\n";
    }
    if (lecturers.size() == 0)
    {
        cout << "There is no lecturer in the system" << endl;
    }
}

bool Staff::operator==(Staff *other)
{
    bool result = true;
    if (this->_staffID != other->_staffID)
        result = false;
    return result;
}
