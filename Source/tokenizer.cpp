#include "header.h"

using namespace std;

vector<string> Tokenizer::split(string haystack, string needel = " "){
    vector<string> result;
        int startPos = 0;
        size_t foundPos = 0;
        while (true)
        {
            foundPos = haystack.find(needel, startPos);
            if (foundPos != string::npos)
            {
                string token = haystack.substr(startPos, foundPos - startPos);
                startPos = foundPos + needel.size();
                result.push_back(token);
            }
            else
            {
                string token = haystack.substr(startPos, haystack.size() - startPos);
                result.push_back(token);
                break;
            }
        }
    return result;
}