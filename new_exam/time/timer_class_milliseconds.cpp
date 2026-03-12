// Класс Timer, считающий миллисекунды с момента создания
#include <iostream>
#include <chrono>
#include <thread>

class Timer {
    std::chrono::steady_clock::time_point start;
public:
    Timer() : start(std::chrono::steady_clock::now()) {}
    
    long long milliseconds() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start).count();
    }
};

int main() {
    Timer t;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "Elapsed: " << t.milliseconds() << " ms\n";
    return 0;
}