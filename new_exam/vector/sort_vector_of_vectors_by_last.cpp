// Сортируем вектор векторов по последнему элементу
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> vec = {
        {1, 2, 3}, {4, 5, 1}, {7, 8, 2}
    };
    
    std::sort(vec.begin(), vec.end(), 
        [](const auto& a, const auto& b) { return a.back() < b.back(); });
    
    for (const auto& v : vec) {
        for (int x : v) std::cout << x << " ";
        std::cout << "\n";
    }
    return 0;
}