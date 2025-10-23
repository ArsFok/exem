#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h);
    
    // Реализация виртуальных функций
    double area() const override;
    double perimeter() const override;
    void print() const override;
    std::string getType() const override;
    
    // Геттеры
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

#endif // RECTANGLE_H