#include "serviceRecord.cpp"

typedef struct elementInList
{
    Record record;
    elementInList *nextInList;
}Elements;

Elements *headAddress = nullptr;
Elements *tempItemAdress = nullptr;
Elements *currentItemAddress = nullptr;

void addToEndOfList(Record record){
    // Create a new item
    Elements *newItemAddress = new Elements;
    newItemAddress->record = record; // ... holding value ...
    newItemAddress->nextInList = nullptr; // ... and pointing to nothing so far

    // If there are previous items in the list
    if (headAddress != nullptr){
        currentItemAddress = headAddress;
        while (currentItemAddress->nextInList != nullptr)
        {
            currentItemAddress = currentItemAddress->nextInList; // ...step forward untill the end is reached...
        }
        currentItemAddress->nextInList = newItemAddress; //... and then append the created item to it
    }
    // If not
    else {
        headAddress=newItemAddress; // ... then make this head
    }
}

void addToAywhere(Record record) {
    // Create a new item
    Elements *newItemAddress = new Elements;
    newItemAddress->record = record;

    currentItemAddress = headAddress;

    // Check through the list untill we reach the position to add record too
    while (currentItemAddress != nullptr && currentItemAddress->record.numberInList != newItemAddress->record.numberInList) {
        tempItemAdress = currentItemAddress; // .. while saving the address just checked for one loop...
        currentItemAddress = currentItemAddress->nextInList; // ... and proceeding to next item
    }
    if (currentItemAddress == nullptr) {
        std::cout << "No previous item held the value " << record.numberInList << ". Adding the item to the end of the list \n"; // Inform if nothing was found
    }
    tempItemAdress->nextInList = newItemAddress; // ...redirect value before to new...
    newItemAddress->nextInList = currentItemAddress; // ... point new to the one after
}

void deleteFirstItem(){
    if (headAddress != nullptr) {
        Elements *removeAddress = headAddress; // point to head location
        headAddress = headAddress->nextInList; // point to new head
        delete removeAddress; // remove the old location
    }
    else
    {
        std::cout << "There is no list to delete from. \n";
    }
}

void deleteItem(Record record){
    Elements *removeAddress = nullptr; 
    tempItemAdress = headAddress;
    currentItemAddress = headAddress;

    // Check through the list untill we reach the end or the value to remove
    while (currentItemAddress != nullptr && currentItemAddress->record.numberInList != record.numberInList) {
        tempItemAdress = currentItemAddress; // .. while saving the address just checked for one loop...
        currentItemAddress = currentItemAddress->nextInList; // ... and proceeding to next item
    }

    if (currentItemAddress == nullptr) {
        std::cout << "The list did not contain the chosen value \n"; // Inform if nothing was found
        delete removeAddress; 
    }
    else {
        removeAddress = currentItemAddress; // identify the item to remove...
        currentItemAddress = currentItemAddress->nextInList; // ...identify the item after the "to be deleted one"...
        tempItemAdress->nextInList = currentItemAddress; // ... and point the previous item to it...
        delete removeAddress; 
    }
}

void displayList(){
    if (headAddress != nullptr) {
        currentItemAddress = headAddress;
        while (currentItemAddress != nullptr)
        {
            std::cout << "Address: " << currentItemAddress << std::endl;
            std::cout << "Record number: " << currentItemAddress->record.numberInList << std::endl;
            currentItemAddress->record.printRecord();
            currentItemAddress = currentItemAddress->nextInList;
        }
    }
    else
    {
        std::cout << "There is no list to show yet. \n";
    }
}

int main() {
    int userAction, exitFlag = 0;
    Record record;

   
    for (;exitFlag<1;) {
        // Choose action
        std::cout << "Please chose action to perform \n";
        std::cout << "   1. Add items \n";
        std::cout << "   2. Remove first item in the list \n"; 
        std::cout << "   3. Print the list \n"; 
        std::cout << "   4. Add item at any position in the list \n";
        std::cout << "   5. Remove any item in the list \n";
        std::cout << "   6. Reverse the list \n";
        std::cout << "   7. Exit program \n";
        std::cin >> userAction;
        switch (userAction){
            case 1:
                // Using fixed records on each position to Keep it simple
                // Create an initial list
                {
                    Date date;
                    PaymentMethods payment;

                    date.year = 1981;
                    date.month = nov;
                    date.day = 06;
                    payment.method = cash;
                    payment.amount = 500; 

                    record.numberInList = 1;
                    record.setValues(date, payment, "Jessica", retrofit, extraLight);
                    addToEndOfList(record);

                    date.year = 1989;
                    date.month = jun;
                    date.day = 30;
                    payment.method = check;
                    payment.amount = 1000; 

                    record.numberInList = 2;
                    record.setValues(date, payment, "Anders", repair, brakepads);
                    addToEndOfList(record);

                    date.year = 1994;
                    date.month = aug;
                    date.day = 01;
                    payment.method = card;
                    payment.amount = 1500; 

                    record.numberInList = 3;
                    record.setValues(date, payment, "Maja", service, none);
                    addToEndOfList(record);

                    date.year = 2008;
                    date.month = dec;
                    date.day = 31;
                    payment.method = paypal;
                    payment.amount = 1500; 

                    record.numberInList = 4;
                    record.setValues(date, payment, "Quintus", service, oil);
                    addToEndOfList(record);

                    date.year = 2015;
                    date.month = jan;
                    date.day = 03;
                    payment.method = swish;
                    payment.amount = 3000; 

                    record.numberInList = 5;
                    record.setValues(date, payment, "Ada", repair, brakepads);
                    addToEndOfList(record);
                }
                break;
            case 2:
                deleteFirstItem();
                break;
            case 3:
                displayList();
                break;
            case 4:
                std::cout << "Enter the position you want your new item to receive" <<std::endl;
                std::cin >> record.numberInList;
                
                // TODO: Call function to create item
                
                addToAywhere(record);
                break;
            case 5:
                std::cout << "Which number do you want to delete?" <<std::endl;
                std::cin >> record.numberInList;
                deleteItem(record);
                break;
            case 6:
                std::cout << "Not implemented yet" <<std::endl;
                break;
            case 7:
                std::cout << "Exiting program " <<std::endl;
                // TODO: delete all items before closing program
                exitFlag = 1;
                break;
            default:
                std::cout << "You chosed an illegal action " <<std::endl;
        }
    }

}