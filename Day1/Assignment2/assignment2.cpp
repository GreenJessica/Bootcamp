#include <iostream>
#include <string>

int main() {
    int key;
    std::string CipherTxt;

    do {
        std::cout << "Please enter a cipher key between 0-26" <<std::endl;
        std::cin >> key;
    }
    while (key < 0 || key > 26);

    std::cout << "Please enter the cipher text in Capital letters" <<std::endl;
    std::cin >> CipherTxt;

    for (int i =0; i< CipherTxt.length();i++) {
        if (int(CipherTxt[i])>=65 && int(CipherTxt[i])<=90){
            CipherTxt[i]= CipherTxt[i] + key;
            if (int(CipherTxt[i])>90){
                int toMuch = int(CipherTxt[i] - 90);
                CipherTxt[i] = 'A' + (toMuch -1);
            }

        }
    }
    std::cout << "With the key: " <<key << " The deciphered word becomes: " << CipherTxt << std::endl;
}