// #include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Init{
public:
    static void start(){
        /*
        struct tm {
            int tm_sec;   // seconds of minutes from 0 to 61
            int tm_min;   // minutes of hour from 0 to 59
            int tm_hour;  // hours of day from 0 to 24
            int tm_mday;  // day of month from 1 to 31
            int tm_mon;   // month of year from 0 to 11
            int tm_year;  // year since 1900
            int tm_wday;  // days since sunday
            int tm_yday;  // days since January 1st
            int tm_isdst; // hours of daylight savings time
        }
        */
        time_t now = time(0);
        tm *Time  = localtime(&now);
        cout << Time->tm_hour;
    }
};

class Course
{
private:
    string _courseCode;
    string _courseName;
    int _year;
    int _semester;
    tm *_start;
    tm *_end;
    tm *_from;
    tm *_to;
    string _dayOfWeek;
public:
};

class Score
{
private:
    string _courseCode;
    int _year;
    int _semester;
    string _studentID;
    float _midScore;
    float _labScore;
    float _finalScore;
};

class Person
{
private:
    string _userName;
    string _fullName;
    string _email;
    string _mobilePhone;
    int _type;
    string _password;
    string _class;
};

class Student : Person
{
private:
    string _studentID;

public:
};

class Lecturer : Person{
private:
    string _shortName;
public:

};

class AcademicStaff : Person{
private:
    string _shortName;
public:
};

int main()
{

    return 0;
}
