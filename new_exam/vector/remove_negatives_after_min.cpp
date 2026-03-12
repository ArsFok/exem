// Вывести каждый отрицательный элемент после минимального в векторе
// с помощью std::for_each и std::remove_if
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, -10, -9, -8, 0, -1, 4};
    auto min_it = std::min_element(vec.begin(), vec.end());
    
    std::cout << "Min: " << *min_it << "\nNegatives after: ";
    std::for_each(min_it + 1, vec.end(), [](int x) {
        if (x < 0) std::cout << x << " ";
    });
    std::cout << std::endl;
    return 0;
}