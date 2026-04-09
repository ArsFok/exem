#include <iostream>
#include <stdexcept>

class Faction {
private:
    int _numenator;    // числитель
    int _determinator; // знаменатель
    
public:
    // Конструктор по умолчанию
    Faction() : _numenator(0), _determinator(1) {}
    
    // Конструктор с параметрами
    Faction(int numenator, int determinator) {
        if (determinator == 0) {
            throw std::runtime_error("Знаменатель не может быть равен нулю!");
        }
        _numenator = numenator;
        _determinator = determinator;
    }
    
    // Геттеры
    int numenator() const {
        return _numenator;
    }
    
    int determinator() const {
        return _determinator;
    }
    
    // Операторы +=, -=, *=, /= как методы класса
    Faction& operator+=(const Faction& other) {
        _numenator = _numenator * other._determinator + other._numenator * _determinator;
        _determinator = _determinator * other._determinator;
        return *this;
    }
    
    Faction& operator-=(const Faction& other) {
        _numenator = _numenator * other._determinator - other._numenator * _determinator;
        _determinator = _determinator * other._determinator;
        return *this;
    }
    
    Faction& operator*=(const Faction& other) {
        _numenator = _numenator * other._numenator;
        _determinator = _determinator * other._determinator;
        return *this;
    }
    
    Faction& operator/=(const Faction& other) {
        if (other._numenator == 0) {
            throw std::runtime_error("Деление на ноль!");
        }
        _numenator = _numenator * other._determinator;
        _determinator = _determinator * other._numenator;
        return *this;
    }
};

// Свободные функции для операторов +, -, *, /
Faction operator+(const Faction& a, const Faction& b) {
    Faction result = a;
    result += b;
    return result;
}

Faction operator-(const Faction& a, const Faction& b) {
    Faction result = a;
    result -= b;
    return result;
}

Faction operator*(const Faction& a, const Faction& b) {
    Faction result = a;
    result *= b;
    return result;
}

Faction operator/(const Faction& a, const Faction& b) {
    Faction result = a;
    result /= b;
    return result;
}

// Пример использования
int main() {
    try {
        Faction f1(1, 2);  // 1/2
        Faction f2(1, 3);  // 1/3
        
        std::cout << "f1 = " << f1.numenator() << "/" << f1.determinator() << std::endl;
        std::cout << "f2 = " << f2.numenator() << "/" << f2.determinator() << std::endl;
        
        Faction sum = f1 + f2;
        std::cout << "f1 + f2 = " << sum.numenator() << "/" << sum.determinator() << std::endl;
        
        Faction diff = f1 - f2;
        std::cout << "f1 - f2 = " << diff.numenator() << "/" << diff.determinator() << std::endl;
        
        Faction prod = f1 * f2;
        std::cout << "f1 * f2 = " << prod.numenator() << "/" << prod.determinator() << std::endl;
        
        Faction quot = f1 / f2;
        std::cout << "f1 / f2 = " << quot.numenator() << "/" << quot.determinator() << std::endl;
        
        // Проверка операторов присваивания
        Faction f3(1, 4);
        f3 += f1;
        std::cout << "f3 после += f1: " << f3.numenator() << "/" << f3.determinator() << std::endl;
        
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}