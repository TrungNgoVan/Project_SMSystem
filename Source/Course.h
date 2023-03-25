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
    Course(string, string, string);
    ~Course();

public: // Getter & Setter
    void setCourseID(string);
    string getCourseID();
    string getCourseName();
    string getLecturerID();
    int getYear();
    int getSemester();
    tm *getStart();
    tm *getEnd();
    tm *getFrom();
    tm *getTo();
    string getDayOfWeek();
    void setCourseName(string);
    void setLecturerID(string);
    void setDayOfWeek(string);
    void displayCourse();
    bool operator==(Course *other);
};
