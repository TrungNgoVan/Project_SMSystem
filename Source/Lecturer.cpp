#include <iostream>
#include "Lecturer.h"
#include "SchoolManager.h"

using namespace std;

Lecturer::Lecturer()
{
    this->_lecturerID = "L0000001";
}

Lecturer::Lecturer(string lecturerID)
{
    this->_lecturerID = lecturerID;
}

// lecturerID,userName,password,fullName,email,phoneNumber
Lecturer::Lecturer(string lecturerID, string userName, string password, string fullName, string email, string phoneNumber)
    : Person(userName, password, fullName, email, phoneNumber)
{
    this->_lecturerID = lecturerID;
}

Lecturer::~Lecturer()
{
}

int Lecturer::getType()
{
    return 2;
}

string Lecturer::getID()
{
    return this->_lecturerID;
}

string Lecturer::getLecturerID()
{
    return this->_lecturerID;
}

void Lecturer::setLecturerID(string lecturerID)
{
    this->_lecturerID = lecturerID;
}

void Lecturer::viewProfile()
{
    cout << "Lecturer ID: " << this->_lecturerID << endl;
    cout << "Full name: " << this->getFullName() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "Phone number: " << this->getPhoneNumber() << endl;
}

void Lecturer::viewCourse()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    map<string, Course> courses = schoolManager->getDataCourse();
    map<string, Course>::iterator it;
    bool check = false;
    for (it = courses.begin(); it != courses.end(); it++)
    {
        if (it->second.getLecturerID() == this->_lecturerID)
        {
            check = true;
            cout << "Course ID: " << it->second.getCourseID() << endl;
            cout << "Course name: " << it->second.getCourseName() << endl;
            cout << "Course lecturer: " << it->second.getLecturerID() << endl;
            cout << "Course semester: " << it->second.getSemester() << endl;
            cout << "Course year: " << it->second.getYear() << endl;
            cout << "\n";
        }
    }
    if (!check)
        cout << "You don't have any course\n";
}

bool Lecturer::operator==(Lecturer *other)
{
    bool result = true;
    if (this->_lecturerID != other->_lecturerID)
        result = false;
    return result;
}
