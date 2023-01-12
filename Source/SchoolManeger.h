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

using namespace std;
class SchoolManager
{
private:
    // Student
    // Staff
    map<string, vector<pair<Student, vector<Score>>>> _scoreboardOfCourse;
    map<string, vector<pair<Course, vector<Score>>>> _scoreboardOfStudent;
    
    vector<Course> _dataCourse;
    vector<Score> _dataScore;
    vector<Student> _dataStudent;
    vector<Lecturer> _dataLecturer;
    vector<Staff> _dataStaff;

public:
    SchoolManager();
    ~SchoolManager();
    // Getter & setter
    map<string, vector<pair<Course, vector<Score>>>> getScoreboardOfStudent();
    void setScoreboardOfStudent(map<string, vector<pair<Course, vector<Score>>>>);

    map<string, vector<pair<Student, vector<Score>>>> getScoreboardOfCourse();
    void setScoreboardOfCourse(map<string, vector<pair<Student, vector<Score>>>>);

    vector<Course> getDataCourse();
    void setDataCourse(vector<Course>);

    vector<Score> getDataScore();
    void setDataScore(vector<Score>);

    vector<Student> getDataStudent();
    void setDataStudent(vector<Student>);

    vector<Lecturer> getDataLecturer();
    void setDataLecturer(vector<Lecturer>);

    vector<Staff> getDataStaff();
    void setDataStaff(vector<Staff>);

    // Method & Behavior

    // Student
    // void viewCheckInResult(Student*);
    void studentViewYourScoreboard(Person *); // Done
    void studentViewYourListCourse(Person *); // Done
    void studentCourseRegistration(Person *);

    // Lecturer
    void lecturerViewScoreboardOfCourse(Person *, Course *); // Done
    void lecturerUpdateScoreOfStudent(Person *, Course *, Person *, Score *);

    // Staff
    void staffImportStudentByCSV();        // CSV file
    void staffAddStudent(Person *, Person *); // Done
    void staffEditInformationStudent(Person *, Student *);
    void staffRemoveStudent(Person *, Person *); //Done
    void staffTransferStudent(Person *, Person *, Course *, Course *);// Done

    void staffImportScoreByCSV(Person *);
    void staffImportCourseByCSV();

    void staffCreateCourse(); 
    void staffAddCourse(Person *, Course *);// Done
    void staffEditInformationCourse(Person *, Course *);
    void staffRemoveCourse(Person *, Course *);// Done

    void staffViewListCourses(Person *);
    void staffViewListStudents(Person *);
    void staffViewStudentListOfCourse(Person *,Course *);

    void exportAttendanceListOfCourse(Course *); // CSV file
};
