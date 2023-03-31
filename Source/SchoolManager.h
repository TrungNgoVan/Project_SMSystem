#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "Course.h"
#include "Score.h"
#include "ScoreManager.h"
#include "Student.h"
#include "Lecturer.h"
#include "Staff.h"
#include "Helper.h"

using namespace std;
class SchoolManager
{
private:
    static SchoolManager *_instance;
    map<string, Student> _dataStudentMap;
    map<string, Course> _dataCourseMap;
    map<string, Lecturer> _dataLecturerMap;
    map<string, Staff> _dataStaffMap;

    ScoreManager *_dataScore;

    SchoolManager();

public:
    // Constructor & Destructor
    ~SchoolManager();
    // Singleton
    static SchoolManager *getInstance();
    // Getter & setter
    map<string, Course> getDataCourse();
    void setDataCourse(map<string, Course>);
    map<string, Student> getDataStudent();
    void setDataStudent(map<string, Student>);
    map<string, Lecturer> getDataLecturer();
    void setDataLecturer(map<string, Lecturer>);
    map<string, Staff> getDataStaff();
    void setDataStaff(map<string, Staff>);
    ScoreManager *getDataScore();
    void setDataScore(ScoreManager *);
    // METHOD
    // General
    void loadData();
    // Student
    void studentViewYourScoreboard(Person *);         // Done
    void studentViewYourListCourse(Person *);         // Done
    void studentCourseRegistration(Person *, string); // Done
    // Lecturer
    void lecturerViewScoreboardOfCourse(Person *, Course *); // Done
    void lecturerUpdateScoreOfStudent(Person *, Score *);    // Done
    // Staff
    void staffImportStudentByCSV(Person *, const string &); // Done
    void staffAddStudent(Person *, Person *);               // Done
    void staffEditInformationStudent(Person *, Student *);
    void staffRemoveStudent(Person *, Person *);                       // Done
    void staffTransferStudent(Person *, Person *, Course *, Course *); // Done
    void staffImportScoreByCSV(Person *, const string &);              // Done
    void staffImportLecturerByCSV(Person *, const string &);           // Done
    void staffImportStaffByCSV(Person *, const string &);              // Done
    void staffCreateCourse();
    void staffAddCourse(Person *, Course *); // Done
    void staffEditInformationCourse(Person *, Course *);
    void staffRemoveCourse(Person *, Course *);            // Done
    void staffViewListCourses(Person *);                   // Done
    void staffViewListStudents(Person *);                  // Done
    void staffViewListLecturers(Person *);                 // Done
    void staffViewListStaffs(Person *);                    // Done
    void staffViewStudentListOfCourse(Person *, Course *); // Done
    void exportAttendanceListOfCourse(Course *);

    void saveData();
};
