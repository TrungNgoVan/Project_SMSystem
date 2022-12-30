#include <iostream>
#include <string>
#include "SchoolManeger.h"

using namespace std;

SchoolManager::SchoolManager()
{
    this->_scoreboardOfStudent = map<string, vector<Score>>();
    this->_listCourseOfStudent = map<string, vector<Course>>();
    this->_scoreboardOfCourse = map<string, vector<Score>>();
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

map<string, vector<Score>> SchoolManager::getScoreboardOfStudent()
{
    return this->_scoreboardOfStudent;
}
void SchoolManager::setScoreboardOfStudent(map<string, vector<Score>> newMap)
{
    this->_scoreboardOfStudent = newMap;
}

map<string, vector<Course>> SchoolManager::getListCourseOfStudent()
{
    return this->_listCourseOfStudent;
}
void SchoolManager::setListCourseOfStudent(map<string, vector<Course>> newMap)
{
    this->_listCourseOfStudent = newMap;
}

map<string, vector<Score>> SchoolManager::getScoreboardOfCourse()
{
    return this->_scoreboardOfCourse;
}
void SchoolManager::setScoreboardOfCourse(map<string, vector<Score>> newMap)
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

void SchoolManager::studentViewYourScoreboard(Student *student)
{
    vector<Score> data = this->_scoreboardOfStudent[student->getStudentID()];
    for (auto it : data)
    {
        cout << it.getCourseID() << "\n";
        it.displayScore();
    }
    cout << "--------------------\n";
}

void SchoolManager::studentViewYourListCourse(Student *student)
{
    vector<Course> data = this->_listCourseOfStudent[student->getStudentID()];
    for (auto it : data)
    {
        cout << it.getCourseID() << " - " << it.getCourseName() << "\n";
    }
    cout << "--------------------\n";
}

void SchoolManager::lecturerViewScoreboardOfCourse(Lecturer *lecturer, Course *course)
{
    if (lecturer->getLecturerID() != course->getLecturerID())
    {
        cout << "You can't access!"
             << "\n";
        cout << "--------------------\n";
    }
    else
    {
        vector<Score> data = this->_scoreboardOfCourse[course->getCourseID()];
        for (auto it : data)
        {
            cout << it.getCourseID() << "\n";
            it.displayScore();
        }
        cout << "--------------------\n";
    }
}

void SchoolManager::addStudent(Person *lecturer, Student *newStudent)
{
    if (lecturer->getType() != 2)
    {
        cout << "You can't access!"
             << "\n";
        cout << "--------------------\n";
    }
    else
    {
        this->_dataStudent.push_back(*newStudent);
        cout << "Done!"
             << "\n";
        cout << "--------------------\n";
    }
}
