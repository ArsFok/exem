#include "polynom.h"
#include <iostream>

int main() {
    Polynom p1; // пустой
    std::cout << "Пустой: " << p1 << std::endl;
    
    Polynom p2{1.5, 2.0, 3.0}; // из списка
    std::cout << "p2: " << p2 << ", степень: " << p2.degree() << std::endl;
    
    p2[1] = 5.5; // изменение
    std::cout << "p2 после p2[1]=5.5: " << p2 << std::endl;
    
    Polynom p3{1.5, 2.0, 3.0}; // для сравнения
    std::cout << "p2 == p3: " << (p2 == p3 ? "да" : "нет") << std::endl;
    std::cout << "p2 != p3: " << (p2 != p3 ? "да" : "нет") << std::endl;
    
    Polynom p4{0, 0, 1, 2}; // с ведущими нулями
    std::cout << "p4: " << p4 << std::endl;
    
    return 0;
}