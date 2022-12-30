#pragma once
#include <string>
#include <vector>
#include <map>

#include "Course.h"
#include "Score.h"
#include "Student.h"
#include "Lecturer.h"

using namespace std;
class SchoolManager
{
private:
    // Student
    map<string, vector<Score>> _scoreboardOfStudent;
    map<string, vector<Course>> _listCourseOfStudent;
    
    // Staff
    map<string, vector<Score>> _scoreboardOfCourse;
    vector<Course> _dataCourse;
    vector<Score> _dataScore;
    vector<Student> _dataStudent;
    vector<Lecturer> _dataLecturer;

public:
    SchoolManager();
    ~SchoolManager();
    // Getter & setter
    map<string, vector<Score>> getScoreboardOfStudent();
    void setScoreboardOfStudent(map<string, vector<Score>>);

    map<string, vector<Course>> getListCourseOfStudent();
    void setListCourseOfStudent(map<string, vector<Course>>);

    map<string, vector<Score>> getScoreboardOfCourse();
    void setScoreboardOfCourse(map<string, vector<Score>>);

    vector<Course> getDataCourse();
    void setDataCourse(vector<Course>);

    vector<Score> getDataScore();
    void setDataScore(vector<Score>);

    vector<Student> getDataStudent();
    void setDataStudent(vector<Student>);

    vector<Lecturer> getDataLecturer();
    void setDataLecturer(vector<Lecturer>);

    // Method & Behavior

    // Student
    // void viewCheckInResult(Student*);
    void studentViewYourScoreboard(Student *);
    void studentViewYourListCourse(Student *);

    //Lecturer
    void lecturerViewScoreboardOfCourse(Lecturer *, Course *);
    
    // Staff
    void importStudentByCSV(); // CSV file
    void addStudent(Person *, Student *);
    void editInformationStudent(Student *);
    void removeStudent(Student *);
    void transferStudent(Student *, Course *, Course *);

    void importScoreByCSV();
    void importCourseByCSV(); // CSV file

    Course *createCourse();
    void addCourse(Course *);
    void editInformationCourse(Course *);
    void removeCourse(Course *);

    void viewListCourses();
    void viewListStudents();
    void viewStudentListOfCourse(Course *);

    void exportAttendanceListOfCourse(Course *); // CSV file
};
