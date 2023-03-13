#include "Score.h"
#include <map>
#include <string>
#include <vector>

class ScoreManager
{
private:
    map<pair<string, string>, Score> _scoreList;
public:
    ScoreManager();
    ~ScoreManager();

    void importScoreBoard(const string&);
    void exportScoreBoard(const string&);
    void addScore(Score*);
    bool isScoreExist(string, string);
    void removeScore(string, string);
    void updateScore(Score*);
    Score getScore(string, string);
    Score getScoreByStudentID(string);
    Score getScoreByCourseID(string);
    void displayScoreBoard();
};
