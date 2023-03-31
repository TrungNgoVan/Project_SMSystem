#pragma once
#include "SchoolManager.h"

using namespace std;

class App
{
private:
    static App *_instance;
    bool _isLoggedIn = false;
    App();

public:
    ~App();
    static App *getInstance();
    void setLoggedIn(bool isLoggedIn);
    bool getLoggedIn();
    static void start();
    static void login();
    static void loginAsStudent();
    static void loginAsLecturer();
    static void loginAsStaff();
    static void logout();
    static void mainMenu();
    static void studentMenu(Person *);
    static void lecturerMenu(Person *);
    static void staffMenu(Person *);
};
