#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c);
    
    // Реализация виртуальных функций
    double area() const override;
    double perimeter() const override;
    void print() const override;
    std::string getType() const override;
    
    // Геттеры
    double getSideA() const { return sideA; }
    double getSideB() const { return sideB; }
    double getSideC() const { return sideC; }
    
private:
    bool isValidTriangle() const;
};

#endif // TRIANGLE_H