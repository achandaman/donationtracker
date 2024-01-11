

#include "VacationAccount.h"
#include "BloodDonation.h"
#include "Calendar.h"
#include <iostream>
#include <string>

using namespace std;

VacationAccount::VacationAccount(int EmployeeID)
{
    mBalance = 0;
    //validates ID is 6 digits long, with digits between 0-9
    if (100000 <= EmployeeID && EmployeeID <= 999999) {
        mID = EmployeeID;
    }
    else {
        mID = -1;
    }
}

double VacationAccount::getBalance()
{
    return mBalance;
}

int VacationAccount::getID()
{
    return mID;
}

bool VacationAccount::addVacationToAccount(BloodDonation donation, DonationLog account, Calendar today)
{
    //checks that donation ID and account ID matches & that ID, age, and weight are valid inputs
    if (donation.getID() == mID && account.getID() == mID && donation.getID() != -1 && donation.getAge() != -1 && donation.getWeight() != -1) {
       // if donation ID matches and donation is valid, add 4 hours to balance
        if (account.canDonate(today) == true) {
            mBalance += 4;
            return true;
        }
    }
    return false;
}
