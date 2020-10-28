#include "./library/shape.h"

int main() {
    Circle circle;
    circle.set_values(1,0);

    std::cout << "Circle area = " << circle.area() <<std::endl;
}
