#include <iostream>

void initMemory(char valueToAdd);
void initLastPosition(char valueToAdd);
void displayList();
void writeToMemory(char valueToAdd);
void readFromMemory();
void deleteMemory();
/*
int positions = 0;
int read = 0;
int write = 0;*/

int main() {
    char listValue; 

    // Initiate 10 positions
    initMemory('a');
    initMemory('b');
    initMemory('c');
    initMemory('d');
    initMemory('e');
    initMemory('f');
    initMemory('g');
    initMemory('h');
    initMemory('i');
    // Add final element and point to the first item
    initLastPosition('j');

    // Display entire list for overview
    displayList();

    // Use memory
    writeToMemory('&');
    writeToMemory('5');
    writeToMemory('@');
    readFromMemory();
    writeToMemory('0');
    readFromMemory();
    readFromMemory();
    readFromMemory();

    // Display entire list for overview
    displayList();
    
    deleteMemory();
}