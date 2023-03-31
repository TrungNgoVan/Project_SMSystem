#include "ScoreManager.h"
#include "Helper.h"

ScoreManager::ScoreManager()
{
    this->_scoreList = map<pair<string, string>, Score *>();
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::importScoreBoard(const string &filePath)
{
    vector<Score *> csv = Helper::readScoreFileCSV(filePath);
    for (Score *score : csv)
    {
        if (isScoreExist(score->getStudentID(), score->getCourseID()))
        {
            updateScore(score);
        }
        else
        {
            addScore(score);
            // Add course to student
        }
    }
}

void ScoreManager::exportScoreBoard(const string &filePath)
{
    vector<Score *> csv;
    for (auto score : _scoreList)
    {
        csv.push_back(score.second);
    }
    Helper::writeScoreFileCSV(filePath, csv);
}

void ScoreManager::addScore(Score *score)
{
    _scoreList[pair<string, string>(score->getStudentID(), score->getCourseID())] = score;
}

bool ScoreManager::isScoreExist(string studentID, string courseID)
{
    return _scoreList.find(pair<string, string>(studentID, courseID)) != _scoreList.end();
}

void ScoreManager::removeScore(string studentID, string courseID)
{
    _scoreList.erase(pair<string, string>(studentID, courseID));
}

void ScoreManager::updateScore(Score *score)
{
    _scoreList[pair<string, string>(score->getStudentID(), score->getCourseID())] = score;
}

Score *ScoreManager::getScore(string studentID, string courseID)
{
    return _scoreList[pair<string, string>(studentID, courseID)];
}

vector<Score *> ScoreManager::getScoreByStudentID(string studentID)
{
    vector<Score *> scoreList;

    for (auto score : this->_scoreList)
    {
        if (score.first.first == studentID)
        {
            scoreList.push_back(score.second);
        }
    }
    return scoreList;
}

Score *ScoreManager::getScoreByCourseID(string courseID)
{
    for (auto score : this->_scoreList)
    {
        if (score.first.second == courseID)
        {
            return score.second;
        }
    }
    return new Score;
}

vector<string> ScoreManager::getCoursesIDByStudentID(string studentID)
{
    unordered_set<string> courseList;
    for (auto score : this->_scoreList)
    {
        if (score.first.first == studentID)
        {
            courseList.insert(score.second->getCourseID());
        }
    }
    return vector<string>(courseList.begin(), courseList.end());
}


void ScoreManager::displayScoreBoard()
{
    for (auto score : _scoreList)
    {
        score.second->displayScore();
    }
}
