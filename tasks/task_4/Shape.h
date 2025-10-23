#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;
    
    // Чисто виртуальные функции
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    
    // Виртуальная функция для получения типа фигуры
    virtual std::string getType() const = 0;
};

#endif // SHAPE_H