#include <iostream>
#include "Lecturer.h"

using namespace std;

Lecturer::Lecturer()
{
    this->_lecturerID = "L0000001";
}

Lecturer::Lecturer(string lecturerID)
{
    this->_lecturerID = lecturerID;
}

Lecturer::~Lecturer()
{
}

int Lecturer::getType()
{
    return 2;
}

string Lecturer::getID()
{
    return this->_lecturerID;
}

string Lecturer::getLecturerID()
{
    return this->_lecturerID;
}

void Lecturer::setLecturerID(string lecturerID)
{
    this->_lecturerID = lecturerID;
}

bool Lecturer::operator==(Lecturer *other)
{
    bool result = true;
    if (this->_lecturerID != other->_lecturerID)
        result = false;
    return result;
}
