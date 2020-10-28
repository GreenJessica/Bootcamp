#include <iostream>

typedef struct elementInList
{
    int valueInList;
    elementInList *nextInList;
}Elements;

Elements *headAddress;
Elements *tempItemAdress = nullptr;
Elements *currentItemAddress = nullptr;
Elements *read = nullptr;
Elements *write = nullptr;
int positions = 0;

void initMemory(char valueToAdd){
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
        positions++; //count up number of positions in the list
    }
    // If not
    else {
        headAddress=newItemAddress; // ... then make this head
    }
}

void initLastPosition(char valueToAdd) {
    // Create a new item
    Elements *newItemAddress = new Elements;
    newItemAddress->valueInList = valueToAdd; // ... holding value ...
    newItemAddress->nextInList = headAddress; // ... and pointing to head

    if (headAddress != nullptr){
        currentItemAddress = headAddress;
        while (currentItemAddress->nextInList != nullptr)
        {
            currentItemAddress = currentItemAddress->nextInList; // ...step forward untill the end is reached...
        }
        currentItemAddress->nextInList = newItemAddress; //... and then append the created item to it
    }
    write = headAddress;
    read = currentItemAddress->nextInList;
    positions++; //count up number of positions in the list
}

void displayList(){
    if (headAddress != nullptr) {
        currentItemAddress = headAddress;
        std::cout << std::endl;
        for (int i=0; i<positions; i++)
        {
            std::cout << "Address: " << currentItemAddress << " Value: " << (char)currentItemAddress->valueInList << std::endl;
            currentItemAddress = currentItemAddress->nextInList;
        }
        std::cout << std::endl;
    }
}

void writeToMemory(char valueToAdd){
    // Start from head
    currentItemAddress = headAddress;
    while (currentItemAddress->nextInList != write)
    {
        currentItemAddress = currentItemAddress->nextInList; // ...and step forward untill the write point is reached...
    }
    std::cout << "Writing: " << valueToAdd <<" to " << currentItemAddress << std::endl;
    currentItemAddress->valueInList = valueToAdd; //... and then append the created item to it
    write = write->nextInList; //count up write positions in prep of next write
}

void readFromMemory(){
    currentItemAddress = headAddress;
    while (currentItemAddress != read)
    {
        currentItemAddress = currentItemAddress->nextInList;
    }
    std::cout << "Reading: " << (char)currentItemAddress->valueInList <<" from " << currentItemAddress << std::endl;
    read = read->nextInList; //count up read positions in prep of next write
}

void deleteMemory(){
    if (headAddress != nullptr){
        currentItemAddress = headAddress;
        for (int i=0; i<positions; i++) {
            Elements *removeAddress = headAddress; // point to head location
            headAddress = headAddress->nextInList; // point to new head
            delete removeAddress; // remove the old location
        }
    }
}