#include <iostream>
#include <vector>
#include <memory>
#include "RGB.h"
#include "RGBA.h"

int main() {
    std::cout << "=== Тестирование иерархии классов RGB/RGBA ===" << std::endl;
    
    // Создаем vector указателей на базовый класс
    std::vector<RGB*> colors;
    
    // Добавляем объекты разных типов в вектор
    colors.push_back(new RGB());                    // RGB по умолчанию
    colors.push_back(new RGB(255, 0, 0));          // Красный RGB
    colors.push_back(new RGB(0, 255, 0));          // Зеленый RGB
    colors.push_back(new RGBA());                   // RGBA по умолчанию
    colors.push_back(new RGBA(0, 0, 255, 128));    // Синий RGBA с прозрачностью
    colors.push_back(new RGBA(255, 255, 0, 200));  // Желтый RGBA
    
    // Тестируем полиморфное поведение
    std::cout << "\n1. Полиморфный вызов print():" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    for (size_t i = 0; i < colors.size(); ++i) {
        std::cout << "Цвет " << i + 1 << " (";
        
        // Определяем тип объекта
        if (dynamic_cast<RGBA*>(colors[i])) {
            std::cout << "RGBA): ";
            colors[i]->print(E_HEX); // Для RGBA используем HEX для демонстрации альфа-канала
        } else {
            std::cout << "RGB): ";
            colors[i]->print(E_RGB);
        }
        std::cout << std::endl;
    }
    
    // Демонстрация разных форматов вывода
    std::cout << "\n2. Разные форматы вывода для RGBA:" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    RGBA testColor(128, 64, 192, 100);
    
    std::cout << "RGB формат: ";
    testColor.print(E_RGB);
    std::cout << std::endl;
    
    std::cout << "HEX формат: ";
    testColor.print(E_HEX);
    std::cout << std::endl;
    
    std::cout << "INT формат: ";
    testColor.print(E_INT);
    std::cout << std::endl;
    
    // Тестирование сложения
    std::cout << "\n3. Тестирование сложения:" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    RGB* color1 = new RGB(100, 50, 25);
    RGBA* color2 = new RGBA(50, 100, 150, 200);
    
    std::cout << "Цвет 1 (RGB): ";
    color1->print(E_RGB);
    std::cout << std::endl;
    
    std::cout << "Цвет 2 (RGBA): ";
    color2->print(E_HEX);
    std::cout << std::endl;
    
    RGB* sumResult1 = color1->sum(*color2);
    std::cout << "Сумма RGB + RGBA: ";
    sumResult1->print(E_RGB);
    std::cout << std::endl;
    
    RGB* sumResult2 = color2->sum(*color1);
    std::cout << "Сумма RGBA + RGB: ";
    sumResult2->print(E_HEX);
    std::cout << std::endl;
    
    // Тестирование setColor
    std::cout << "\n4. Тестирование setColor:" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    RGBA mutableColor(255, 0, 0, 255);
    std::cout << "До setColor: ";
    mutableColor.print(E_HEX);
    std::cout << std::endl;
    
    mutableColor.setColor(0, 255, 0, 128); // Перегруженная версия
    std::cout << "После setColor(r,g,b,a): ";
    mutableColor.print(E_HEX);
    std::cout << std::endl;
    
    mutableColor.setColor(0, 0, 255); // Переопределенная версия
    std::cout << "После setColor(r,g,b): ";
    mutableColor.print(E_HEX);
    std::cout << std::endl;
    
    // Очистка памяти
    for (RGB* color : colors) {
        delete color;
    }
    delete color1;
    delete color2;
    delete sumResult1;
    delete sumResult2;
    
    std::cout << "\n=== Тестирование завершено ===" << std::endl;
    
    return 0;
}

//Перейдите в папку с файлами проекта и выполните:
//g++ -std=c++11 main.cpp RGB.cpp RGBA.cpp -o rgb_program

//Запуск программы:
//./rgb_program