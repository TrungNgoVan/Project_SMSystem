#include <string>
#include "Person.h"

using namespace std;

Person::Person()
{

}

Person::~Person()
{
    
}


string Person::getUserName()
{
    return this->_userName;
}

void Person::setUserName(string userName)
{
    this->_userName = userName;
}

string Person::getFullName()
{
    return this->_fullName;
}

void Person::setFullName(string fullName){
    this->_fullName = fullName;
}

int getType() {
    return 0;
}

string Person::getEmail()
{
    return this->_email;
}

void Person::setEmail(string email)
{
    this->_email = email;
}

string Person::getPhoneNumber()
{
    return this->_phoneNumber;
}

void Person::setPhoneNumber(string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

string Person::getPassword()
{
    return this->_password;
}

void Person::setPassword(string password)
{
    this->_password = password;
}
