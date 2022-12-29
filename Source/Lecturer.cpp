#include <iostream>
#include "Lecturer.h"

using namespace std;

Lecturer::Lecturer(){
    this->_lecturerID = "L0000001";
}

Lecturer::~Lecturer(){
    
}

string Lecturer::getLecturerID(){
    return this->_lecturerID;
}

void Lecturer::setLecturerID(string lecturerID){
    this->_lecturerID = lecturerID;
}
