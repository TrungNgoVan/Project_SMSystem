#include <iostream>
#include "Student.h"
#include "Header.h"

using namespace std;

Student::Student()
{
    this->_studentID = "00000001";
}

Student::Student(string studentID)
{
    this->_studentID = studentID;
}

Student::Student(string studentID, string userName, string password, string fullName, string email, string phoneNumber)
    : Person(userName, password, fullName, email, phoneNumber)
{
    this->_studentID = studentID;
}

Student::~Student()
{
}

int Student::getType()
{
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

void Student::viewProfile()
{
    cout << "Student ID: " << this->getID() << endl;
    cout << "Full name: " << this->getFullName() << endl;
    cout << "Email: " << this->getEmail() << endl;
    cout << "Phone number: " << this->getPhoneNumber() << endl;
    cout << "\n";
}

void Student::viewCourse()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    ScoreManager *score = schoolManager->getDataScore();
    map<string, Course> courses = schoolManager->getDataCourse();
    if (courses.size() == 0)
    {
        cout << "No course available" << endl;
    }
    else
    {
        for (auto i : score->getCoursesIDByStudentID(this->getID()))
        {
            courses[i].displayCourse();
        }
    }

    // free memory
    courses.clear();
}

void Student::viewScore()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    ScoreManager *score = schoolManager->getDataScore();
    vector<Score *> scores = score->getScoreByStudentID(this->getID());
    if (scores.size() == 0)
    {
        cout << "No score available" << endl;
    }
    else
    {
        for (auto i : scores)
        {
            i->displayScore();
        }
    }
}

bool Student::operator==(Student *other)
{
    bool result = true;
    if (this->_studentID != other->_studentID)
        result = false;
    return result;
}

bool Student::operator!=(Student *other)
{
    bool result = true;
    if (this->_studentID == other->_studentID)
        result = false;
    return result;
}
