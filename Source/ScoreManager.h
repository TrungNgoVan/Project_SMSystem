#pragma once
#include "Score.h"
#include "Presence.h"
#include "Student.h"
#include "Course.h"
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

class ScoreManager
{
private:
    map<pair<string, string>, Score*> _scoreList;
    unordered_map<string, Presence*> _presenceList;
public:
    ScoreManager();
    ~ScoreManager();
    void importScoreBoard(const string&);
    void exportScoreBoard(const string&);
    void addScore(Score*);
    bool isScoreExist(string, string);
    void removeScore(string, string);
    void updateScore(Score*);
    Score* getScore(string, string);
    vector<Score*> getScoreByStudentID(string);
    Score* getScoreByCourseID(string);
    vector<string> getCoursesIDByStudentID(string);
    void setPresence(Student*, Course*, bool);
    bool isPresenceExist(Student*, Course*);

    void displayScoreBoard();
};
