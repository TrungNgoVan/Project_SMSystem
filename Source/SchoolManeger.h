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
    map<string, vector<Score>> _scoreBoardStudent;
    map<string, vector<Score>> _scoreBroadCourse;
    vector<Course> _dataCourse;
    vector<Score> _dataScore;
    vector<Student> _dataStudent;
    vector<Lecturer> _dataLecturer;
public:
    SchoolManager();
    ~SchoolManager();

    void setScoreBoardStudent(map<string, vector<Score>>);
    void setScoreBoardCourse(map<string, vector<Score>>);

    // Student
    // void viewCheckInResult(Student*);
    void studentViewScoreBoard(Student*);
    void viewCourseBoard(Student*);

    //Staff
    void importStudentByCSV(); // CSV file
    void addStudent(Student*);
    void editInformationStudent(Student*);
    void removeStudent(Student*);
    void transferStudent(Student*, Course*, Course*);

    void importScoreByCSV();
    void importCourseByCSV();// CSV file
    
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
