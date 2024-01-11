// Blood Donation Tracker

#include <iostream>
#include <cassert>
#include <string>
#include "BloodDonation.h"
#include "VacationAccount.h"
#include "Calendar.h"

using namespace std;

int main() {
    //test constructor delegation of Calendar
    Calendar test1(3);
    assert(test1.getMonth() == 3 && test1.getDay() == 0 && test1.getYear() == 0);
    
    Calendar test2(5, 17);
    assert(test2.getMonth() == 5 && test2.getDay() == 17 && test2.getYear() == 0);

    Calendar Test2(7, 9, 2004);
    assert(Test2.getMonth() == 7 && Test2.getDay() == 9 && Test2.getYear() == 2004);
   
    //test constructor overloading in DonationLog
    DonationLog test3(123456);
    assert(test3.getLastMonth() == 0 && test3.getLastDay() == 0);
    DonationLog test4(945738, Test2);
    assert(test4.getLastMonth() == 7 && test4.getLastDay() == 9 && test4.getLastYear() == 2004);
    
    //test timeBetweenMonths
    Calendar month(6, 23, 2053);
    Calendar month2(12, 22, 2052);
    DonationLog prevYear(203892, month2);
    //current month is 6 and last month is 12 of the prev. year -> time between is 6
    assert(prevYear.timeBetweenMonths(month) == 6);
    
    Calendar month3(12, 10, 2012);
    Calendar month4(6, 10, 2012);
    DonationLog sameYear(294590, month4);
    //months are in the same year, should subtract 12 - 6
    assert(sameYear.timeBetweenMonths(month3) == 6);
    
    Calendar month5(4, 20, 2023);
    Calendar month6(6, 29, 2016);
    DonationLog manyYears(194802, month6);
    //months are many years apart
    assert(manyYears.timeBetweenMonths(month5) == 70);
    
    Calendar month7(2, 13, 2023);
    Calendar month8(2, 4, 2022);
    DonationLog oneYear(293849, month8);
    //exactly one year between each date
    assert(oneYear.timeBetweenMonths(month7) == 12);
    
    Calendar month9(5, 29, 2023);
    Calendar month10(4, 29, 2023);
    DonationLog oneMonth(934894, month10);
    //exactly one month between dates
    assert(oneMonth.timeBetweenMonths(month9) == 1);
    //tests when both dates are in the same month
    Calendar month11(5, 10, 2023);
    DonationLog sameMonth(238921, month11);
    assert(sameMonth.timeBetweenMonths(month9) == 0);
    
    //test canDonate and addVacationToAccount
    Calendar today(3, 25, 2023);
    VacationAccount account1(490284);
    BloodDonation donation1(490284, 30, 120);

    Calendar testDay(3, 25, 2023);
    DonationLog sameDay(490284, testDay);
    //test invalid donation date does not add to balance -> same day
    assert(sameDay.canDonate(today) == false);
    assert(account1.getBalance() == 0);
    assert(account1.addVacationToAccount(donation1, sameDay, today) == false);
    
    //test edge month 6 is exactly 6 months before today's month 3
    VacationAccount account2(294848);
    BloodDonation donation2(294848, 23, 190);
    Calendar EdgeMonth(6, 30, 2022);
    DonationLog test5(294848, EdgeMonth);
    assert(test5.canDonate(today) == true);
    assert(account2.addVacationToAccount(donation2, test5, today) == true);
    //valid donation date gets added to balance
    assert(account2.getBalance() == 4);

    //tests if year "resets" properly so that the time between 12 of the previous year and 3 of the next year returns as 3, not 9
    VacationAccount account3(344948);
    BloodDonation donation3(344948, 58, 102);
    Calendar EdgeMonth2(12, 18, 2022);
    DonationLog test6(344948, EdgeMonth2);
    assert(test6.timeBetweenMonths(today) == 3);
    assert(test6.canDonate(today) == false);
    assert(account3.addVacationToAccount(donation3, test6, today) == false);
    //invalid donation date does not get added
    assert(account3.getBalance() == 0);

    
    //tests date 6 months apart with the same day
    Calendar EdgeDay(9, 25, 2022);
    DonationLog test7(182739, EdgeDay);
    //date "today" becomes the last date to update DonationLog and "nextDate" is the current day
    Calendar nextDate(8, 30, 2024);
    DonationLog Test7(182739, today);
    BloodDonation donation4(182739, 47, 156);
    VacationAccount account4(182739);
    assert(test7.canDonate(today) == true);
    assert(account4.addVacationToAccount(donation4, test7, today) == true);
    assert(account4.getBalance() == 4);
    //"today" as last date and "nextDate" as the current day is a valid donation, adding 4 to balance
    assert(Test7.canDonate(nextDate) == true);
    assert(account4.addVacationToAccount(donation4, Test7, nextDate) == true);
    assert(account4.getBalance() == 8);
    
    
    BloodDonation donation5(203943, 29, 166.7);
    VacationAccount account5(203943);
    Calendar EdgeDay2(9, 24, 2022);
    DonationLog test8 (387462, EdgeDay2);
    //test edge day where month is 6 apart from current month and day is 1 before current day -> this is valid
    assert(test8.canDonate(today) == true);
    //test for matching IDs between VacationAccount, BloodDonation AND DonationLog
    assert(account5.addVacationToAccount(donation5, test8, today) == false);
    assert(account5.getBalance() == 0);

    //test edge day where month is 6 apart from current but day is 1 after, meaning 6 months have not passed -> invalid
    Calendar EdgeDay3(9, 26, 2022);
    DonationLog test9(592742, EdgeDay3);
    assert(test9.canDonate(today) == false);

    //test average day
    Calendar LastDate(4, 1, 2012);
    DonationLog test10(291473, LastDate);
    assert(test10.canDonate(today) == true);
        
    
    
    
}
