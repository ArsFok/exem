// Написать функцию, решающую квадратные уравнения с возвратом: 
// std::variant если два корня / int если один корень / monostate если нет корней
#include <iostream>
#include <variant>
#include <cmath>
#include <utility>

using QuadraticResult = std::variant<std::monostate, double, std::pair<double, double>>;

QuadraticResult solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            return std::monostate{};
        }
        return -c / b;
    }
    
    double D = b * b - 4 * a * c;
    
    if (D > 0) {
        double x1 = (-b + std::sqrt(D)) / (2 * a);
        double x2 = (-b - std::sqrt(D)) / (2 * a);
        return std::make_pair(x1, x2);
    } else if (D == 0) {
        double x = -b / (2 * a);
        return x;
    } else {
        return std::monostate{};
    }
}

void printResult(const QuadraticResult& result) {
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            std::cout << "Корней нет" << std::endl;
        } else if constexpr (std::is_same_v<T, double>) {
            std::cout << "Один корень: x = " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, std::pair<double, double>>) {
            std::cout << "Два корня: x1 = " << arg.first 
                      << ", x2 = " << arg.second << std::endl;
        }
    }, result);
}

int main() {
    std::cout << "x^2 - 5x + 6 = 0: ";
    printResult(solveQuadratic(1, -5, 6));
    
    std::cout << "x^2 - 4x + 4 = 0: ";
    printResult(solveQuadratic(1, -4, 4));
    
    std::cout << "x^2 + x + 1 = 0: ";
    printResult(solveQuadratic(1, 1, 1));
    
    return 0;
}