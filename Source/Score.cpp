#include <iostream>
#include "Score.h"

using namespace std;

Score::Score()
{
    this->_year = -1;
    this->_semester = -1;
    this->_studentID = "";
    this->_courseID = "";
    this->_midtermScore = -1;
    this->_labScore = -1;
    this->_finalScore = -1;
}

Score::~Score()
{
}

Score::Score(string studentID, string courseID) : Score(){
    this->_studentID = studentID;
    this->_courseID = courseID;
}


Score::Score(int year, int semester, string studentID, string courseID, float midtermScore, float labScore, float finalScore)
{
    this->_year = year;
    this->_semester = semester;
    this->_studentID = studentID;
    this->_courseID = courseID;
    this->_midtermScore = midtermScore;
    this->_labScore = labScore;
    this->_finalScore = finalScore;
}

int Score::getYear()
{
    return this->_year;
}

void Score::setYear(int year)
{
    this->_year = year;
}

int Score::getSemester()
{
    return this->_semester;
}

void Score::setSemester(int semester)
{
    this->_semester = semester;
}

string Score::getStudentID()
{
    return this->_studentID;
}

void Score::setStudentID(string studentID)
{
    this->_studentID = studentID;
}

string Score::getCourseID()
{
    return this->_courseID;
}

void Score::setCourseID(string courseID)
{
    this->_courseID = courseID;
}

float Score::getMidtermScore()
{
    return this->_midtermScore;
}

void Score::setMidtermScore(float midtermScore)
{
    this->_midtermScore = midtermScore;
}

float Score::getLabScore()
{
    return this->_labScore;
}

void Score::setLabScore(float labScore)
{
    this->_labScore = labScore;
}

float Score::getFinalScore()
{
    return this->_finalScore;
}

void Score::setFinalScore(float finalScore)
{
    this->_finalScore = finalScore;
}

void Score::displayScore()
{
    cout << "Year: " << this->_year << endl;
    cout << "Semester: " << this->_semester << endl;
    cout << "Student ID: " << this->_studentID << endl;
    cout << "Course ID: " << this->_courseID << endl;
    cout << "Midterm Score: " << this->_midtermScore << endl;
    cout << "Lab Score: " << this->_labScore << endl;
    cout << "Final Score: " << this->_finalScore << endl;
}
