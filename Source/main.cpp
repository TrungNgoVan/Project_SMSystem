#include "Header.h"

using namespace std;

int main()
{
    SchoolManager HCMUS;
    Score S1, S2, S3, S4;
    Student Trung("21110423"), Dat("21125231");
    Lecturer Thao("L1112213"), Vu("L1212321");
    Staff Hai("S1112321"), Long("S1223123");
    Course C1("MTH10405", "DSA", Thao.getID()), 
        C2("MTH00012", "GT2", Vu.getID()),
        C3("MTH00108", "GT3", Vu.getID());

    map<string, vector<pair<Course, vector<Score>>>> mp1;
    map<string, vector<pair<Student, vector<Score>>>> mp2;

    S1.setCourseID(C1.getCourseID());
    S2.setCourseID(C2.getCourseID());
    S3.setCourseID(C1.getCourseID());
    S4.setCourseID(C2.getCourseID());
    C1.setLecturerID(Thao.getID());
    C2.setLecturerID(Vu.getID());

    mp1[Trung.getID()] = {{C1, {S1}}, {C2, {S2}}};
    HCMUS.setScoreboardOfStudent(mp1);
    mp2[C1.getCourseID()] = {{Trung, {S1, S2}}, {Dat, {S3, S4}}};
    HCMUS.setScoreboardOfCourse(mp2);

    HCMUS.setDataCourse({{C1.getCourseID(), C1}, {C2.getCourseID(), C2}});
    HCMUS.setDataLecturer({{Thao.getID(), Thao}, {Vu.getID(), Vu}});
    HCMUS.setDataStudent({{Trung.getID(), Trung}, {Dat.getID(), Dat}});
    HCMUS.setDataStaff({{Hai.getID(), Hai}, {Long.getID(), Long}});

    // Run behavior
    HCMUS.staffViewListCourses(&Hai);
    HCMUS.staffViewListLecturers(&Hai);
    HCMUS.staffViewListStudents(&Hai);
    HCMUS.studentViewYourScoreboard(&Trung);
    HCMUS.studentViewYourScoreboard(&Thao);
    HCMUS.studentViewYourListCourse(&Trung);
    HCMUS.lecturerViewScoreboardOfCourse(&Thao, &C1);
    HCMUS.lecturerViewScoreboardOfCourse(&Trung, &C1);
    HCMUS.staffAddStudent(&Hai, &Trung);
    HCMUS.staffAddStudent(&Hai, &Dat);
    HCMUS.staffRemoveStudent(&Hai, &Dat);
    HCMUS.staffRemoveStudent(&Hai, &Dat);
    HCMUS.staffViewListCourses(&Hai);
    HCMUS.staffRemoveCourse(&Hai, &C1);
    HCMUS.staffAddCourse(&Hai, &C3);
    HCMUS.staffViewStudentListOfCourse(&Hai, &C1);
    return 0;
}
