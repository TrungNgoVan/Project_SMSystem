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
            App::loginAsLecturer();
        }
        else if (choice == "3")
        {
            App::loginAsStaff();
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
    cout << "\n\nLogout successfully\n";
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
            cout << "\n\nLogin successfully\n";
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

void App::loginAsLecturer()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    App *app = App::getInstance();
    cout << "Login as lecturer" << endl;
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
    for (auto data : schoolManager->getDataLecturer())
    {
        if (data.second.getUserName() == username && data.second.getPassword() == password)
        {
            Lecturer *lecturer = &data.second;
            isLogin = true;
            cout << "\n\nLogin successfully\n";
            app->setLoggedIn(true);
            while (true && app->getLoggedIn() == true)
            {
                App::lecturerMenu(lecturer);
            }
            break;
        }
    }
    if (isLogin == false)
    {
        cout << "\nLogin failed\n\n";
    }
}

void App::loginAsStaff()
{
    SchoolManager *schoolManager = SchoolManager::getInstance();
    App *app = App::getInstance();
    cout << "Login as staff" << endl;
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
    for (auto data : schoolManager->getDataStaff())
    {
        if (data.second.getUserName() == username && data.second.getPassword() == password)
        {
            Staff *staff = &data.second;
            isLogin = true;
            cout << "\n\nLogin successfully\n";
            app->setLoggedIn(true);
            while (true && app->getLoggedIn() == true)
            {
                App::staffMenu(staff);
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

void App::studentMenu(Person *person)
{
    if (person->getType() != studentCode)
    {
        cout << "Invalid role" << endl;
        return;
    }
    Student *student = (Student *)person;
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
        cout << "\n\nView profile\n";
        student->viewProfile();
        break;
    case 2:
        cout << "\n\nView course\n";
        student->viewCourse();
        break;
    case 3:
        cout << "\n\nView score\n";
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

void App::lecturerMenu(Person *person)
{
    if (person->getType() != lecturerCode)
    {
        cout << "Invalid role" << endl;
        return;
    }
    Lecturer *lecturer = (Lecturer *)person;
    cout << "Menu" << endl;
    cout << "1.View profile" << endl;
    cout << "2.View course" << endl;
    cout << "3.Logout" << endl;
    cout << "Your choice: ";
    string choice;
    getline(cin, choice);
    switch (stoi(choice))
    {
    case 1:
        cout << "\n\nView profile\n";
        lecturer->viewProfile();
        break;
    case 2:
        cout << "\n\nView course\n";
        lecturer->viewCourse();
        break;
    case 3:
        App::logout();
        break;
    default:
        cout << "Invalid choice\n"
             << endl;
        break;
    }
}

void App::staffMenu(Person *person)
{
    if (person->getType() != staffCode)
    {
        cout << "Invalid role" << endl;
        return;
    }
    Staff *staff = (Staff *)person;
    cout << "Menu" << endl;
    cout << "1.View profile" << endl;
    cout << "2.View list student" << endl;
    cout << "3.View list course" << endl;
    cout << "4.View list lecturer" << endl;
    cout << "5.Logout" << endl;
    cout << "Your choice: ";
    string choice;
    getline(cin, choice);
    switch (stoi(choice))
    {
    case 1:
        cout << "\n\nView profile\n";
        staff->viewProfile();
        break;
    case 2:
        cout << "\n\nView list student\n";
        staff->viewListStudent();
        break;
    case 3:
        cout << "\n\nView list course\n";
        staff->viewListCourse();
        break;
    case 4:
        cout << "\n\nView list lecturer\n";
        staff->viewListLecturer();
        break;
    case 5:
        App::logout();
        break;
    default:
        cout << "Invalid choice\n"
             << endl;
        break;
    }
}
