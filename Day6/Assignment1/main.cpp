#include <iostream>

struct field {
    unsigned bitsLights:3; // lights
    unsigned bitsDoors:4; // doors
    unsigned bitsWindows:4; // windows
    unsigned bitsSeatbelts:5; // seatbelts
};

union uintToBits
{
   uint16_t input;
   field bits;
};

void checkLights(uintToBits word);
void checkDoors(uintToBits word);
void checkWindows(uintToBits word);
void checkSeatbelts(uintToBits word);

int main() {
    uintToBits word;
    word.input = 0b1011101001011011;

    checkLights(word);
    checkDoors(word);
    checkWindows(word);
    checkSeatbelts(word);

    return 0;
}

void checkLights(uintToBits word) {
    // Assuming sorting from msb to lsb = driver lights, passenger lights, rear seat lights.
    field temp;

    if (word.bits.bitsLights == 7) {
        std::cout << " All lights are on \n";
    }
    else if (word.bits.bitsLights == 0) {
        std::cout << " No lights are on \n";
    }
    else {
        temp.bitsLights = word.bits.bitsLights & 0b100;
        if (temp.bitsLights == 4) {
        std::cout << " Driver lights are on \n";
        }
        temp.bitsLights = word.bits.bitsLights & 0b10;
        if (temp.bitsLights == 2) {
        std::cout << " Passenger lights are on \n";
        }
        temp.bitsLights = word.bits.bitsLights & 0b1;
        if (temp.bitsLights == 1) {
        std::cout << " Rear seat lights are on \n";
        }
    }
    std::cout << std::endl;
}

void checkDoors(uintToBits word) {
    // Assuming sorting from msb to lsb = driver door, passenger door, rear left door, rear right door.
    field temp;

    if (word.bits.bitsDoors == 15) {
        std::cout << " All doors are open \n";
    }
    else if (word.bits.bitsDoors == 0) {
        std::cout << " No doors are open \n";
    }
    else {
        temp.bitsDoors = word.bits.bitsDoors & 0b1000;
        if (temp.bitsDoors == 8) {
        std::cout << " Driver door is open \n";
        }
        temp.bitsDoors = word.bits.bitsDoors & 0b100;
        if (temp.bitsDoors == 4) {
        std::cout << " Passenger door is open \n";
        }
        temp.bitsDoors = word.bits.bitsDoors & 0b10;
        if (temp.bitsDoors == 2) {
        std::cout << " Rear left door is open \n";
        }
        temp.bitsDoors = word.bits.bitsDoors & 0b1;
        if (temp.bitsDoors == 1) {
        std::cout << " Rear right door is open \n";
        }
    }
    std::cout << std::endl;
}

void checkWindows(uintToBits word) {
    // Assuming sorting from msb to lsb = driver window, passenger window, rear left window, rear right window.
    field temp;

    if (word.bits.bitsWindows == 15) {
        std::cout << " All windows are open \n";
    }
    else if (word.bits.bitsWindows == 0) {
        std::cout << " No windows are open \n";
    }
    else {
        temp.bitsWindows = word.bits.bitsWindows & 0b1000;
        if (temp.bitsWindows == 8) {
        std::cout << " Driver window is open \n";
        }
        temp.bitsWindows = word.bits.bitsWindows & 0b100;
        if (temp.bitsWindows == 4) {
        std::cout << " Passenger window is open \n";
        }
        temp.bitsWindows = word.bits.bitsWindows & 0b10;
        if (temp.bitsWindows == 2) {
        std::cout << " Rear left window is open \n";
        }
        temp.bitsWindows = word.bits.bitsWindows & 0b1;
        if (temp.bitsWindows == 1) {
        std::cout << " Rear right window is open \n";
        }
    }
    std::cout << std::endl;
}

void checkSeatbelts(uintToBits word) {
    // Assuming sorting from msb to lsb = driver, passenger, rear left, rear middle & rear right seatbelt.
    field temp;

    if (word.bits.bitsSeatbelts == 31) {
        std::cout << " All seatbelts are loose \n";
    }
    else if (word.bits.bitsWindows == 0) {
        std::cout << " No seatbelts are loose \n";
    }
    else {
        temp.bitsSeatbelts = word.bits.bitsSeatbelts & 0b10000;
        if (temp.bitsSeatbelts == 15) {
        std::cout << " Driver seatbelt is loose \n";
        }
        temp.bitsSeatbelts = word.bits.bitsSeatbelts & 0b1000;
        if (temp.bitsSeatbelts == 8) {
        std::cout << " Passenger seatbelt is loose \n";
        }
        temp.bitsSeatbelts = word.bits.bitsSeatbelts & 0b100;
        if (temp.bitsSeatbelts == 4) {
        std::cout << " Rear left seatbelt is loose \n";
        }
        temp.bitsSeatbelts = word.bits.bitsSeatbelts & 0b10;
        if (temp.bitsSeatbelts == 2) {
        std::cout << " Rear middle seatbelt is loose \n";
        }
        temp.bitsSeatbelts = word.bits.bitsSeatbelts & 0b1;
        if (temp.bitsSeatbelts == 1) {
        std::cout << " Rear right seatbelt is loose \n";
        }
    }
    std::cout << std::endl;
}