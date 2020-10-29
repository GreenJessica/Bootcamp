#include <iostream>
#include "serviceRecord.h"

void testDateClass(int year, Month month, int day);

int main (){
    testDateClass(2000, jan, 31); // Inside day & year boundary
    testDateClass(1999, jan, 31); // Outside year boundary
    testDateClass(2020, jan, 32); // Outside day boundary
    testDateClass(2020, nov, 31); // Outside day boundary
    testDateClass(2020, nov, 30); // Inside day boundary
    testDateClass(2020, feb, 30); // Outside day boundary
    testDateClass(2020, feb, 29); // Inside leap year boundary
    testDateClass(2019, feb, 29); // Outside date boundary
    testDateClass(2019, feb, 28); // Inside date boundary
    testDateClass(2000, jan, 1); // Inside day boundary
    testDateClass(2000, jan, 0); // Outside day boundary

    return 0;
}

void testDateClass(int year, Month month, int day) {
    bool result = false;
    // Prep
    Date testItem;
    testItem.year = year;
    testItem.month = month;
    testItem.day = day;

    std::cout <<"Testing: " << testItem.year << " " << testItem.month << " " << testItem.day << std::endl;

    // Possible to set days that don't exist?
    if(testItem.day < 1 || testItem.day > 31) {
        std::cout << "The date should be 1-31 " <<std::endl;
    }
    // What about 31 days on a 30 day month?
    else if(testItem.month == apr || testItem.month == jun || testItem.month == sep || testItem.month == nov) {
        if (testItem.day > 30) {
            std::cout << "This month should only have 30 days" <<std::endl;
        }
        else result = true;
    }
    // And february? 
    else if(testItem.month == feb) {
        // leap year?
        if (testItem.year % 4 == 0){
            if(testItem.year % 100 == 0) {
                if(testItem.year % 400 == 0) {
                    if (testItem.day > 29) {
                        std::cout << "February should only have 29 days on a leap year" <<std::endl;
                    }
                    else result = true;
                }
                else {
                    if (testItem.day > 28) {
                        std::cout << "February should only have 28 days on a normal year" <<std::endl;
                    }
                    else result = true;
                }
            }
            else {
                if (testItem.day > 29) {
                    std::cout << "February should only have 29 days on a leap year" <<std::endl;
                }
                else result = true;
            }
        }
        else {
            if (testItem.day > 28) {
                std::cout << "February should only have 28 days on a normal year" <<std::endl;
            }
            else result = true;
        }
    }
    // Possible to enter a year before the workshop started?
    // Assuming initiated in year 2k
    else if(testItem.year <2000) {
        std::cout << "The workshop was not in buissness on this date" << std::endl;
    }
    else result = true;

    if (result) std::cout <<"The test has passed" << std::endl;
}