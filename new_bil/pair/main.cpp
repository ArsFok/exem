#include <iostream>
#include <string>
#include "pair.h"

int main() {
    // Конструктор по умолчанию
    Pair<int, std::string> p1;
    p1.setFirst(1);
    p1.setSecond("hello");
    
    // Конструктор с параметрами
    Pair<int, std::string> p2(2, "world");
    
    // Конструктор копирования
    Pair<int, std::string> p3(p1);
    
    // Оператор присваивания
    Pair<int, std::string> p4;
    p4 = p2;
    
    // Использование геттеров и оператора вывода
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;
    
    // Сравнение пар
    std::cout << "p1 == p3: " << (p1 == p3 ? "true" : "false") << std::endl;
    std::cout << "p1 != p2: " << (p1 != p2 ? "true" : "false") << std::endl;
    
    Pair<int, int> p5(1, 2);
    Pair<int, int> p6(2, 1);
    
    std::cout << "p5 < p6: " << (p5 < p6 ? "true" : "false") << std::endl;
    std::cout << "p5 > p6: " << (p5 > p6 ? "true" : "false") << std::endl;
    
    // Использование сеттеров
    p5.setFirst(10);
    p5.setSecond(20);
    std::cout << "p5 после изменений: " << p5 << std::endl;
    
    return 0;
}