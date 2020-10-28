#include <iostream>

int min = 0;
int max = 128;
int guessNo = 64;
char userAnswer;
int noOfQuestions = 0;

void guess();
void ask();

int main() {
    std::cout << "Think of a number between 1 & 128." <<std::endl;
    std::cout << "Answer all questions with \"y\" for yes and \"n\" for no." <<std::endl;

    guess();
    std::cout << "The number is: " << guessNo <<std::endl;   

}

void ask(){
    noOfQuestions ++;
    std::cout << noOfQuestions << ". Is the number smaller than or equal to " << guessNo <<"?" <<std::endl;  
    std::cin >> userAnswer;
}

void guess() {
    if (max-min == 1) {
        if (userAnswer == 'y'){
            guessNo = min;
        }
        else if (userAnswer == 'n') {
            guessNo = max;
        }
        return;
    }

    else {
        ask();

        if (userAnswer == 'y') {
            max= guessNo; 
            guessNo = guessNo - (max-min)/2;
        }
        else if (userAnswer == 'n') {
            min = guessNo;
            guessNo = guessNo + ((max-min)/2);
        }
        guess();
    }
}