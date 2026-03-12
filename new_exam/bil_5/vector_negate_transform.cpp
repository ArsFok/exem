// Поменять знаки у элементов вектора с помощью std::transform и std::negatex
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> vec = {1, -5, 3, -2, 7, -8, 4};
    
    std::cout << "Исходный вектор: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::transform(vec.begin(), vec.end(), vec.begin(), std::negate<int>());
    
    std::cout << "После изменения знаков: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}