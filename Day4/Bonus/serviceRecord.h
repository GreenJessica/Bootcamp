#ifndef serviceRecord_h
#define serviceRecord_h

# include <iostream>

enum Month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
enum PaymentMethod {cash, card, check, paypal, swish};
enum PerformedService {service, repair, retrofit};
enum PartsChanged {none, oil, brakepads, extraLight};

class Date {
public:
    // Methods
    Date() = default;
    ~Date() = default;
    
    virtual void setDate(int year, Month month, int day) = 0;

    // Attributes
    int year;
    Month month;
    int day;
};

class PaymentMethods{
public: 
    // Methods
    PaymentMethods() = default;
    ~PaymentMethods() = default;

    virtual void setPayment(PaymentMethod method, int amount);

    // Attributes
    PaymentMethod method;
    int amount;
};

class Record {
public:
    // Methods
    Record() = default;
    ~Record() = default;

    void setValues(std::string customerName, PerformedService performedService, PartsChanged part);
    void getRecordValues();
    
    void printRecord();

    void setDate(int year, Month month, int day);
    void setPayment(PaymentMethod method, int amount);

private:
    // Attributes
    Date date;
    PaymentMethods payment;
    std::string customerName;
    PerformedService performedService;
    PartsChanged partsChanged;
};

#endif