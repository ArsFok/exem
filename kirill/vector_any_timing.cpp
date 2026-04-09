// Контейнер std::vector<std::any> с элементами разных типов
// и измерением времени выполнения
#include <iostream>
#include <vector>
#include <any>
#include <chrono>
#include <string>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    // Создаем вектор из std::any элементов
    std::vector<std::any> anyVector;
    
    // Добавляем элементы разных типов
    anyVector.push_back(42);
    anyVector.push_back(3.14);
    anyVector.push_back(std::string("Hello"));
    anyVector.push_back(true);
    anyVector.push_back(100);
    
    // Выводим элементы с определением типа
    for (size_t i = 0; i < anyVector.size(); ++i) {
        std::cout << "Элемент " << i << ": ";
        
        if (anyVector[i].type() == typeid(int)) {
            std::cout << "int = " << std::any_cast<int>(anyVector[i]);
        }
        else if (anyVector[i].type() == typeid(double)) {
            std::cout << "double = " << std::any_cast<double>(anyVector[i]);
        }
        else if (anyVector[i].type() == typeid(std::string)) {
            std::cout << "string = " << std::any_cast<std::string>(anyVector[i]);
        }
        else if (anyVector[i].type() == typeid(bool)) {
            std::cout << "bool = " << std::any_cast<bool>(anyVector[i]);
        }
        std::cout << std::endl;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "\nВремя выполнения: " << duration.count() << " мкс" << std::endl;
    
    return 0;
}