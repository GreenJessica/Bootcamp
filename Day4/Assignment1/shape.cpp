#include "shape.h"
#include <cmath>

int main() {
    Circle circle;
    Triangle triangle;
    Rectangle rectangle;
    Rectangle rectangle2;
    Square square;

    circle.set_values(1);
    triangle.set_values(4,3); 
    rectangle.set_values(3,2);
    rectangle2.set_values(3,2);
    square.set_values(2);

    if (rectangle2==rectangle){
        std::cout << "Works." << std::endl;
    }
    else {
        std::cout << "Something's not working." << std::endl;
    }

    if (triangle!=rectangle){
        std::cout << "Works." << std::endl;
    }
    else {
        std::cout << "Something's not working." << std::endl;
    }

    if (circle<rectangle) {
        std::cout << "Works." << std::endl;
    }
    else {
        std::cout << "Something's not working." << std::endl;
    }

    if (circle>rectangle) {
        std::cout << "Something's not working." << std::endl;
    }
    else {
        std::cout << "Works." << std::endl;
    }
}



void Shape::set_values(int width, int height) {
    this->width=width;
    this->height = height;
}

bool operator==(Shape& firstShape, Shape& secondShape){
    bool area = firstShape.area() == secondShape.area();
    bool perimeter = false;
    if (area) {
        perimeter = firstShape.perimeter() == secondShape.perimeter();
    }
    return perimeter;
}

bool operator!=(Shape& firstShape, Shape& secondShape){
    return (!((firstShape) == secondShape));
}

bool operator<(Shape &firstShape, Shape &secondShape) {
    bool area = firstShape.area() < secondShape.area();
    bool perimeter = false;
    if (area) {
        perimeter = firstShape.perimeter() < secondShape.perimeter();
    }
    return perimeter;
}

bool operator>(Shape &firstShape, Shape &secondShape) {
    return (!((firstShape) < secondShape));
}


void Circle::set_values(int radius) {
    this->width=radius;
}

int Circle::area() {
    return 3*this->width*this->width;
}

int Circle::perimeter() {
    return 2*3*this->width;
}

int Triangle::area() {
    return this->width*this->height/2;
}

int Triangle::perimeter() {
    // Assuming a right angled triangle, find the hypotenuse
    int hypotenuse;
    hypotenuse = sqrt(this->width*this->width + this->height*this->height);

    return this->width + this->height + hypotenuse;
}

int Rectangle::area() {
    return this->width*this->height;
}

int Rectangle::perimeter() {
    return 2*this->width + 2*this->height;
}

void Square::set_values(int width) {
    this->width= width;
}

int Square::area() {
    return this->width*this->width;
}

int Square::perimeter() {
    return 4*this->width;
}