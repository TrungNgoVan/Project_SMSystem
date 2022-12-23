#pragma once
#include <string>

using namespace std;

class Score{
private:
    int _year;
    int _semester;
    float _midtermScore;
    float _labScore;
    float _finalScore;
public:
    int getYear();
    void setYear(int);
};
