

#ifndef BloodDonation_h
#define BloodDonation_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


class BloodDonation
{
private:
    int mID;
    int mAge;
    double mWeight;
public:
    BloodDonation(int EmployeeID, int EmployeeAge, double EmployeeWeight);
    
    int getID();
    void setID(int EmployeeID);
    
    int getAge();
    void setAge(int EmployeeAge);
    
    double getWeight();
    void setWeight(double EmployeeWeight);
    friend class DonationLog;
    
};

#endif
