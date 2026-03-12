// Находим максимальный элемент и его позицию
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 100, 4, 5};
    auto max_it = std::max_element(vec.begin(), vec.end());
    
    std::cout << "Max: " << *max_it 
              << " at index: " << std::distance(vec.begin(), max_it) << std::endl;
    return 0;
}