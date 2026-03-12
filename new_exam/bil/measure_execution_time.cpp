// Создать функцию принимающую std::function(тип void, без параметров)
// и измеряющую время работы этой функции. 
// Протестировать работу на функции, функторе и лямбде
#include <iostream>
#include <functional>
#include <chrono>
#include <thread>

// Функция для измерения времени выполнения
void measureTime(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    
    func();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Время выполнения: " << duration.count() << " мкс" << std::endl;
}

// Обычная функция
void regularFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Выполнена обычная функция" << std::endl;
}

// Функтор
class Functor {
public:
    void operator()() const {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        std::cout << "Выполнен функтор" << std::endl;
    }
};

int main() {
    std::cout << "Тест 1 - обычная функция:" << std::endl;
    measureTime(regularFunction);
    
    std::cout << "\nТест 2 - функтор:" << std::endl;
    Functor functor;
    measureTime(functor);
    
    std::cout << "\nТест 3 - лямбда:" << std::endl;
    measureTime([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Выполнена лямбда-функция" << std::endl;
    });
    
    return 0;
}