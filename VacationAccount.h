

#ifndef VacationAccount_h
#define VacationAccount_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "BloodDonation.h"
#include "Calendar.h"


class VacationAccount{
private:
    int mID;
    double mBalance;
public:
    VacationAccount(int EmployeeID);
    double getBalance();
    int getID();
    bool addVacationToAccount(BloodDonation donation, DonationLog account, Calendar today);
};

#endif
