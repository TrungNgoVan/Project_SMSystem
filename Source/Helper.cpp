#include "Helper.h"
#include "Student.h"

void Helper::start()
{
    /*
    struct tm {
        int tm_sec;   // seconds of minutes from 0 to 61
        int tm_min;   // minutes of hour from 0 to 59
        int tm_hour;  // hours of day from 0 to 24
        int tm_mday;  // day of month from 1 to 31
        int tm_mon;   // month of year from 0 to 11
        int tm_year;  // year since 1900
        int tm_wday;  // days since sunday
        int tm_yday;  // days since January 1st
        int tm_isdst; // hours of daylight savings time
    }
    */
    time_t now = time(0);
    tm *Time = localtime(&now);
}

bool Helper::isInteger(const string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

bool Helper::isFloat(const string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;
    char *p;
    strtof(s.c_str(), &p);
    return (*p == 0);
}

vector<Student *> Helper::readStudentFileCSV(const string &fileName)
{

    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return vector<Student *>();
    }
    vector<Student *> students;
    string line;
    string studentID, userName, password, fullName, email, phoneNumber;
    size_t pos;
    string delimiter = ",";
    getline(file, line); // Skip the first line
    while (getline(file, line))
    {
        studentID = userName = password = fullName = email = phoneNumber = "";
        pos = 0;
        delimiter = ",";

        pos = line.find(delimiter);
        studentID = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        userName = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        password = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        fullName = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        email = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        phoneNumber = line;
        Student *s = new Student(studentID, userName, password, fullName, email, phoneNumber);
        students.push_back(s);
    }
    return students;
}

vector<Score *> Helper::readScoreFileCSV(const string &fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return vector<Score *>();
    }
    vector<Score *> scores;
    string line;
    string studentID, courseID;
    int semester, year;
    float midScore, labScore, finalScore;
    size_t pos;
    string delimiter = ",";
    getline(file, line); // Skip the first line
    while (getline(file, line))
    {
        studentID = courseID = "";
        semester = year = 0;
        midScore = labScore = finalScore = 0;
        pos = 0;
        delimiter = ",";

        pos = line.find(delimiter);
        if (isInteger(line.substr(0, pos)))
            year = stoi(line.substr(0, pos));
        else
        {
            cout << "Error: Year must be an integer" << endl;
            return vector<Score *>(); // Exit the program
        }
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        if (isInteger(line.substr(0, pos)))
            semester = stoi(line.substr(0, pos));
        else
        {
            cout << "Error: Semester must be an integer" << endl;
            return vector<Score *>(); // Exit the program
        }
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        studentID = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        courseID = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        if (isFloat(line.substr(0, pos)))
            midScore = stof(line.substr(0, pos));
        else
        {
            cout << "Error: Midterm score must be a float" << endl;
            return vector<Score *>(); // Exit the program
        }
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        if (isFloat(line.substr(0, pos)))
            labScore = stof(line.substr(0, pos));
        else
        {
            cout << "Error: Lab score must be a float" << endl;
            return vector<Score *>(); // Exit the program
        }
        line.erase(0, pos + delimiter.length());

        if (isFloat(line))
            finalScore = stof(line);
        else
        {
            cout << "Error: Final score must be a float" << endl;
            return vector<Score *>(); // Exit the program
        }

        Score *s = new Score(year, semester, studentID, courseID, midScore, labScore, finalScore);
        scores.push_back(s);
    }
    return scores;
}

// Write to file
void Helper::writeScoreFileCSV(const string& fileName, vector<Score*> scores)
{
    ofstream file(fileName);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    file << "Year,Semester,Student ID,Course ID,Midterm Score,Lab Score,Final Score" << endl;
    for (Score* s : scores)
    {
        file << s->getYear() << "," << s->getSemester() << "," << s->getStudentID() << "," << s->getCourseID() << "," << s->getMidtermScore() << "," << s->getLabScore() << "," << s->getFinalScore() << endl;
    }
}


