#include "serviceRecord.cpp"

int main (){
    PerformedService service;
    PartsChanged part;
    
    Record first;
    service = service;
    part = none;
        
    first.setDate(1981,nov,06);
    first.setPayment(cash, 500);
    first.setValues("Jessica", service, part);

    
    Record second;
    service = repair;
    part = brakepads;

    second.setDate(2020,oct,21);
    second.setPayment(swish, 3000);
    second.setValues("Pelle", service, part);

    first.printRecord();
    second.printRecord();
}