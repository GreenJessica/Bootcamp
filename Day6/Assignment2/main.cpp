#include <iostream>

struct field {
    unsigned bitsLeftDist:3;
    unsigned bitsRightDist:3;
    unsigned bitsRearDist:3;
    unsigned bitsFrontDist:3;
    unsigned bitsSpeed:4;
};

field output;

void encodeSpeed(uint16_t speed, uint16_t  frontDist, uint16_t  rearDist, uint16_t  rightDist, uint16_t  leftDist);
void detectCrash(field output);

int main() {
    uint16_t inputSpeed = 500, inputFrontDist = 150, inputRearDist = 1000, inputRightDist = 240, inputLeftDist = 78;
    
    encodeSpeed(inputSpeed, inputFrontDist, inputRearDist, inputLeftDist, inputRightDist);
    std::cout << "Encoded speed " << output.bitsSpeed << std::endl;
    std::cout << "Encoded front distance " << output.bitsFrontDist << std::endl;
    std::cout << "Encoded rear distance " << output.bitsRearDist << std::endl;
    std::cout << "Encoded left distance " << output.bitsLeftDist << std::endl;
    std::cout << "Encoded right distance " << output.bitsRightDist << std::endl;
    detectCrash(output);

    return 0;
}

void encodeSpeed(uint16_t speed, uint16_t  frontDist, uint16_t  rearDist, uint16_t  rightDist, uint16_t  leftDist) { 
    output.bitsSpeed = speed/20;
    output.bitsFrontDist = frontDist/150;
    output.bitsRearDist = rearDist/150;
    output.bitsLeftDist = leftDist/150;
    output.bitsRightDist = rightDist/150;
    
    return;
}

void detectCrash(field output) {
    if (output.bitsFrontDist == 0) {
        std::cout << "The vehicle has collided with an object in front, at a velocity of roughly " << output.bitsSpeed*20 << std::endl;
    }
    if (output.bitsRearDist == 0) {
        std::cout << "The vehicle has collided with an object in rear, at a velocity of roughly " << output.bitsSpeed*20 << std::endl;
    } 
    if (output.bitsLeftDist == 0) {
        std::cout << "The vehicle has collided with an object on the left side, at a velocity of roughly " << output.bitsSpeed*20 << std::endl;
    }
    if (output.bitsRightDist == 0) {
        std::cout << "The vehicle has collided with an object on the right side, at a velocity of roughly " << output.bitsSpeed*20 << std::endl;
    }

}
