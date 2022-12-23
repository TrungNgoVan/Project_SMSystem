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
public: //Constructor & destructor
public:
    void setPhoneNumber(string);
    string getPhoneNumber();

    void setEmail(string);
    string getEmail();

    void setPassword(string);
    string getPassword();
};
