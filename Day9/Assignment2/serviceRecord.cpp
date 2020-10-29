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