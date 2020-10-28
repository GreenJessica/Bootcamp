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

    // Attributes
    PaymentMethod method;
    int amount;
};

class Record {
public:
    // Methods
    Record() = default;
    ~Record() = default;

    void setValues(Date date, PaymentMethods payment, std::string customerName, PerformedService performedService, PartsChanged part);
    void getRecordValues();
    
    void printRecord();

    // Attributes
    int numberInList;

private:
    // Attributes
    Date date;
    PaymentMethods payment;
    std::string customerName;
    PerformedService performedService;
    PartsChanged partsChanged;
};