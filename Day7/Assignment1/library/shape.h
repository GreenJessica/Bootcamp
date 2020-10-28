#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape {
    protected:
        int width, height;
     
    public:
        virtual void set_values(int width, int height);
        virtual int area() = 0;
        virtual int perimeter() = 0; 
        bool operator==(Shape &secondShape);
        //bool operator!=(Shape &secondShape);
        bool operator<(Shape &secondShape);
        //bool operator>(Shape &secondShape);
        std::ostream &operator<<(std::ostream &os); 
};

class Circle : public Shape{
    public:
        //void set_values (int radius);

        int area();
        int perimeter(); 
};

class Triangle : public Shape{
    public:
        int area();
        int perimeter(); 
};

class Rectangle : public Shape{
    public:
        int area();
        int perimeter(); 
};

class Square : public Shape{
    public:
        //void set_values (int width);

        int area();
        int perimeter(); 
};

template <typename T>
void compare(T firstItem, T secondItem){
    if (firstItem == secondItem){
        std::cout << firstItem << " is equal to " << secondItem << std::endl;
    }
    else if (firstItem < secondItem) {
        std::cout << firstItem << " is smaller than " << secondItem << std::endl;
    }
    else {
        std::cout << firstItem << " is larger than " << secondItem << std::endl;
    }
}

#endif