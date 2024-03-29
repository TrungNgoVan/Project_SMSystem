#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include "SchoolManager.h"

using namespace std;

SchoolManager *SchoolManager::_instance = NULL;

SchoolManager::SchoolManager()
{
    this->_dataStudentMap = map<string, Student>();
    this->_dataCourseMap = map<string, Course>();
    this->_dataLecturerMap = map<string, Lecturer>();
    this->_dataStaffMap = map<string, Staff>();
    this->_dataScore = new ScoreManager();
}

SchoolManager *SchoolManager::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new SchoolManager();
    }
    return _instance;
}

SchoolManager::~SchoolManager()
{
    delete this->_dataScore;
}

void SchoolManager::loadData()
{
    Lecturer Thao("L1112213"), Vu("L1212321");
    Staff Hai("S1112321"), Long("S1223123");
    Course C1("MTH10405", "DSA", Thao.getID()),
        C2("MTH00012", "GT2", Vu.getID()),
        C3("MTH00108", "GT3", Vu.getID());

    this->setDataCourse({{C1.getCourseID(), C1}, {C2.getCourseID(), C2}, {C3.getCourseID(), C3}});
    this->setDataLecturer({{Thao.getID(), Thao}, {Vu.getID(), Vu}});
    this->setDataStaff({{Hai.getID(), Hai}, {Long.getID(), Long}});
    this->staffImportStudentByCSV(&Hai, "../Data/StudentData.csv");
    this->staffImportLecturerByCSV(&Hai, "../Data/LecturerData.csv");
    this->staffImportStaffByCSV(&Hai, "../Data/StaffData.csv");
}

map<string, Course> SchoolManager::getDataCourse()
{
    return this->_dataCourseMap;
}

void SchoolManager::setDataCourse(map<string, Course> newData)
{
    this->_dataCourseMap = newData;
}

map<string, Student> SchoolManager::getDataStudent()
{
    return this->_dataStudentMap;
}

void SchoolManager::setDataStudent(map<string, Student> newData)
{
    this->_dataStudentMap = newData;
}

map<string, Lecturer> SchoolManager::getDataLecturer()
{
    return this->_dataLecturerMap;
}

void SchoolManager::setDataLecturer(map<string, Lecturer> newData)
{
    this->_dataLecturerMap = newData;
}

map<string, Staff> SchoolManager::getDataStaff()
{
    return this->_dataStaffMap;
}

void SchoolManager::setDataStaff(map<string, Staff> newData)
{
    this->_dataStaffMap = newData;
}

ScoreManager *SchoolManager::getDataScore()
{
    return this->_dataScore;
}

void SchoolManager::setDataScore(ScoreManager *newData)
{
    this->_dataScore = newData;
}

//-------------------
//----- FEATURE -----
//-------------------

void SchoolManager::studentViewYourScoreboard(Person *student)
{
    cout << "Function: studentViewYourScoreboard\n";
    if (student->getType() == Type::studentCode)
    {
        if (this->_dataStudentMap.find(student->getID()) == this->_dataStudentMap.end())
        {
            cout << "Student not found!\n";
            cout << "--------------------\n";
            return;
        }
        cout << "Student " << student->getID() << " view their scoreboard!\n";
        vector<Score *> data = this->_dataScore->getScoreByStudentID(student->getID());
        if (data.size() == 0)
        {
            cout << "Student " << student->getID() << " don't have any course!\n";
            cout << "--------------------\n";
            return;
        }
        else
        {
            for (auto score : data)
            {
                if (score->getYear() != -1)
                    score->displayScore();
            }
        }
    }
    else
    {
        cout << "You can't access!\n";
    }
    cout << "--------------------\n";
}

void SchoolManager::studentViewYourListCourse(Person *student)
{
    cout << "Function: studentViewYourListCourse\n";
    if (student->getType() == Type::studentCode)
    {
        vector<string> data = this->_dataScore->getCoursesIDByStudentID(student->getID());
        if (data.size() == 0)
        {
            cout << "Student " << student->getID() << " don't have any course!\n";
            cout << "--------------------\n";
            return;
        }
        else
        {
            cout << "Student " << student->getID() << " view their list course!\n";
            for (auto courseID : data)
            {
                cout << courseID << endl;
            }
        }
        // free memory of data
        data.clear();
    }
    else
    {
        cout << "You can't access!\n";
    }
    cout << "--------------------\n";
}

void SchoolManager::studentCourseRegistration(Person *student, string courseID)
{
    cout << "Function: studentCourseRegistration\n";
    if (student->getType() == Type::studentCode)
    {
        if (this->_dataStudentMap.find(student->getID()) == this->_dataStudentMap.end())
        {
            cout << "Student not found!\n";
            cout << "--------------------\n";
            return;
        }
        if (this->_dataCourseMap.find(courseID) == this->_dataCourseMap.end())
        {
            cout << "Course not found!\n";
            cout << "--------------------\n";
            return;
        }
        cout << "Student " << student->getID() << " register course " << courseID << " !\n";
        this->_dataScore->addScore(new Score(student->getID(), courseID));

        cout << "Done!\n";
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::lecturerViewScoreboardOfCourse(Person *lecturer, Course *course)
{
    cout << "Function: lecturerViewScoreboardOfCourse\n";
    if (lecturer->getType() == Type::lecturerCode)
    {
        cout << "Lecturer " << lecturer->getID() << " view scoreboard of course " << course->getCourseID() << " ! \n";
        if (lecturer->getID() != course->getLecturerID())
        {
            cout << "You can't access!\n";
            cout << "--------------------\n";
        }
        else
        {
            if (this->_dataCourseMap.find(course->getCourseID()) == this->_dataCourseMap.end())
            {
                cout << "Course not found!\n";
                cout << "--------------------\n";
                return;
            }
            this->_dataScore->getScoreByCourseID(course->getCourseID());
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::lecturerUpdateScoreOfStudent(Person *lecturer, Score *score)
{

    cout << "Function: lecturerUpdateScoreOfStudent\n";
    if (lecturer->getType() == Type::lecturerCode)
    {
        if (this->_dataScore->getScore(score->getStudentID(), score->getCourseID()) == NULL)
        {
            this->_dataScore->addScore(score);
        }
        else
        {
            this->_dataScore->updateScore(score);
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffAddStudent(Person *staff, Person *newStudent)
{
    cout << "Function: staffAddStudent\n";
    if (staff->getType() == Type::staffCode)
    {
        if (newStudent->getType() == Type::studentCode)
        {
            cout << "Staff " << staff->getID() << " add student " << newStudent->getID() << " to data!\n";
            auto it = this->_dataStudentMap.find(newStudent->getID());
            if (it == this->_dataStudentMap.end())
            {
                // Add the student to the data
                this->_dataStudentMap.insert(pair<string, Student>(newStudent->getID(), *dynamic_cast<Student *>(newStudent)));
                cout << "Done!\n";
                cout << "--------------------\n";
            }
            else
            {
                cout << "This student exists!\n";
                cout << "--------------------\n";
            }
        }
        else
        {
            cout << "Type error!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffRemoveStudent(Person *staff, Person *student)
{
    if (staff->getType() == Type::staffCode)
    {
        if (student->getType() == Type::studentCode)
        {
            cout << "Staff " << staff->getID() << " remove student " << student->getID() << " from data!\n";
            auto it = this->_dataStudentMap.find(student->getID());
            if (it != this->_dataStudentMap.end())
            {
                // Remove the student from the data
                this->_dataStudentMap.erase(it);
                cout << "Done!\n";
                cout << "--------------------\n";
            }
            else
            {
                cout << "This student does not exist!\n";
                cout << "--------------------\n";
            }
        }
        else
        {
            cout << "Type error!\n";
            cout << "--------------------\n";
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffImportStudentByCSV(Person *staff, const string &fileName)
{
    cout << "Function: staffImportStudentByCSV\n";
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " import student by CSV file!\n";
        vector<Student *> csv = Helper::readStudentFileCSV("../Data/StudentData.csv");
        for (auto student : csv)
        {
            // Add student to data
            auto it = this->_dataStudentMap.find(student->getID());
            if (it == this->_dataStudentMap.end())
            {
                this->_dataStudentMap.insert(pair<string, Student>(student->getID(), *student));
            }
            else
            {
                cout << "This student exists!\n";
            }
        }

        // delete csv
        for (auto student : csv)
        {
            delete student;
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
    cout << "Done import student!\n";
    cout << "--------------------\n";
}

void SchoolManager::staffImportLecturerByCSV(Person *staff, const string &fileName)
{
    cout << "Function: staffImportLecturerByCSV\n";
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " import lecturer by CSV file!\n";
        vector<Lecturer *> csv = Helper::readLecturerFileCSV("../Data/LecturerData.csv");
        for (auto lecturer : csv)
        {
            // Add lecturer to data
            auto it = this->_dataLecturerMap.find(lecturer->getID());
            if (it == this->_dataLecturerMap.end())
            {
                this->_dataLecturerMap.insert(pair<string, Lecturer>(lecturer->getID(), *lecturer));
            }
            else
            {
                cout << "This lecturer exists!\n";
            }
        }

        // delete csv
        for (auto lecturer : csv)
        {
            delete lecturer;
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
    cout << "Done import lecturer!\n";
    cout << "--------------------\n";
}

void SchoolManager::staffImportStaffByCSV(Person *staff, const string &fileName)
{
    cout << "Function: staffImportStaffByCSV\n";
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " import staff by CSV file!\n";
        vector<Staff *> csv = Helper::readStaffFileCSV("../Data/StaffData.csv");
        for (auto staff : csv)
        {
            // Add staff to data
            auto it = this->_dataStaffMap.find(staff->getID());
            if (it == this->_dataStaffMap.end())
            {
                this->_dataStaffMap.insert(pair<string, Staff>(staff->getID(), *staff));
            }
            else
            {
                cout << "This staff exists!\n";
            }
        }

        // delete csv
        for (auto staff : csv)
        {
            delete staff;
        }
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
    cout << "Done import staff!\n";
    cout << "--------------------\n";
}

void SchoolManager::staffImportScoreByCSV(Person *staff, const string &fileName)
{
    cout << "Function: staffImportScoreByCSV\n";
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " import score by CSV file!\n";
        this->_dataScore->importScoreBoard(fileName);
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
    cout << "Done import score!\n";
    cout << "--------------------\n";
}

// void SchoolManager::staffTransferStudent(Person *staff, Person *student, Course *courseA, Course *courseB)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         if (student->getType() == Type::studentCode)
//         {
//             cout << "Staff " << staff->getID() << " transfer student " << student->getID() << " from course "
//                  << courseA->getCourseID() << " to course " << courseB->getCourseID() << " !\n";
//         }
//         else
//         {
//             cout << "Type error!\n";
//             cout << "--------------------\n";
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }

// void SchoolManager::staffAddCourse(Person *staff, Course *newCourse)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         cout << "Staff " << staff->getID() << " add course " << newCourse->getCourseID() << " to data!\n";
//         auto it = find(this->_dataCourseMap.begin(), this->_dataCourseMap.end(), newCourse->getCourseID());
//         if (it == this->_dataCourseMap.end())
//         {
//             // Add the course to the data
//             this->_dataCourseMap[newCourse->getCourseID()] = *newCourse;
//             cout << "Done!\n";
//             cout << "--------------------\n";
//         }
//         else
//         {
//             cout << "This course exists!\n";
//             cout << "--------------------\n";
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }

// void SchoolManager::staffRemoveCourse(Person *staff, Course *course)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         cout << "Staff " << staff->getID() << " remove course " << course->getCourseID() << " from data!\n";
//         auto it = find(this->_dataCourseMap.begin(), this->_dataCourseMap.end(), course->getCourseID());
//         if (it != this->_dataCourseMap.end())
//         {
//             // Remove the course from the data
//             this->_dataCourseMap.erase(it);
//             cout << "Done!\n";
//             cout << "--------------------\n";
//         }
//         else
//         {
//             cout << "This course does not exist!\n";
//             cout << "--------------------\n";
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }

void SchoolManager::staffViewListCourses(Person *staff)
{
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " view list courses!\n";
        if (this->_dataCourseMap.empty())
        {
            cout << "Empty!\n";
            cout << "--------------------\n";
            return;
        }
        else
        {
            for (auto it : this->_dataCourseMap)
            {
                cout << it.second.getCourseID() << " " << it.second.getCourseName() << endl;
            }
        }
        cout << "Done!\n";
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

void SchoolManager::staffViewListStudents(Person *staff)
{
    cout << "Function: staffViewListStudents\n";
    if (staff->getType() == Type::staffCode)
    {
        cout << "Staff " << staff->getID() << " view list students!\n";
        if (this->_dataStudentMap.empty())
        {
            cout << "Empty!\n";
            cout << "--------------------\n";
            return;
        }
        for (auto it : this->_dataStudentMap)
        {
            cout << it.second.getStudentID() << " " << it.second.getFullName() << endl;
        }
        cout << "Done!\n";
        cout << "--------------------\n";
    }
    else
    {
        cout << "You can't access!\n";
        cout << "--------------------\n";
    }
}

// void SchoolManager::staffViewListLecturers(Person *staff)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         if (this->_dataLecturerMap.empty())
//         {
//             cout << "Empty!\n";
//             cout << "--------------------\n";
//             return;
//         }
//         for (auto it : this->_dataLecturerMap)
//         {
//             cout << it.second.getLecturerID() << " " << it.second.getFullName() << endl;
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }

// void SchoolManager::staffViewListStaffs(Person *staff)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         cout << "Staff " << staff->getID() << " view list staffs!\n";
//         if (this->_dataStaffMap.empty())
//         {
//             cout << "Empty!\n";
//             cout << "--------------------\n";
//             return;
//         }
//         for (auto it : this->_dataStaffMap)
//         {
//             cout << it.second.getStaffID() << " " << it.second.getFullName() << "\n";
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }

// void SchoolManager::staffViewStudentListOfCourse(Person *staff, Course *course)
// {
//     if (staff->getType() == Type::staffCode)
//     {
//         cout << "Staff " << staff->getID() << " view list students of course " << course->getCourseID() << "!\n";
//         if (_scoreboardOfCourse[course->getCourseID()].empty())
//         {
//             cout << "Empty!\n";
//             cout << "--------------------\n";
//             return;
//         }
//         for (auto it : _scoreboardOfCourse[course->getCourseID()])
//         {
//             cout << it.first.getStudentID() << " " << it.first.getFullName() << "\n";
//         }
//     }
//     else
//     {
//         cout << "You can't access!\n";
//         cout << "--------------------\n";
//     }
// }
