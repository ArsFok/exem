#include <iostream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

// Функция для печати информации о всех фигурах в векторе
void printShapesInfo(const std::vector<Shape*>& shapes) {
    std::cout << "=== ИНФОРМАЦИЯ О ФИГУРАХ ===" << std::endl;
    std::cout << "Количество фигур: " << shapes.size() << std::endl;
    std::cout << "============================" << std::endl;
    
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "ФИГУРА " << i + 1 << ":" << std::endl;
        shapes[i]->print();
        std::cout << "---------------------------" << std::endl;
    }
}

// Альтернативная версия с умными указателями
void printShapesInfoSmart(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << "=== ИНФОРМАЦИЯ О ФИГУРАХ (умные указатели) ===" << std::endl;
    std::cout << "Количество фигур: " << shapes.size() << std::endl;
    std::cout << "=============================================" << std::endl;
    
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "ФИГУРА " << i + 1 << ":" << std::endl;
        shapes[i]->print();
        std::cout << "---------------------------------------------" << std::endl;
    }
}

int main() {
    // Способ 1: С обычными указателями
    std::cout << "СПОСОБ 1: Обычные указатели" << std::endl;
    std::vector<Shape*> shapes;
    
    try {
        // Создаем фигуры и добавляем в вектор
        shapes.push_back(new Triangle(3, 4, 5));      // Прямоугольный треугольник
        shapes.push_back(new Rectangle(5, 10));       // Прямоугольник
        shapes.push_back(new Circle(7));              // Окружность
        shapes.push_back(new Triangle(5, 5, 5));      // Равносторонний треугольник
        shapes.push_back(new Rectangle(2.5, 4.5));    // Прямоугольник с дробными сторонами
        
        // Печатаем информацию о всех фигурах
        printShapesInfo(shapes);
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    // Очищаем память
    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();
    
    std::cout << std::endl;
    
    // Способ 2: С умными указателями (рекомендуется)
    std::cout << "СПОСОБ 2: Умные указатели" << std::endl;
    std::vector<std::unique_ptr<Shape>> smartShapes;
    
    try {
        // Создаем фигуры с помощью умных указателей
        smartShapes.push_back(std::make_unique<Triangle>(6, 8, 10));
        smartShapes.push_back(std::make_unique<Rectangle>(3, 7));
        smartShapes.push_back(std::make_unique<Circle>(5));
        smartShapes.push_back(std::make_unique<Triangle>(7, 7, 7));
        
        // Печатаем информацию
        printShapesInfoSmart(smartShapes);
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    // Дополнительная демонстрация полиморфизма
    std::cout << std::endl;
    std::cout << "ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА:" << std::endl;
    std::cout << "==========================" << std::endl;
    
    std::vector<std::unique_ptr<Shape>> demoShapes;
    demoShapes.push_back(std::make_unique<Triangle>(3, 4, 5));
    demoShapes.push_back(std::make_unique<Rectangle>(4, 4)); // Квадрат
    demoShapes.push_back(std::make_unique<Circle>(2));
    
    double totalArea = 0;
    double totalPerimeter = 0;
    
    for (const auto& shape : demoShapes) {
        totalArea += shape->area();
        totalPerimeter += shape->perimeter();
    }
    
    std::cout << "Суммарная площадь всех фигур: " << totalArea << std::endl;
    std::cout << "Суммарный периметр всех фигур: " << totalPerimeter << std::endl;
    
    return 0;
}

//Компиляция
//g++ -std=c++11 -o shapes main.cpp Triangle.cpp Rectangle.cpp Circle.cpp

//Запуск
//./shapes