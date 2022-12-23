#include <iostream>
#include "Lecturer.h"

using namespace std;

string Lecturer::getLecturerID(){
    return this->_lecturerID;
}

void Lecturer::setLecturerID(string lecturerID){
    this->_lecturerID = lecturerID;
}
