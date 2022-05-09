#pragma once
#include<string>
using namespace std;
class User
{
};

class Student : public User
{
};

class Lecturer : public User
{
};

class AcademicStaff : public User
{
};

class Course
{
private: 
    string codeCourse;
    string yearCourse;
    
};

class Attendance
{
};

class Score
{
};