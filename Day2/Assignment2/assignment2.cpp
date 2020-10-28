#include <iostream>
typedef struct elementInList
{
    int valueInList;
    elementInList *nextInList;
}Elements;

Elements *headAddress = nullptr;
Elements *tempItemAdress = nullptr;
Elements *currentItemAddress = nullptr;

void addToEndOfList(int valueToAdd){
    // Create a new item
    Elements *newItemAddress = new Elements;
    newItemAddress->valueInList = valueToAdd; // ... holding value ...
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

void addToAywhere(int listPosition, int listValue) {
    // Create a new item
    Elements *newItemAddress = new Elements;
    newItemAddress->valueInList = listValue;

    currentItemAddress = headAddress;

    // Check through the list untill we reach the value after the one to add
    while (currentItemAddress != nullptr && currentItemAddress->valueInList != listPosition) {
        tempItemAdress = currentItemAddress; // .. while saving the address just checked for one loop...
        currentItemAddress = currentItemAddress->nextInList; // ... and proceeding to next item
    }
    if (currentItemAddress == nullptr) {
        std::cout << "No previous item held the value " << listPosition << ". Adding the item to the end of the list \n"; // Inform if nothing was found
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

void deleteItem(int valueToRemove){
    Elements *removeAddress = nullptr; 
    tempItemAdress = headAddress;
    currentItemAddress = headAddress;

    // Check through the list untill we reach the end or the value to remove
    while (currentItemAddress != nullptr && currentItemAddress->valueInList != valueToRemove) {
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
            std::cout << "Address: " << currentItemAddress << " Value: " << currentItemAddress->valueInList << std::endl;
            currentItemAddress = currentItemAddress->nextInList;
        }
    }
    else
    {
        std::cout << "There is no list to show yet. \n";
    }
}

int main() {
    int userAction;
    int listValue;
    int listPosition;

    int exitFlag = 0;

    for (;exitFlag<1;) {
        // Choose action
        std::cout << "Please chose action to perform \n";
        std::cout << "   1. Add item \n";
        std::cout << "   2. Remove first item in the list \n"; 
        std::cout << "   3. Print the list \n"; 
        std::cout << "   4. Add item at any position in the list \n";
        std::cout << "   5. Remove any item in the list \n";
        std::cout << "   6. Reverse the list \n";
        std::cout << "   7. Exit program \n";
        std::cin >> userAction;
        switch (userAction){
            case 1:
                std::cout << "Which number do you want to add?" <<std::endl;
                std::cin >> listValue;
                addToEndOfList(listValue);
                break;
            case 2:
                deleteFirstItem();
                break;
            case 3:
                displayList();
                break;
            case 4:
                std::cout << "Enter the number you want your new item to point towards" <<std::endl;
                std::cin >> listPosition;
                std::cout << "Which number do you want to add?" <<std::endl;
                std::cin >> listValue;
                addToAywhere(listPosition, listValue);
                break;
            case 5:
                std::cout << "Which number do you want to delete?" <<std::endl;
                std::cin >> listValue;
                deleteItem(listValue);
                break;
            case 6:
                std::cout << "Not implemented yet" <<std::endl;
                break;
            case 7:
                std::cout << "Exiting program " <<std::endl;
                exitFlag = 1;
                break;
            default:
                std::cout << "You chosed an illegal action " <<std::endl;
        }
    }

}