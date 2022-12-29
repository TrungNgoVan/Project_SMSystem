#include "Header.h"

using namespace std;

int main()
{
    SchoolManager HCMUS;
    Score S1;
    Course C1;
    Student Trung;
    Lecturer Thao;

    map<string, vector<Score>> mp1, mp2;
    mp1[Trung.getStudentID()] = {S1};
    HCMUS.setScoreBoardStudent(mp1);
    mp2[C1.getCourseID()] = {S1};
    HCMUS.setScoreBoardCourse(mp2);
    HCMUS.studentViewScoreBoard(&Trung);
    return 0;
}
