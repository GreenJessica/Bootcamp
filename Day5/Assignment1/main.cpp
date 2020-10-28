#include "shape.h"

int main() {
    Circle circle;
    Triangle triangle;
    Rectangle rectangle;
    Rectangle rectangle2;
    Square square;

    circle.set_values(1,0);
    triangle.set_values(4,3); 
    rectangle.set_values(3,2);
    rectangle2.set_values(3,2);
    square.set_values(2,2);

    compare<Shape>(circle, triangle);
    compare<Shape>(rectangle, rectangle2);
    compare<Shape>(circle, square);
}