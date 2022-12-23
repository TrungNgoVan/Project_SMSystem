#pragma once 
#include <string>
#include <vector>
#include <map>

#include "Course.h"
#include "Score.h"
#include "Student.h"
#include "Lecturer.h"

using namespace std;

class SchoolManager{
private:
    map<string, Score> scoreBoardStudent;
    map<string, Score> scoreBroadCourse;
    vector<Course> dataCourse;
    vector<Score> dataScore;
    vector<Student> dataStudent;
    vector<Lecturer> dataLecturer;
public:
    // Student
    void viewCheckInResult(Student*);
    void viewScoreBoard(Student*);
    void viewCourseBoard(Student*);

    //Staff
    void importStudentByCSV(); // CSV file
    void addStudent(Student*);
    void editInformationStudent(Student*);
    void removeStudent(Student*);
    void transferStudent(Student*, Course*, Course*);

    void importScoreByCSV();

    void importCourseByCSV(); // CSV file
    Course* createCourse();
    void addCourse(Course*);
    void editInformationCourse(Course*);
    void removeCourse(Course*);

    void viewListCourses();
    void viewListStudents();

    void viewScoreBoardOfStudent(Student*);
    void viewScoreBoardOfCourse(Course*);
    void viewStudentListOfCourse(Course*);

    void exportAttendanceListOfCourse(Course*); // CSV file



};
