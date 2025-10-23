#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    
    // Реализация виртуальных функций
    double area() const override;
    double perimeter() const override;
    void print() const override;
    std::string getType() const override;
    
    // Геттер
    double getRadius() const { return radius; }
};

#endif // CIRCLE_H