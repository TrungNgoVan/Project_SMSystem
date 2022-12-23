#pragma once 
#include <iostream>

using namespace std;

class Course
{
private:
    string _courseID;
    string _courseName;
    int _year;
    int _semester;
    tm *_start;
    tm *_end;
    tm *_from;
    tm *_to;
    string _dayOfWeek;
public: // Constructor & Destructor
    Course();
    Course(/*parameter*/);
    ~Course();
public: // Getter & Setter
    void setCourseID(string);
    string getCourseID();

    void setDayOfWeek(string);
};
