

#ifndef Calendar_h
#define Calendar_h

#include <iostream>
#include <string>

using namespace std;

class Calendar
{
private:
    int thisMonth;
    int today;
    int thisYear;
public:
    //constructor delegation based on what info is passed in about the date
    Calendar(int month) {
        if (month >=1 && month <= 12) {
            thisMonth = month;
        }
        else {
            thisMonth = 0;
        }
        today = 0;
        thisYear = 0;
    }
    Calendar(int month, int day) : Calendar(month) {
        if (day >= 1 && day <= 30) {
            today = day;
        }
        else {
            today = 0;
        }
    }
    Calendar(int month, int day, int year) : Calendar(month, day) {
        if (year >= 2000 && year <= 3000) {
            thisYear = year;
        }
        else {
            thisYear = 0;
        }
    }

    friend class DonationLog;
    friend class VacationAccount;
    int getMonth();
    int getDay();
    int getYear();
};

class DonationLog
{
private:
    Calendar lastDate;
    int lastMonth;
    int lastDay;
    int lastYear;
    int mID;
    int time;
public:
    friend class VacationAccount;
    
    DonationLog(int EmployeeID);
    DonationLog(int EmployeeID, Calendar lastDate);
    bool canDonate(Calendar today);
    int timeBetweenMonths(Calendar today);
    int getID();
    int getLastMonth();
    int getLastDay();
    int getLastYear();
    int getTime();


};


#endif /* Calendar_h */
