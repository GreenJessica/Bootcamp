#include <iostream>

class Shape {
    protected:
        int width, height;
     
    public:
        virtual void set_values(int width, int height);
        virtual int area() = 0;
        virtual int perimeter() = 0; 

        friend bool operator==(Shape &firstShape, Shape &secondShape);
        friend bool operator!=(Shape &firstShape, Shape &secondShape);
        friend bool operator<(Shape &firstShape, Shape &secondShape);
        friend bool operator>(Shape &firstShape, Shape &secondShape);
};

class Circle : public Shape{
    public:
        void set_values (int radius);

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
        void set_values (int width);

        int area();
        int perimeter(); 
};