#include <iostream>
#include "RGBA.h"

int main() {
    std::cout << "=== Тестирование класса RGBA ===" << std::endl;
    
    // Тест конструктора по умолчанию
    std::cout << "1. Конструктор по умолчанию:" << std::endl;
    RGBA color1;
    std::cout << "Цвет 1: ";
    color1.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест конструктора с параметрами
    std::cout << "\n2. Конструктор с параметрами:" << std::endl;
    RGBA color2(255, 128, 64, 200);
    std::cout << "Цвет 2: ";
    color2.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест конструктора копирования
    std::cout << "\n3. Конструктор копирования:" << std::endl;
    RGBA color3(color2);
    std::cout << "Цвет 3 (копия цвета 2): ";
    color3.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест функции setColor с параметрами
    std::cout << "\n4. setColor с параметрами:" << std::endl;
    color1.setColor(100, 150, 200, 255);
    std::cout << "Цвет 1 после setColor: ";
    color1.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест функции setColor без параметров
    std::cout << "\n5. setColor без параметров:" << std::endl;
    RGBA color4;
    color4.setColor();
    std::cout << "Цвет 4 после setColor(): ";
    color4.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест функций получения значений
    std::cout << "\n6. Функции получения значений:" << std::endl;
    std::cout << "Цвет 2 - Red: " << static_cast<int>(color2.red()) 
              << ", Green: " << static_cast<int>(color2.green())
              << ", Blue: " << static_cast<int>(color2.blue())
              << ", Alpha: " << static_cast<int>(color2.alpha()) << std::endl;
    
    // Тест функции print с разными форматами
    std::cout << "\n7. Печать в разных форматах:" << std::endl;
    RGBA testColor(255, 127, 63, 191);
    
    std::cout << "RGBA формат: ";
    testColor.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "HEX формат: ";
    testColor.print(E_HEX);
    std::cout << std::endl;
    
    std::cout << "INT формат: ";
    testColor.print(E_INT);
    std::cout << std::endl;
    
    // Тест функции сложения
    std::cout << "\n8. Сложение цветов:" << std::endl;
    RGBA colorA(100, 50, 25, 255);
    RGBA colorB(50, 100, 150, 255);
    RGBA colorSum = colorA.sum(colorB);
    
    std::cout << "Цвет A: ";
    colorA.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "Цвет B: ";
    colorB.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "Сумма A + B: ";
    colorSum.print(E_RGBA);
    std::cout << std::endl;
    
    // Тест сложения с ограничением 255
    std::cout << "\n9. Сложение с ограничением 255:" << std::endl;
    RGBA colorC(200, 150, 100, 255);
    RGBA colorD(100, 150, 200, 255);
    RGBA colorSum2 = colorC.sum(colorD);
    
    std::cout << "Цвет C: ";
    colorC.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "Цвет D: ";
    colorD.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "Сумма C + D: ";
    colorSum2.print(E_RGBA);
    std::cout << std::endl;
    
    std::cout << "\n=== Тестирование завершено ===" << std::endl;
    
    return 0;
}

//g++ -std=c++11 main.cpp RGBA.cpp -o rgba_test
//./rgba_test