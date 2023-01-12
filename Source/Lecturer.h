#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Lecturer : public Person
{
private:
    string _lecturerID;

public:
    Lecturer();
    Lecturer(string);
    ~Lecturer();
    int getType();  
    string getID();
    void setLecturerID(string);
};
