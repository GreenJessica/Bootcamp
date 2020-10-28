#include <iostream>
#include <vector>
#include <string>
#include <bitset>

std::string memory[16];

struct field{
    unsigned bitsWrite: 4;
    unsigned bitsRead: 4;
};

field counters;

void initMemory(){
    for (int i=0; i<16; i++) {
        memory[i] = "initiated memory cell ";
    }
    counters.bitsRead = 0;
    counters.bitsWrite = 0;
}

void writeToMemory(std::string content){
    memory[(int)counters.bitsWrite] = content;
    std::cout << "Writing to position:" << counters.bitsWrite << " Content:" << content << std::endl;
    counters.bitsWrite++;
}

void readFromMemory(){
    std::cout << "Reading from position: " << counters.bitsRead << " Content: " << memory[counters.bitsRead] <<std::endl;
    counters.bitsRead++;
}

void readFromMemory(int skipPositions){
    counters.bitsRead = counters.bitsRead+skipPositions;
    std::cout << "Reading from position: " << counters.bitsRead << " Content: " << memory[counters.bitsRead] <<std::endl;
    counters.bitsRead++;
}
