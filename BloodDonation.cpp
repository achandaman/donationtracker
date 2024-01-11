

#include "BloodDonation.h"
#include <iostream>
#include <string>

using namespace std;

BloodDonation::BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight)
{
    //ID must be 6 digits, all combinations of digits 0-9 included in numbers 1000000 to 999999
    if (100000 <= EmployeeID && EmployeeID <= 999999) {
        mID = EmployeeID;
    }
    else {
        mID = -1;
    }
    
    //number passed in should greater than or equal to 21 AND less than or equal to 65 to be valid
    if (EmployeeAge >= 21 && EmployeeAge <= 65){
        mAge = EmployeeAge;
    }
    else{
        mAge = -1;
    }
    //weight must be between 101.00 and 280.00, inclusive
    if (EmployeeWeight >= 101.00 && EmployeeWeight <= 280.00){
        mWeight = EmployeeWeight;
    }
    else{
        mWeight = -1;
    }
}

void BloodDonation::setID(int EmployeeID)
{
    //ID must be 6 digits, all combinations of digits 0-9 included in numbers 1000000 to 999999
    if (100000 <= EmployeeID && EmployeeID <= 999999) {
        mID = EmployeeID;
    }
    else {
        mID = -1;
    }
}
int BloodDonation::getID()
{
    return mID;
}


void BloodDonation::setAge(int EmployeeAge)
{
    //validates age is between 21 and 65
    if (EmployeeAge >= 21 && EmployeeAge <= 65){
        mAge = EmployeeAge;
    }
    else {
        mAge = -1;
    }
}

int BloodDonation::getAge()
{
    return mAge;
}

void BloodDonation::setWeight(double EmployeeWeight)
{
    //validates weight is in the range of 101 and 280, inclusive
    if (EmployeeWeight >= 101.00 && EmployeeWeight <= 280.00){
        mWeight = EmployeeWeight;
    }
    else{
        mWeight = -1;
    }
}
double BloodDonation::getWeight()
{
    return mWeight;
}


