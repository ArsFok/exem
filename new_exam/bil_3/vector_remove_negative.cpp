// Реализуйте программу, которая использует алгоритм std::remove_if 
// для удаления всех отрицательных элементов из вектора, идущих после минимального. 
// Выведите вектор на экран с помощью std::for_each. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> vec = {5, 3, -8, 2, -1, -6, 4, -3, 7};
    
    std::cout << "Исходный вектор: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Находим минимальный элемент
    auto min_it = std::min_element(vec.begin(), vec.end());
    std::cout << "Минимальный элемент: " << *min_it << std::endl;
    
    // Удаляем отрицательные элементы после минимального
    auto new_end = std::remove_if(min_it + 1, vec.end(), 
                                   [](int x) { return x < 0; });
    vec.erase(new_end, vec.end());
    
    std::cout << "Результат: ";
    std::for_each(vec.begin(), vec.end(), 
                  [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
    
    return 0;
}