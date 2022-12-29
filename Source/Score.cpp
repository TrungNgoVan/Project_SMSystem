#include <iostream>
#include "Score.h"

using namespace std;

Score::Score(){
    this->_year = 2000;
    this->_semester = 1;
    this->_courseID = "MTH00000";
    this->_midtermScore = 0;
    this->_labScore = 0;
    this->_finalScore = 0;
}

Score::~Score(){
    
}

int Score::getYear(){
    return this->_year;
}

void Score::setYear(int year){
    this->_year = year;
}

string Score::gerCourseID(){
    return this->_courseID;
}

void Score::displayScore(){
    cout << "Midterm score: " << this->_midtermScore << "\n";
    cout << "Lab score: " << this->_labScore << "\n";
    cout << "Final score: " << this->_finalScore << "\n";
}



