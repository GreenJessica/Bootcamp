#include "serviceRecord.h"

int main (){
    Date date;
    PaymentMethods payment;
    PerformedService service;
    PartsChanged part;

    date.year = 1981;
    date.month = nov;
    date.day = 06;
    payment.method = cash;
    payment.amount = 500;
    service = service;
    part = none;
    
    Record first;
    first.setValues(date, payment, "Jessica", service, part);

    date.year = 2020;
    date.month = oct;
    date.day = 21;
    payment.method = swish;
    payment.amount = 3000;
    service = repair;
    part = brakepads;
    
    Record second;
    second.setValues(date, payment, "Pelle", service, part);

    first.printRecord();
    second.printRecord();
}