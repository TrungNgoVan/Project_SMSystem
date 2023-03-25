#include "App.h"
#include "Helper.h"
#include <conio.h>
#include <iostream>

using namespace std;

App *App::_instance = NULL;

App::App()
{
}

App::~App()
{
}

App *App::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new App();
    }
    return _instance;
}

void App::setLoggedIn(bool isLoggedIn)
{
    _isLoggedIn = isLoggedIn;
}

bool App::getLoggedIn()
{
    return _isLoggedIn;
}

void App::start()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    schoolManager->loadData();
    while (true)
    {
        App::mainMenu();
    }
}

void App::login()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    while (true)
    {
        cout << "-------------- \n";
        cout << "Login" << endl;
        cout << "1. Login as student" << endl;
        cout << "2. Login as lecturer" << endl;
        cout << "3. Login as staff" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        string choice;
        getline(cin, choice);
        if (choice == "1")
        {
            App::loginAsStudent();
        }
        else if (choice == "2")
        {
            // App::loginAsLecturer();
        }
        else if (choice == "3")
        {
            // App::loginAsStaff();
        }
        else if (choice == "4")
        {
            return;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}

void App::logout()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    App *app = App::getInstance();
    app->setLoggedIn(false);
    cout << "Logout successfully" << endl;
    App::mainMenu();
}

void App::loginAsStudent()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    App *app = App::getInstance();
    cout << "Login as student" << endl;
    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    // write code to hide password input
    while (true)
    {
        char ch = _getch();
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            if (password.length() > 0)
            {
                cout << "\b \b";
                password.erase(password.length() - 1);
            }
        }
        else
        {
            cout << "*";
            password.push_back(ch);
        }
    }
    cout << endl;
    // write code to check username and password
    bool isLogin = false;
    for (auto data : schoolManager->getDataStudent())
    {
        if (data.second.getUserName() == username && data.second.getPassword() == password)
        {
            Student *student = &data.second;
            isLogin = true;
            cout << "Login successfully\n\n";
            app->setLoggedIn(true);
            while (true && app->getLoggedIn() == true)
            {
                App::studentMenu(student);
            }
            break;
        }
    }
    if (isLogin == false)
    {
        cout << "\nLogin failed\n\n";
    }
}

void App::mainMenu()
{
    cout << "Menu" << endl;
    cout << "1.Login" << endl;
    cout << "2.About" << endl;
    cout << "3.Exit" << endl;
    cout << "Your choice: ";
    string choice;
    getline(cin, choice);
    switch (stoi(choice))
    {
    case 1:
        App::login();
        break;
    case 2:
        cout << "\nAbout\n\n";
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid choice\n"
             << endl;
        break;
    }
}

void App::studentMenu(Student *student)
{
    cout << "Menu" << endl;
    cout << "1.View profile" << endl;
    cout << "2.View course" << endl;
    cout << "3.View score" << endl;
    cout << "4.Logout" << endl;
    cout << "Your choice: ";
    string choice;
    getline(cin, choice);
    switch (stoi(choice))
    {
    case 1:
        cout << "\nView profile\n\n";
        student->viewProfile();
        break;
    case 2:
        cout << "\nView course\n\n";
        student->viewCourse();
        break;
    case 3:
        cout << "\nView score\n\n";
        student->viewScore();
        break;
    case 4:
        App::logout();
        break;
    default:
        cout << "Invalid choice\n"
             << endl;
        break;
    }
}
