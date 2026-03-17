#include <iostream>
#include "polynom.h"

int main() {
    try {
        std::cout << "=== Демонстрация работы класса Polynom ===" << std::endl;
        
        // Тест 1: Конструкторы
        std::cout << "\n1. Конструкторы:" << std::endl;
        Polynom p1; // По умолчанию
        Polynom p2({1, 2, 3}); // 3x^2 + 2x + 1
        Polynom p3 = {0, 0, 4, 5}; // 5x^3 + 4x^2
        
        std::cout << "p1 (по умолчанию): " << p1 << std::endl;
        std::cout << "p2 ({1, 2, 3}): " << p2 << std::endl;
        std::cout << "p3 ({0, 0, 4, 5}): " << p3 << std::endl;
        
        // Тест 2: Оператор []
        std::cout << "\n2. Оператор []:" << std::endl;
        p1[0] = 7; // Свободный член
        p1[2] = 3; // Коэффициент при x^2
        p1[1] = 2; // Коэффициент при x
        
        std::cout << "После p1[0]=7, p1[2]=3, p1[1]=2: " << p1 << std::endl;
        std::cout << "p1[0] = " << p1[0] << std::endl;
        std::cout << "p1[1] = " << p1[1] << std::endl;
        std::cout << "p1[2] = " << p1[2] << std::endl;
        
        // Тест 3: Степень многочлена
        std::cout << "\n3. Степень многочлена:" << std::endl;
        std::cout << "Степень p1: " << p1.degree() << std::endl;
        std::cout << "Степень p2: " << p2.degree() << std::endl;
        std::cout << "Степень p3: " << p3.degree() << std::endl;
        
        // Тест 4: Операторы сравнения
        std::cout << "\n4. Операторы сравнения:" << std::endl;
        Polynom p4({7, 2, 3});
        std::cout << "p1: " << p1 << std::endl;
        std::cout << "p4: " << p4 << std::endl;
        std::cout << "p1 == p4: " << (p1 == p4 ? "true" : "false") << std::endl;
        std::cout << "p1 != p2: " << (p1 != p2 ? "true" : "false") << std::endl;
        
        // Тест 5: Обработка ошибок
        std::cout << "\n5. Обработка ошибок:" << std::endl;
        try {
            std::cout << "Попытка доступа к p1[10]: ";
            double val = p1[10]; // Должно вызвать исключение
            std::cout << val << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Поймано исключение: " << e.what() << std::endl;
        }
        
        // Тест 6: Автоматическое удаление ведущих нулей
        std::cout << "\n6. Автоматическое удаление ведущих нулей:" << std::endl;
        Polynom p5({1, 2, 0, 0, 0}); // Должно стать 2x + 1
        std::cout << "p5({1, 2, 0, 0, 0}): " << p5 << std::endl;
        std::cout << "Степень p5: " << p5.degree() << std::endl;
        
        // Тест 7: Разные форматы многочленов
        std::cout << "\n7. Разные форматы многочленов:" << std::endl;
        Polynom p6({-1, -2, -3}); // -3x^2 - 2x - 1
        Polynom p7({0, 1});       // x
        Polynom p8({5});          // 5
        Polynom p9({0, 0, -1});   // -x^2
        
        std::cout << "p6 ({-1, -2, -3}): " << p6 << std::endl;
        std::cout << "p7 ({0, 1}): " << p7 << std::endl;
        std::cout << "p8 ({5}): " << p8 << std::endl;
        std::cout << "p9 ({0, 0, -1}): " << p9 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    std::cout << "\n=== Демонстрация завершена ===" << std::endl;
    return 0;
}