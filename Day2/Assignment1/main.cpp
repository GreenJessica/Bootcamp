#include <iostream>
#include <time.h>

int sizeOfDimension(char dim);
int maxValue();

int main() {
    int *dimA;
    int *dimB;
    int *dimC;
    int sizeOfA, sizeOfB, sizeOfC, randomMax;

    srand(time(0));

    randomMax=maxValue();
    dimA = new int[sizeOfA=sizeOfDimension('A')];
    dimB = new int[sizeOfB=sizeOfDimension('B')];
    dimC = new int[sizeOfC=sizeOfDimension('C')];

    for (int i=0;i<sizeOfA;i++) {
        *(dimA +i) = *(dimB + i);
        for (int j=0;j<sizeOfB;j++) {
            *(dimB +i) = *(dimC + i);
            for (int k=0;k<sizeOfC;k++){
                *(dimC +i) = rand()%randomMax;
                std::cout << "[" << i << "][" << j  << "][" << k <<"]: " << *(dimC +i) << "\t";
            }
            std::cout <<std::endl;
        }
    std::cout <<std::endl;
    }

    delete[] dimC;
    delete[] dimB;
    delete[] dimA;
}