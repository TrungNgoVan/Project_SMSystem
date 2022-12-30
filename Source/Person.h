#pragma once
#include <string>
using namespace std;

class Person
{
private:
    string _userName;
    string _fullName;
    string _email;
    string _phoneNumber;
    string _password;
// protected:
//     int _type;
//     // 1 - Student
//     // 2 - Lecturer

public:
    Person();
    ~Person();

    virtual int getType() = 0;

    void setPhoneNumber(string);
    string getPhoneNumber();

    void setEmail(string);
    string getEmail();

    void setPassword(string);
    string getPassword();
};
