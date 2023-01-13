#pragma once 
#include <string>
#include "Person.h"

using namespace std;

class Staff : public Person {
private:
    string _staffID;
public:
    Staff();
    Staff(string);
    ~Staff();
    int getType();
    string getID();
    string getStaffID();
    void setStaffID(string);
};
