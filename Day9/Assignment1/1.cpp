#include <iostream>

const size_t SIZE = 10;

int function() {
    //int test  = std::rand();
    //std::cout << " testvalue " << test <<std::endl;
    return std::rand();
    //return test;
}
int *fillArray() {
    int *a = new int[SIZE];
    size_t i = SIZE;// YOU ARE NOT SUPPOSE TO CHANGE THIS  
    for (; i >-0; --i) {
        a[i-1] = function();   
    }   
    return a; 
}
void printArray(int a[SIZE]) {        
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << a[i] << std::endl;
    } 
    delete a;   
}
void printBool (bool _b) {
    if (_b == true) {
        std::cout << "VALUE is TRUE" << std::endl;        
    } else if (_b == false)    {
        std::cout << "VALUE is FALSE" << std::endl;        
    }    
}
// YOU ARE NOT ALLOWED TO CHANGE THE RETURN TYPE
void resizeForMe(char *&a, size_t _newSize) {
    delete a;
    a = new char[_newSize];
}

int main() {
    printArray(fillArray());
    printBool(false);
    char *a = new char[SIZE];  
    for (size_t i = 0; i<SIZE; i++) i%2 ? *(a+i) = 'A' : *(a+i) = 'D'; 
    std::cout << "Content is: " << a << std::endl;
    resizeForMe(a,100);
    for (size_t i = 0; i<100; i++) i%2 ? a[i] = 'B' : a[i] = 'C';
    std::cout << "Content is: " << a << std::endl;
    delete a;
    return 0;
}
