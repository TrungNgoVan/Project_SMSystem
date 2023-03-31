#pragma once
#include <string>
using namespace std;

enum Type
{
    studentCode = 1,
    lecturerCode = 2,
    staffCode = 3
};

class Person
{
private:
    string _userName;
    string _password;
    string _fullName;
    string _email;
    string _phoneNumber;

public:
    Person();
    Person(string, string, string, string, string);
    ~Person();

    virtual int getType() = 0;
    virtual string getID() = 0;

    void setUserName(string);
    string getUserName();

    void setFullName(string);
    string getFullName();

    void setPhoneNumber(string);
    string getPhoneNumber();

    void setEmail(string);
    string getEmail();

    void setPassword(string);
    string getPassword();

    bool operator==(Person *other);
};
