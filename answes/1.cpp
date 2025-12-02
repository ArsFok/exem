#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

<<<<<<< Updated upstream
// Глобальная переменная для хранения максимального элемента
int global_max;

// Обычная функция для сложения с максимальным элементом
int addWithMax(int element) {
    return element + global_max;
}

=======
>>>>>>> Stashed changes
int main() {
    std::vector<int> numbers = {1, 3, 5, 2, 4};
    std::vector<int> result(numbers.size());
    
    std::cout << "Исходный вектор: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
<<<<<<< Updated upstream
    // Находим максимальный элемент
    global_max = *std::max_element(numbers.begin(), numbers.end());
    
    std::cout << "Максимальный элемент: " << global_max << std::endl;
    
    // Используем std::transform с обычной функцией
    std::transform(numbers.begin(), numbers.end(), result.begin(), addWithMax);
=======
    // Используем std::transform с лямбда-функцией
    std::transform(numbers.begin(), numbers.end(), result.begin(),
        // Лямбда-функция, захватывающая вектор numbers по ссылке
        [&numbers](int element) {
            // Находим максимальный элемент в векторе на момент вызова
            int max_element = *std::max_element(numbers.begin(), numbers.end());
            // Складываем текущий элемент с максимальным
            return element + max_element;
        });
>>>>>>> Stashed changes
    
    std::cout << "Результат (элемент + максимальный элемент вектора): ";
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}