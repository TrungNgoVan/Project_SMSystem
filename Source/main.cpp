#include "Header.h"

using namespace std;

int main()
{
    SchoolManager HCMUS;
    Score S1;
    Course C1;
    Student Trung;
    Student Dat;
    Lecturer Thao, Hai;
    Hai.setLecturerID("L0000002");

    map<string, vector<Score>> mp1;
    map<string, vector<Course>> mp2;
    map<string, vector<Score>> mp3;
    
    mp1[Trung.getStudentID()] = {S1};
    HCMUS.setScoreboardOfStudent(mp1);

    mp2[Trung.getStudentID()] = {C1};
    HCMUS.setListCourseOfStudent(mp2);
    
    S1.setCourseID(C1.getCourseID());
    C1.setLecturerID(Thao.getLecturerID());

    mp3[C1.getCourseID()] = {S1};
    HCMUS.setScoreboardOfCourse(mp3);

//Run behavior
    HCMUS.studentViewYourScoreboard(&Trung);
    HCMUS.studentViewYourListCourse(&Trung);
    HCMUS.lecturerViewScoreboardOfCourse(&Thao, &C1);
    HCMUS.lecturerViewScoreboardOfCourse(&Hai, &C1);
    HCMUS.addStudent(&Thao, &Dat); // Done because Thao is Lecturer
    HCMUS.addStudent(&Dat, &Trung); // Fail because Dat is Student

    return 0;
}
