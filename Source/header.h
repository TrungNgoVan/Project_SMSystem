#pragma once
#include <string>
#include <vector>
using namespace std;

class Tokenizer
{
public:
    static vector<string> split(string, string);
};

class Helper
{
};

class User
{
private:
    string _username;
    string _name;
    string email;
    string _phoneNumber;
    int _type;
    string _password;
    string _rank;

public:
};

class Student : public User
{
private:
    string _id;
    vector<Course *> listCourse;

public:
    void checkIn(Course);
    void viewCourse();
    void viewCourseScore(Course);
    void viewSchedule();
};

class Lecturer : public User
{
private:
public:
    void importScoreboard(Course &);
    void editGrade(Student &);
    void viewScoreBoard(Course);
};

class AcademicStaff : public User
{
private:
public:
    void importStudent(vector<Student> &, string);
    void addNewStudent(vector<Student> &, Student);
    void editStudent(Student &);
    void removeStudent(vector<Student> &, Student);

    void viewListClasses(vector<Course>);
    void viewListStudents(Course);
    void importCourse(vector<Course> &, string);
    void addNewCourse(vector<Course> &, Course);
    void editCourse(Course &);
    void removeCourse(vector<Course> &, Course);
    void viewListCourses(vector<Course>);

    void importSchedule(vector<Schedule>&, string);
    //void addNewSchedule(vector<Schedule>&, Schedule);
    void editCourseSchedule(vector<Course>&, Course&);


    vector<int> searchAttendanceOfCourse(Course); // return list of Students and attendances of those student
    void exportScoreboard(Course, string);
};

class Course
{
private:
    string _code;
    string _year;
    int _semester;
    string _name;
    Lecturer *lecturer;
    Schedule schedule;
    int _dayInWeek;
    vector<int> _attendance;
    vector<Student *> listStudent;
    Score score;
public:

};

class Score
{
private:
    // Attribute
    string _code;
    string _year;
    int _semester;
    int _midtermScore;
    int _labScore;
    int _finalScore;

public:
    // Constructor & Destructor
    Score();
    Score(string, string, int, int, int, int);
    ~Score();
    // Getter & Setter
    void setCode(string);
    string getCode();

    void setYear(string);
    string getYear();

    void setSemester(int);
    int getSemester();

    void setMidtermScore(int);
    int getMidtermScore();

    void setLabScore(int);
    int getLabScore();

    void setFinalScore(int);
    int getFinalScore();
    // Method
    vector<string> Parse(string);
};

class Schedule
{
private:
    // Attribute
    int _second;
    int _minute;
    int _hour;
    int dayInWeek;

public:
    // Constructor & Destructor
    Schedule();
    Schedule(int, int, int);
    ~Schedule();
    // Getter & Setter

    void setSecond(int);
    int getSecond();

    void setMinute(int);
    int getMinute();

    void setHour(int);
    int getHour();
    // Method

    void toInfomation();
};

class Date{

};