#pragma once
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"
#include "Course.h"
#include "Score.h"
#include "Lecturer.h"
#include "Staff.h"

using namespace std;

class Helper
{
public:
    static void start();
    static bool isInteger(const string& s);
    static bool isFloat(const string& s);
    static vector<Student*> readStudentFileCSV(const string& fileName);
    static vector<Score*> readScoreFileCSV(const string& fileName);
    static vector<Lecturer*> readLecturerFileCSV(const string& fileName);
    static vector<Staff*> readStaffFileCSV(const string& fileName);
    static void writeScoreFileCSV(const string& fileName, vector<Score*> scoreList);
};
