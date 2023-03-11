#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Course.h"
#include "Score.h"
#include "Student.h"
#include "Lecturer.h"
#include "Staff.h"
#include "Helper.h"

using namespace std;
class SchoolManager
{
private:
    // vector<Score>* _scoreList;
    map<string, vector<pair<Student, vector<Score>>>> _scoreboardOfCourse;
    map<string, vector<pair<Course, vector<Score>>>> _scoreboardOfStudent;
    
    map<string, Student> _dataStudentMap;
    map<string, Course> _dataCourseMap;
    map<string, Lecturer> _dataLecturerMap;
    map<string, Staff> _dataStaffMap;

public:
    SchoolManager();
    ~SchoolManager();
    // Getter & setter
    map<string, vector<pair<Course, vector<Score>>>> getScoreboardOfStudent();
    void setScoreboardOfStudent(map<string, vector<pair<Course, vector<Score>>>>);

    map<string, vector<pair<Student, vector<Score>>>> getScoreboardOfCourse();
    void setScoreboardOfCourse(map<string, vector<pair<Student, vector<Score>>>>);

    map<string, Course> getDataCourse();
    void setDataCourse(map<string, Course>);

    map<string, Student> getDataStudent();
    void setDataStudent(map<string, Student>);

    map<string, Lecturer> getDataLecturer();
    void setDataLecturer(map<string, Lecturer>);

    map<string, Staff> getDataStaff();
    void setDataStaff(map<string, Staff>);

    // Method & Behavior

    // Student
    // void viewCheckInResult(Student*);
    void studentViewYourScoreboard(Person *); // Done
    void studentViewYourListCourse(Person *); // Done
    void studentCourseRegistration(Person *);

    // Lecturer
    void lecturerViewScoreboardOfCourse(Person *, Course *); // Done
    // void lecturerUpdateScoreOfStudent(Person *, Course *, Person *, Score *);

    // Staff
    void staffImportStudentByCSV(Person*, const string&); //Done
    void staffAddStudent(Person *, Person *); // Done
    // void staffEditInformationStudent(Person *, Student *);
    void staffRemoveStudent(Person *, Person *);                       // Done
    void staffTransferStudent(Person *, Person *, Course *, Course *); // Done

    void staffImportScoreByCSV(Person *, const string&);
    void staffImportCourseByCSV();

    void staffCreateCourse();
    void staffAddCourse(Person *, Course *); // Done
    void staffEditInformationCourse(Person *, Course *);
    void staffRemoveCourse(Person *, Course *); // Done

    void staffViewListCourses(Person *);   // Done
    void staffViewListStudents(Person *);  // Done
    void staffViewListLecturers(Person *); // Done
    void staffViewListStaffs(Person *);    // Done

    void staffViewStudentListOfCourse(Person *, Course *); // Done
    void exportAttendanceListOfCourse(Course *);           // CSV file
};
