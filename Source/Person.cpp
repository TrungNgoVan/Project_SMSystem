#include <string>
#include <Person.h>

using namespace std;

string Person::getEmail(){
    return this->_email;
}

void Person::setEmail(string email){
    this->_email=email;
}

string Person::getPhoneNumber(){
    return this->_phoneNumber;
}

void Person::setPhoneNumber(string phoneNumber){
    this->_phoneNumber = phoneNumber;
}

string Person::getPassword(){
    return this->_password;
}

void Person::setPassword(string password){
    this->_password = password;
}
