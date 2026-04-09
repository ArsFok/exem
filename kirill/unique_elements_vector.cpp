// Составить вектор из периодически повторяющихся элементов определенного типа,
// а затем сделать так, чтобы в векторе остались только уникальные элементы
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    // Создаем вектор с периодически повторяющимися элементами
    std::vector<int> vec = {1, 2, 3, 1, 2, 4, 3, 1, 5, 2, 4, 1};
    
    std::cout << "Исходный вектор: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Оставляем только уникальные элементы
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    
    std::cout << "Уникальные элементы: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}