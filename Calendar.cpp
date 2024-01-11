

#include <stdio.h>
#include <string>
#include "Calendar.h"
#include "VacationAccount.h"

using namespace std;

int Calendar::getMonth() {
    return thisMonth;
}
int Calendar::getDay() {
    return today;
}
int Calendar::getYear() {
    return thisYear;
}

//lastDate set to month 0, day 0, year 0 if no date passed in
DonationLog::DonationLog(int EmployeeID) : lastDate(0, 0, 0) {
    if (100000 <= EmployeeID && EmployeeID <= 999999) {
        mID = EmployeeID;
    }
    else {
        mID = -1;
    }
    lastMonth = 0;
    lastDay = 0;
    lastYear = 0;
}

//if date is passed in, it is stored as the most recent donation date
DonationLog::DonationLog(int EmployeeID, Calendar date) : lastDate(0, 0, 0){
    if (100000 <= EmployeeID && EmployeeID <= 999999) {
        mID = EmployeeID;
    }
    else {
        mID = -1;
    }
    lastMonth = date.getMonth();
    lastDay = date.getDay();
    lastYear = date.getYear();
    time = 0;

}

int DonationLog::getID() {
    return mID;
}

int DonationLog::getLastMonth() {
    return lastMonth;
}

int DonationLog::getLastDay() {
    return lastDay;
}

int DonationLog::getLastYear() {
    return lastYear;
}

int DonationLog::getTime() {
    return time;
}

int DonationLog::timeBetweenMonths(Calendar today) {
    int thisYear = today.getYear();
    int thisMonth = today.getMonth();
    //if current month is in the same year as the last month of donation, subtract to find the difference
    if (lastYear == thisYear) {
        time = thisMonth - lastMonth;
    }
    //if the last month of donation is in a past year, must calculate the number of years that passed in months
    else {
        //find total number of years that have passed
        int yearsBetween = thisYear - lastYear;
        //if last donation was in the previous year, get to the next year by subtracting lastMonth from 12, then add the current month
        if (yearsBetween == 1) {
            time = thisMonth + (12 - lastMonth);
        }
        //if last donation was > 1 year apart
        else{
            //find how many months must be added to the last month of donation to get to the next calendar year
            int roundToNextYear = 12 - lastMonth;
            //subtract 2 from years between because time between the last month and the next year, as well as the next year and today's date is not a full year
            int wholeYears = (yearsBetween - 2);
            if (wholeYears < 0) {
                wholeYears = 0;
            }
            else {
                wholeYears = wholeYears * 12;
            }
            //sum up months to find total number of months that have passed between today and the last donation date
            time = roundToNextYear + wholeYears + thisMonth;
        }
    }
    return time;
}

bool DonationLog::canDonate(Calendar today) {
//the current month must match that of the nextValid month and the day must be greater than the last day to make sure the full 6 months have passed
    if (timeBetweenMonths(today) > 6 ){
        return true;
    }
    else if (timeBetweenMonths(today) == 6 && lastDay <= today.getDay()) {
            return true;
    }
    return false;
}

