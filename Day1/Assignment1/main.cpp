#include <iostream>
#include <time.h>

int main() {
    int positiveNumberArray[8][9][11];
    int randomMax;
    int randomizedNumber;
    srand(time(0));

    std::cout << "Please enter a positive number" <<std::endl;
    do {std::cin >> randomMax;}while(randomMax<1);

    for (int i=0;i<8;i++) {
        for  (int j=0;j<9;j++) {
            for (int k=0;k<11;k++) {
                positiveNumberArray[i][j][k] = rand()%randomMax;
                std::cout << "[" << i << "][" << j  << "][" << k <<"]: " <<positiveNumberArray[i][j][k] << "\t";
            }
            std::cout <<std::endl;
        }
        std::cout <<std::endl;
    } 
}