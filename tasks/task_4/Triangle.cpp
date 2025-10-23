#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Triangle::Triangle(double a, double b, double c) 
    : sideA(a), sideB(b), sideC(c) {
    if (!isValidTriangle()) {
        throw std::invalid_argument("Недопустимые стороны треугольника");
    }
}

bool Triangle::isValidTriangle() const {
    return (sideA > 0 && sideB > 0 && sideC > 0) &&
           (sideA + sideB > sideC) &&
           (sideA + sideC > sideB) &&
           (sideB + sideC > sideA);
}

double Triangle::area() const {
    // Формула Герона
    double p = perimeter() / 2.0;
    return std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double Triangle::perimeter() const {
    return sideA + sideB + sideC;
}

void Triangle::print() const {
    std::cout << "Тип: " << getType() << std::endl;
    std::cout << "Параметры: стороны " << sideA << ", " << sideB << ", " << sideC << std::endl;
    std::cout << "Площадь: " << area() << std::endl;
    std::cout << "Периметр: " << perimeter() << std::endl;
}

std::string Triangle::getType() const {
    return "Треугольник";
}