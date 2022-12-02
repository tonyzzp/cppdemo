#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

class Shape
{
public:
    virtual float area() const = 0;
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }

    float area() const
    {
        return width * height;
    }
};

class Circle : public Shape
{
private:
    float r;

public:
    Circle(float r)
    {
        this->r = r;
    }

    float area() const
    {
        return M_PI * r * r;
    }
};

class Square : public Shape
{
private:
    int size;

public:
    Square(int size)
    {
        this->size = size;
    }

    float area() const
    {
        return size * size;
    }
};

int main()
{
    Rectangle rect = Rectangle(1, 3);
    Circle circle(10.0);
    Square square(4);
    std::cout << "rect.area()=" << rect.area() << std::endl;
    std::cout << "circle.area()=" << circle.area() << std::endl;
    std::cout << "square.area()=" << square.area() << std::endl;

    return 0;
}