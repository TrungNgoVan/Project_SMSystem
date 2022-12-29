#include <iostream> 
#include <string>
#include "SchoolManeger.h"

using namespace std;

SchoolManager::SchoolManager(){
    this->_scoreBoardStudent = map<string, vector<Score>>();
    this->_scoreBroadCourse = map<string, vector<Score>>();
    this->_dataCourse = vector<Course>();
    this->_dataScore = vector<Score>();
    this->_dataStudent = vector<Student>();
    this->_dataLecturer = vector<Lecturer>();
}

SchoolManager::~SchoolManager(){
    //Do nothing;
}

void SchoolManager::setScoreBoardStudent(map<string, vector<Score>> newMap){
    this->_scoreBoardStudent = newMap;
}

void SchoolManager::setScoreBoardCourse(map<string, vector<Score>> newMap){
    this->_scoreBroadCourse = newMap;
}

void SchoolManager::studentViewScoreBoard(Student* student){
    vector<Score> data = _scoreBoardStudent[student->getStudentID()];
    for (auto it: data){
        cout << it.gerCourseID() << "\n";
        it.displayScore();
    }
}

void SchoolManager::viewCourseBoard(Student* student){

}
