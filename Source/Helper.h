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
    static vector<Student*> readStudentFileCVS(const string& fileName);
    static vector<Score*> readScoreFileCVS(const string& fileName);
    static vector<Lecturer*> readLecturerFileCVS(const string& fileName);
    static vector<Staff*> readStaffFileCVS(const string& fileName);
};
