#pragma once
#include <string>
#include "Person.h"
#include "Course.h"
#include "ScoreManager.h"
#include "Score.h"

using namespace std;

class Staff : public Person
{
private:
    string _staffID;

public:
    Staff();
    Staff(string);
    Staff(string, string, string, string, string, string);
    ~Staff();
    int getType();
    string getID();
    string getStaffID();
    void setStaffID(string);
    void viewProfile();
    void viewListStudent();
    void viewListCourse();
    void viewListLecturer();
    bool operator==(Staff *other);
};
