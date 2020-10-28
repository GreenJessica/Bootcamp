#include "serviceRecord.h"

void Record::setValues(Date date, PaymentMethods payment, std::string customerName, PerformedService performedService, PartsChanged part) {
    this->date.year = date.year;
    this->date.month = date.month;
    this->date.day = date.day;
    this->payment.method = payment.method;
    this->payment.method = payment.method;
    this->customerName = customerName;
    this->performedService = performedService;
    this->partsChanged = part;
}

void Record::getRecordValues() {
    std::cout << "Customer name: " << this->customerName << std::endl;
    std::cout << "Performed service: " << this->performedService << std::endl;
    std::cout << "Exchanged parts:" << this->partsChanged <<"\n" << std::endl;
}

void Record::printRecord() {
    std::cout << "Year: " << this->date.year << std::endl;
    std::cout << "Month: " << this->date.month << std::endl;
    std::cout << "Day: " << this->date.day << std::endl;

    switch (this->payment.method){
        case 0:
            std::cout << "Payment method: Cash" << std::endl;
            break;
        case 1:
            std::cout << "Payment method: Card" << std::endl;
            break;
        case 2:
            std::cout << "Payment method: Check" << std::endl;
            break;
        case 3:
            std::cout << "Payment method: Paypal" << std::endl;
            break;
        case 4:
            std::cout << "Payment method: Swish" << std::endl;
            break;            
        default:
            break;
    }

    // std::cout << "Payment method: " << this->payment.method << std::endl;
    std::cout << "Amount: " << this->payment.amount << std::endl;
    this->getRecordValues();
}

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