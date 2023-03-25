#pragma once
#include "SchoolManeger.h"

using namespace std;

class App{
private:
    static App* _instance;
    bool _isLoggedIn = false;
    App();
public:
    ~App();
    static App* getInstance();
    void setLoggedIn(bool isLoggedIn);
    bool getLoggedIn();
    static void start();
    static void login();
    static void loginAsStudent();
    static void loginAsLecturer();
    static void loginAsStaff();
    static void logout();
    static void mainMenu();
    static void studentMenu(Student*);
    static void lecturerMenu();
    static void staffMenu();

};
