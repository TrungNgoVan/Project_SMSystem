#pragma once
#include <string>

using namespace std;

class Score{
private:
    int _year;
    int _semester;
    string _courseID;
    float _midtermScore;
    float _labScore;
    float _finalScore;
public:
    Score();
    ~Score();

    int getYear();
    void setYear(int);
    string gerCourseID();
    void displayScore();
};
