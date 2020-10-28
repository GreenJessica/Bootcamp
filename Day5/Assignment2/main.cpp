#include <iostream>
#include <time.h>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int currentNumber;
    std::vector<std::vector<int>> occurance;

    // Set occurance[] to 33 rows
    occurance.resize(34);
    for (int i=0; i<34; i++) {
        occurance[i].resize(2); // Set 2 columns to each row
        occurance[i][0] = i; // Put 0-33 in number, [i][0]...
        occurance[i][1] = 0; // ...and 0 in all occurances [i][1]
    }

    // Randomize "0-33"s and count them
    srand(time(0));
    for (int i=0; i<10000; i++) {
        currentNumber = rand()%34;
        occurance[currentNumber][1]==occurance[currentNumber][1]++;
    }

    //Sort it in assending order
    std::sort(occurance.begin(),occurance.end(),
        [] (std::vector<int> &a, std::vector<int> &b)
        {
            return a[1] < b[1];
        });

    // Show them
    for (int i=0; i<34; i++) {
        std::cout <<"Number: " << occurance[i][0] <<" occurs " <<occurance[i][1] <<" times." << std::endl;
    }
}