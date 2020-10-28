#include "shape.h"

int main() {
    Circle circle;
    Triangle triangle;

    circle.set_values(1,0);
    triangle.set_values(4,3); 

    std::cout << "Circle area = " << circle.area() <<std::endl;
    std::cout << "Triangle perimeter = " << triangle.perimeter() <<std::endl;
}