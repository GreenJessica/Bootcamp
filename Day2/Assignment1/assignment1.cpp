#include <iostream>
#include <time.h>

int main() {
    int *dimensionA;
    int *dimensionB;
    int *dimensionC;

    int numberOfArraysDimensionA;
    int numberOfArraysDimensionB;
    int numberOfArraysDimensionC;

    int randomMax;
    int randomizedNumber;
    srand(time(0));

    // Max size
    std::cout << "Please enter a positive number to use as the max value" <<std::endl;
    std::cin >> randomMax;

    // Dimension A
    std::cout << "Please enter a positive number to use as array dimension A" <<std::endl;
    std::cin >> numberOfArraysDimensionA;
    dimensionA = new int[numberOfArraysDimensionA];

    // Dimension B
    std::cout << "Please enter a positive number to use as array dimension B" <<std::endl;
    std::cin >> numberOfArraysDimensionB;
    dimensionB = new int[numberOfArraysDimensionB];


    // Dimension C
    std::cout << "Please enter a positive number to use as array dimension C" <<std::endl;
    std::cin >> numberOfArraysDimensionC;
    dimensionC = new int[numberOfArraysDimensionC];

    for (int i=0;i<numberOfArraysDimensionA;i++) {
        *(dimensionA +i) = *(dimensionB + i);
        std::cout <<std::endl;

        for (int j=0;j<numberOfArraysDimensionB;j++) {
            *(dimensionB +i) = *(dimensionC + i);
            std::cout <<std::endl;

            for (int k=0;k<numberOfArraysDimensionC;k++){
                *(dimensionC +i) = rand() % randomMax;
                // std::cout << "value " << *(dimensionC + i) << " address: " << (dimensionC + i) << std::endl;
                std::cout << "[" << i << "][" << j  << "][" << k <<"]: " << *(dimensionC +i) << "\t";
            }
        }
    std::cout <<std::endl;
    }

    delete dimensionA;
    delete dimensionB;
    delete dimensionC;
}