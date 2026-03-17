#include <iostream>
#include <functional>
#include <chrono>

long long measureTime(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return duration.count();
}

// обычная функция
void normalFunction() {
    for (volatile int i = 0; i < 100000000; i++);
}

// функциональный объект
struct Functor {
    void operator()() {
        for (volatile int i = 0; i < 100000000; i++);
    }
};

int main() {

    long long t1 = measureTime(normalFunction);

    long long t2 = measureTime([](){
        for (volatile int i = 0; i < 100000000; i++);
    });

    Functor f;
    long long t3 = measureTime(f);

    std::cout << "Normal function: " << t1 << " ms\n";
    std::cout << "Lambda: " << t2 << " ms\n";
    std::cout << "Functor: " << t3 << " ms\n";
}