// Измеряем время заполнения вектора 100000 случайных чисел
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<int> vec(100000);
    std::generate(vec.begin(), vec.end(), []() { return rand() % 33401; });
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Time: " << duration.count() << " ms\n";
    return 0;
}