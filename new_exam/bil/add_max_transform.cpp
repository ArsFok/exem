//С помощью std::transform реализовать функцию,
//которая добавляет к каждому элементу максимальный на момент сложения
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void addMaxToElements(std::vector<int>& vec) {
    if (vec.empty()) return;
    
    int current_max = vec[0];
    
    std::transform(vec.begin(), vec.end(), vec.begin(),
        [&current_max](int& elem) {
            if (elem > current_max) {
                current_max = elem;
            }
            return elem + current_max;
        });
}

int main() {
    std::vector<int> vec = {1, 5, 3, 8, 2, 4, 6};
    
    std::cout << "Исходный вектор: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    addMaxToElements(vec);
    
    std::cout << "После преобразования: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}