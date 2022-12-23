#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Lecturer : Person
{
private:
    string _lecturerID;

public:
    string getLecturerID();
    void setLecturerID(string);
};
