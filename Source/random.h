#pragma once
#include <string>

class Person
{
private:
    std::string _name;
    int _age;
public:
    Person(){
        //Do nothing
    }
    int getAge();
    void setAge(int value);
};