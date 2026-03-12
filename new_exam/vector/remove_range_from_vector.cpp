// Удаляем диапазон элементов из вектора
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    int start = 2, end = 4; // удалить элементы с индексами 2,3,4
    
    std::cout << "Original: ";
    for (int x : vec) std::cout << x << " ";
    
    vec.erase(vec.begin() + start, vec.begin() + end + 1);
    
    std::cout << "\nAfter erase: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}