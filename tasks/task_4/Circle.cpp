#include "Circle.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

Circle::Circle(double r) : radius(r) {
    if (radius <= 0) {
        throw std::invalid_argument("Радиус должен быть положительным");
    }
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::print() const {
    std::cout << "Тип: " << getType() << std::endl;
    std::cout << "Параметры: радиус " << radius << std::endl;
    std::cout << "Площадь: " << area() << std::endl;
    std::cout << "Периметр (длина окружности): " << perimeter() << std::endl;
}

std::string Circle::getType() const {
    return "Окружность";
}