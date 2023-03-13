#include "ScoreManager.h"
#include "Helper.h"

ScoreManager::ScoreManager()
{
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::importScoreBoard(const string& filePath)
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
        }
        // score->displayScore();
    }
}

void ScoreManager::exportScoreBoard(const string& filePath)
{
    vector<Score *> csv;
    for (auto score : _scoreList)
    {
        csv.push_back(&score.second);
    }
    Helper::writeScoreFileCSV(filePath, csv);
}

void ScoreManager::addScore(Score* score)
{
    _scoreList[pair<string, string>(score->getStudentID(), score->getCourseID())] = *score;
}

bool ScoreManager::isScoreExist(string studentID, string courseID)
{
    return _scoreList.find(pair<string, string>(studentID, courseID)) != _scoreList.end();
}

void ScoreManager::removeScore(string studentID, string courseID)
{
    _scoreList.erase(pair<string, string>(studentID, courseID));
}

void ScoreManager::updateScore(Score* score)
{
    _scoreList[pair<string, string>(score->getStudentID(), score->getCourseID())] = *score;
}

Score ScoreManager::getScore(string studentID, string courseID)
{
    return _scoreList[pair<string, string>(studentID, courseID)];
}

Score ScoreManager::getScoreByStudentID(string studentID)
{
    for (auto score : _scoreList)
    {
        if (score.first.first == studentID)
        {
            return score.second;
        }
    }
    return Score();
}

Score ScoreManager::getScoreByCourseID(string courseID)
{
    for (auto score : _scoreList)
    {
        if (score.first.second == courseID)
        {
            return score.second;
        }
    }
    return Score();
}

void ScoreManager::displayScoreBoard()
{
    for (auto score : _scoreList)
    {
        score.second.displayScore();
    }
}




