#include "shape.h"
#include <cmath>

void Shape::set_values(int width, int height) {
    this->width=width;
    this->height = height;
}

bool Shape::operator==(Shape &secondShape){
    int returnResult = false;
    if (this->area() == secondShape.area() && this->perimeter() == secondShape.perimeter()){
        returnResult = true;
    }
    return returnResult;
}

/*
bool Shape::operator!=(const Shape &secondShape){
    return (!((this) == secondShape));
}
*/

bool Shape::operator<(Shape &secondShape) {
    int returnResult = false;
    if (this->area() < secondShape.area()) {
        returnResult = true;
    }
    else if (this->area() == secondShape.area() && this->perimeter() <secondShape.perimeter()) {
        returnResult = true;
    }
    return returnResult;
}

/*
bool Shape::operator>(const Shape &secondShape) {
    return (!((this) < secondShape));
}
*/
/*
void Circle::set_values(int radius) {
    this->width=radius;
}
*/

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
/*
void Square::set_values(int width) {
    this->width= width;
}
*/

int Square::area() {
    return this->width*this->width;
}

int Square::perimeter() {
    return 4*this->width;
}

std::ostream &Shape::operator<<(std::ostream &os) {
    return os << "area: " << this->area()  << "perimeter: " <<this->perimeter();
}