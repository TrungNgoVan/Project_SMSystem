#include <iostream>
#include "Staff.h"

using namespace std;

Staff::Staff()
{
    this->_staffID = "S0000001";
}

Staff::Staff(string staffID){
    this->_staffID = staffID;
}

Staff::~Staff()
{
}

int Staff::getType(){
    return 3;
}

string Staff::getID()
{
    return this->_staffID;
}

void Staff::setStaffID(string staffID)
{
    this->_staffID = staffID;
}
