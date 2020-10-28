#include <iostream>
#include <time.h>

int main() {
    int positiveNumberArray[8][9][11];
    int randomMax;
    int randomizedNumber;
    srand(time(0));

    std::cout << "Please enter a positive number" <<std::endl;
    std::cin >> randomMax;

    for (int i=0;i<8;i++) {
        std::cout <<std::endl;
        for  (int j=0;j<9;j++) {
            std::cout <<std::endl;

            for (int k=0;k<11;k++) {
                do {
                    positiveNumberArray[i][j][k] = rand();
                }
                while (positiveNumberArray[i][j][k] >= randomMax);

                std::cout << "[" << i << "][" << j  << "][" << k <<"]: " <<positiveNumberArray[i][j][k] << "\t";
            }
        }
    } 
    std::cout <<std::endl;
}