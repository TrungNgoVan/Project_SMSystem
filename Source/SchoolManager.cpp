#include <iostream>
#include <string>
#include "SchoolManeger.h"

using namespace std;

SchoolManager::SchoolManager()
{
    this->_scoreboardOfStudent = map<string, vector<pair<Course, vector<Score>>>>();
    this->_scoreboardOfCourse = map<string, vector<pair<Student, vector<Score>>>>();
    this->_dataCourse = vector<Course>();
    this->_dataScore = vector<Score>();
    this->_dataStudent = vector<Student>();
    this->_dataLecturer = vector<Lecturer>();
}

SchoolManager::~SchoolManager()
{
    // Do nothing;
}

//-------------------
//- GETTER & SETTER -
//-------------------

map<string, vector<pair<Course, vector<Score>>>> SchoolManager::getScoreboardOfStudent()
{
    return this->_scoreboardOfStudent;
}
void SchoolManager::setScoreboardOfStudent(map<string, vector<pair<Course, vector<Score>>>> newMap)
{
    this->_scoreboardOfStudent = newMap;
}

map<string, vector<pair<Student, vector<Score>>>> SchoolManager::getScoreboardOfCourse()
{
    return this->_scoreboardOfCourse;
}
void SchoolManager::setScoreboardOfCourse(map<string, vector<pair<Student, vector<Score>>>> newMap)
{
    this->_scoreboardOfCourse = newMap;
}

vector<Course> SchoolManager::getDataCourse()
{
    return this->_dataCourse;
}

void SchoolManager::setDataCourse(vector<Course> newData)
{
    this->_dataCourse = newData;
}

vector<Score> SchoolManager::getDataScore()
{
    return this->_dataScore;
}

void SchoolManager::setDataScore(vector<Score> newData)
{
    this->_dataScore = newData;
}

vector<Student> SchoolManager::getDataStudent()
{
    return this->_dataStudent;
}

void SchoolManager::setDataStudent(vector<Student> newData)
{
    this->_dataStudent = newData;
}

vector<Lecturer> SchoolManager::getDataLecturer()
{
    return this->_dataLecturer;
}

void SchoolManager::setDataLecturer(vector<Lecturer> newData)
{
    this->_dataLecturer = newData;
}

vector<Staff> SchoolManager::getDataStaff()
{
    return this->_dataStaff;
}

void SchoolManager::setDataStaff(vector<Staff> newData)
{
    this->_dataStaff = newData;
}

//-------------------
//----- FEATURE -----
//-------------------

void SchoolManager::studentViewYourScoreboard(Person *student)
{
    if (student->getType() == Type::studentCode)
    {
        cout << "Student " << student->getID() << " view their scoreboard!\n";
        vector<pair<Course, vector<Score>>> data = this->_scoreboardOfStudent[student->getID()];
        for (auto it : data)
        {
            cout << it.first.getCourseID() << "\n";
            for (auto score : it.second)
            {
                score.displayScore();
            }
        }
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::studentViewYourListCourse(Person *student)
{
    if (student->getType() == Type::studentCode)
    {
        cout << "Student " << student->getID() << " view their list course!\n";
        vector<pair<Course, vector<Score>>> data = this->_scoreboardOfStudent[student->getID()];
        for (auto it : data)
        {
            cout << it.first.getCourseID() << "\n";
        }
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::studentCourseRegistration(Person *student)
{
}

void SchoolManager::lecturerViewScoreboardOfCourse(Person *lecturer, Course *course)
{
    if (lecturer->getType() == Type::lecturerCode)
    {
        cout << "Lecturer " << lecturer->getID() << " view scoreboard of course " << course->getCourseID() << " ! \n";
        if (lecturer->getID() != course->getLecturerID())
        {
            cout << "You can't access!\n";
            cout << "--------------------\n";
        }
        else
        {
            cout << course->getCourseID() << "\n";
            vector<pair<Student, vector<Score>>> data = this->_scoreboardOfCourse[course->getCourseID()];
            for (auto it : data)
            {
                cout << it.first.getID() << "\n";
                for (auto score : it.second)
                {
                    if (score.getCourseID() == course->getCourseID())
                    {
                        score.displayScore();
                        break;
                    }
                }
            }
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

// void SchoolManager::lecturerUpdateScoreOfStudent(){}

void SchoolManager::staffAddStudent(Person *staff, Person *newStudent)
{
    if (staff->getType() == Type::staffCode)
    {
        if (newStudent->getType() == Type::studentCode)
        {
            cout << "Staff " << staff->getID() << " add student " << newStudent->getID() << " to data!\n";
            auto it = find(this->_dataStudent.begin(), this->_dataStudent.end(), dynamic_cast<Student *>(newStudent));
            if (it == this->_dataStudent.end())
            {
                // Add the student to the data
                this->_dataStudent.push_back(*dynamic_cast<Student *>(newStudent));
                cout << "Done!\n";
                cout << "--------------------\n";
            }
            else
            {
                cout << "This student exists!\n";
                cout << "--------------------\n";
            }
        }
        else
        {
            cout << "Type error!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffRemoveStudent(Person *staff, Person *student)
{
    if (staff->getType() == Type::staffCode)
    {
        if (student->getType() == Type::studentCode)
        {
            cout << "Staff " << staff->getID() << " remove student " << student->getID() << " from data!\n";
            auto it = find(this->_dataStudent.begin(), this->_dataStudent.end(), dynamic_cast<Student *>(student));
            if (it != this->_dataStudent.end())
            {
                // Add the student to the data
                this->_dataStudent.erase(it);
                cout << "Done!\n";
                cout << "--------------------\n";
            }
            else
            {
                cout << "This student does not exist!\n";
                cout << "--------------------\n";
            }
        }
        else
        {
            cout << "Type error!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffTransferStudent(Person *staff, Person *student, Course *courseA, Course *courseB)
{
    if (staff->getType() == Type::staffCode)
    {
        if (student->getType() == Type::studentCode)
        {
            cout << "Staff " << staff->getID() << " transfer student " << student->getID() << " from course " << courseA->getCourseID() << " to course " << courseB->getCourseID() << " !\n";
            auto it = find(this->_dataStudent.begin(), this->_dataStudent.end(), dynamic_cast<Student *>(student));
            if (it != this->_dataStudent.end())
            {
                // Add the student to the data
                vector<pair<Course, vector<Score>>> data = this->_scoreboardOfStudent[student->getID()];
                for (auto it : data)
                {
                    if (it.first.getCourseID() == courseA->getCourseID())
                    {
                        it.first = *courseB;
                        cout << "Done!\n";
                        cout << "--------------------\n";
                        return;
                    }
                }
                cout << "This student does not exist in this course!\n";
                cout << "--------------------\n";
            }
            else
            {
                cout << "This student does not exist!\n";
                cout << "--------------------\n";
            }
        }
        else
        {
            cout << "Type error!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffAddCourse(Person *staff, Course *newCourse)
{
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " add course " << newCourse->getCourseID() << " to data!\n";
        auto it = find(this->_dataCourse.begin(), this->_dataCourse.end(), newCourse);
        if (it == this->_dataCourse.end())
        {
            // Add the course to the data
            this->_dataCourse.push_back(*newCourse);
            cout << "Done!\n";
            cout << "--------------------\n";
        }
        else
        {
            cout << "This course exists!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffRemoveCourse(Person *staff, Course *course)
{
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " remove course " << course->getCourseID() << " from data!\n";
        auto it = find(this->_dataCourse.begin(), this->_dataCourse.end(), course);
        if (it != this->_dataCourse.end())
        {
            // Add the course to the data
            this->_dataCourse.erase(it);
            cout << "Done!\n";
            cout << "--------------------\n";
        }
        else
        {
            cout << "This course does not exist!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffViewListCourses(Person *staff)
{
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " view list courses!\n";
        for (auto it : this->_dataCourse)
        {
            cout << it.getCourseID() << " " << it.getCourseName() << " " << it.getYear() << " "
                 << it.getSemester() << " " << endl;
        }
        cout << "Done!\n";
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}
