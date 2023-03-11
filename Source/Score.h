#pragma once
#include <string>

using namespace std;

class Score
{
private:
    int _year;
    int _semester;
    string _studentID;
    string _courseID;
    float _midtermScore;
    float _labScore;
    float _finalScore;

public:
    Score();
    Score(int, int, string, string, float, float, float);
    ~Score();

    int getYear();
    void setYear(int);
    int getSemester();
    void setSemester(int);
    string getStudentID();
    void setStudentID(string);
    string getCourseID();
    void setCourseID(string);
    float getMidtermScore();
    void setMidtermScore(float);
    float getLabScore();
    void setLabScore(float);
    float getFinalScore();
    void setFinalScore(float);
    
    void displayScore();
};
