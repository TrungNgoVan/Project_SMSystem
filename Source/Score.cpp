#include <iostream>
#include "Score.h"

using namespace std;

Score::Score()
{
    this->_year = 2000;
    this->_semester = 1;
    this->_studentID = "00000000";
    this->_courseID = "MTH00000";
    this->_midtermScore = 0;
    this->_labScore = 0;
    this->_finalScore = 0;
}

Score::~Score()
{
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
    cout << "Year: " << this->_year << " Semester: " << this->_semester << " Student ID: " << this->_studentID 
    << " Course ID: " << this->_courseID << " Midterm score: " << this->_midtermScore << " Lab score: " << this->_labScore 
    << " Final score: " << this->_finalScore << endl;
}
