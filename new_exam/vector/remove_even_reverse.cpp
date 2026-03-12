// Удаляем чётные числа и выводим в обратном порядке
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), 
              [](int x) { return x % 2 == 0; }), vec.end());
    std::reverse(vec.begin(), vec.end());
    
    for (int x : vec) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}