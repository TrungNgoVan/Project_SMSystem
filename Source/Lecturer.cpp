#include <iostream>
#include "Lecturer.h"

using namespace std;

Lecturer::Lecturer()
{
    this->_lecturerID = "L0000001";
}

Lecturer::~Lecturer()
{
}

int Lecturer::getType(){
    return 2;
}

string Lecturer::getLecturerID()
{
    return this->_lecturerID;
}

void Lecturer::setLecturerID(string lecturerID)
{
    this->_lecturerID = lecturerID;
}
