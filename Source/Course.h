#pragma once
#include <iostream>

using namespace std;

class Course
{
private:
    string _courseID;
    string _courseName;
    string _lecturerID;
    int _year;
    int _semester;
    tm *_start;
    tm *_end;
    tm *_from;
    tm *_to;
    string _dayOfWeek;

public: // Constructor & Destructor
    Course();
    ~Course();

public: // Getter & Setter
    void setCourseID(string);
    string getCourseID();
    string getCourseName();
    string getLecturerID();
    void setLecturerID(string);
    void setDayOfWeek(string);
};
