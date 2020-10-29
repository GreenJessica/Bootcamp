#include <iostream>

int sizeOfDimension(char dim) {
    int returnSize;
    std::cout << "Please enter a positive number to use as array dimension " << dim <<std::endl;
    std::cin >> returnSize;
    return returnSize;
}

int maxValue() {
    int randomMax;
    std::cout << "Please enter a positive number to use as the max value" <<std::endl;
    std::cin >> randomMax;
    return randomMax;
}