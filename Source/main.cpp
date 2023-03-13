#include "Header.h"

using namespace std;

int main()
{
    SchoolManager HCMUS;
    Score S1, S2, S3, S4;
    Lecturer Thao("L1112213"), Vu("L1212321");
    Staff Hai("S1112321"), Long("S1223123");
    Course C1("MTH10405", "DSA", Thao.getID()),
        C2("MTH00012", "GT2", Vu.getID()),
        C3("MTH00108", "GT3", Vu.getID());

    HCMUS.setDataCourse({{C1.getCourseID(), C1}, {C2.getCourseID(), C2}, {C3.getCourseID(), C3}});
    HCMUS.setDataLecturer({{Thao.getID(), Thao}, {Vu.getID(), Vu}});
    HCMUS.setDataStaff({{Hai.getID(), Hai}, {Long.getID(), Long}});

    // Run behavior
    HCMUS.staffViewListCourses(&Hai);
    HCMUS.staffViewListStudents(&Hai);
    HCMUS.staffImportStudentByCSV(&Hai, "../Data/StudentData.csv");
    HCMUS.staffViewListStudents(&Hai);
    HCMUS.studentViewYourScoreboard(&HCMUS.getDataStudent()["21110401"]);
    HCMUS.staffImportScoreByCSV(&Hai, "../Data/ScoreData.csv");
    HCMUS.studentViewYourScoreboard(&HCMUS.getDataStudent()["21110401"]);
    HCMUS.getDataScore().displayScoreBoard();

    cout << "Press any key to exit...";
    return 0;
}
