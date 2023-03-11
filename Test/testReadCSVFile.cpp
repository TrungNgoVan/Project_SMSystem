#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Score{
private: 
    int _year;
    int _semester;
    string _studentID;
    string _courseID;
    float _midtermScore;
    float _labScore;
    float _finalScore;
public:
    Score()
    {
        this->_year = 2000;
        this->_semester = 1;
        this->_studentID = "00000000";
        this->_courseID = "MTH00000";
        this->_midtermScore = 0;
        this->_labScore = 0;
        this->_finalScore = 0;
    }

    ~Score()
    {
    }

    Score(int year, int semester, string studentID, string courseID, float midtermScore, float labScore, float finalScore)
    {
        this->_year = year;
        this->_semester = semester;
        this->_studentID = studentID;
        this->_courseID = courseID;
        this->_midtermScore = midtermScore;
        this->_labScore = labScore;
        this->_finalScore = finalScore;
    }

    int getYear()
    {
        return this->_year;
    }

    void setYear(int year)
    {
        this->_year = year;
    }

    string getCourseID()
    {
        return this->_courseID;
    }

    void setCourseID(string courseID)
    {
        this->_courseID = courseID;
    }

    void displayScore()
    {
        cout << "Year: " << this->_year << " Semester: " << this->_semester << " Student ID: " << this->_studentID 
        << "Course ID: " << this->_courseID << " Midterm score: " << this->_midtermScore << " Lab score: " << this->_labScore 
        << " Final score: " << this->_finalScore << endl;
    }

};

bool isInteger(const string& s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

bool isFloat(const string& s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    strtof(s.c_str(), &p);

    return (*p == 0);
}

void readScoreFileCVS(const string& fileName)
{
    cout << "Reading file " << fileName << endl;
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    cout << "Start reading file" << endl;

    vector<Score*> scores;
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
        else{
            cout << "Error: Year must be an integer" << endl;
            return; // Exit the program
        }
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        if (isInteger(line.substr(0, pos)))
            semester = stoi(line.substr(0, pos));
        else{
            cout << "Error: Semester must be an integer" << endl;
            return; // Exit the program
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
        else{
            cout << "Error: Midterm score must be a float" << endl;
            return; // Exit the program

        }
        line.erase(0, pos + delimiter.length());

        pos = line.find(delimiter);
        if (isFloat(line.substr(0, pos)))
            labScore = stof(line.substr(0, pos));
        else{
            cout << "Error: Lab score must be a float" << endl;
            return; // Exit the program

        }
        line.erase(0, pos + delimiter.length());

        if (isFloat(line))
            finalScore = stof(line);
        else{
            cout << "Error: Final score must be a float" << endl;
            return; // Exit the program

        }

        Score* s = new Score(year, semester, studentID, courseID, midScore, labScore, finalScore);
        scores.push_back(s);   
    }
    // Print all scores
    for (Score* s : scores)
        s->displayScore();
    return; // Exit the program

}

int main()
{
    readScoreFileCVS("../Data/ScoreData.csv");
    return 0;
}
