#include <iostream>

void initMemory();
void writeToMemory(std::string content);
void readFromMemory();
void readFromMemory(int skipPositions);


int main() {
    char listValue; 

    std::cout <<"Initiate a memory with 16 positions" << std::endl; 
    initMemory();

    std::cout <<"Read the entire list +1 to overflow the counter" << std::endl; 
    for (int i=0; i<17; i++){
    readFromMemory();
    }

    writeToMemory("1");
    writeToMemory("2");
    writeToMemory("3");

    readFromMemory();

    std::cout <<"... and if 3 older value are no longer valid skip them when reading" << std::endl; 
    readFromMemory(3);

    std::cout <<"... Continue adding stuff" << std::endl; 
    writeToMemory("!");
    writeToMemory("@");
    writeToMemory("#");

    std::cout <<"Display entire list for overview" << std::endl; 
    for (int i=0; i<16; i++){
        readFromMemory();
    }

    std::cout <<"... Continue adding stuff to overflow write counter" << std::endl; 
    writeToMemory("!");
    writeToMemory("@");
    writeToMemory("#");
    writeToMemory("!");
    writeToMemory("@");
    writeToMemory("#");
    writeToMemory("!");
    writeToMemory("@");
    writeToMemory("#");
    writeToMemory("#");
    writeToMemory("Last message should end up at position 0");
    

    std::cout <<"Display entire list for overview" << std::endl; 
    for (int i=0; i<16; i++){
        readFromMemory();
    }
}