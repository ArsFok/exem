// С помощью find_if найти первый отрицательный элемент после максимального
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 10, 7, 0, -3};
    auto max_it = std::max_element(vec.begin(), vec.end());
    auto neg_it = std::find_if(max_it + 1, vec.end(), [](int x) { return x < 0; });
    
    if (neg_it != vec.end()) {
        std::cout << "Found: " << *neg_it << " at index " 
                  << std::distance(vec.begin(), neg_it) << std::endl;
    } else {
        std::cout << "No negative after max\n";
    }
    return 0;
}