#include "rgba.h"
#include <iomanip>
#include <sstream>
#include <algorithm>

// Вспомогательная функция для ограничения значения
int RGB::clamp(int value) const {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

// Конструктор по умолчанию
RGB::RGB() : red(0), green(0), blue(0) {}

// Конструктор с параметрами
RGB::RGB(int r, int g, int b) : red(clamp(r)), green(clamp(g)), blue(clamp(b)) {}

// Конструктор копирования
RGB::RGB(const RGB& other) : red(other.red), green(other.green), blue(other.blue) {}

// Оператор присваивания
RGB& RGB::operator=(const RGB& other) {
    if (this != &other) {
        red = other.red;
        green = other.green;
        blue = other.blue;
    }
    return *this;
}

// Оператор +=
RGB& RGB::operator+=(const RGB& other) {
    red = clamp(red + other.red);
    green = clamp(green + other.green);
    blue = clamp(blue + other.blue);
    return *this;
}

// Оператор -=
RGB& RGB::operator-=(const RGB& other) {
    red = clamp(red - other.red);
    green = clamp(green - other.green);
    blue = clamp(blue - other.blue);
    return *this;
}

// Геттеры
int RGB::getRed() const { return red; }
int RGB::getGreen() const { return green; }
int RGB::getBlue() const { return blue; }

// Сеттеры
void RGB::setRed(int r) { red = clamp(r); }
void RGB::setGreen(int g) { green = clamp(g); }
void RGB::setBlue(int b) { blue = clamp(b); }

// Преобразование в HEX
std::string RGB::getHex() const {
    std::stringstream ss;
    ss << "#" 
       << std::hex << std::setfill('0') << std::setw(2) << red
       << std::hex << std::setfill('0') << std::setw(2) << green
       << std::hex << std::setfill('0') << std::setw(2) << blue;
    return ss.str();
}

// Свободный оператор +
RGB operator+(const RGB& lhs, const RGB& rhs) {
    return RGB(lhs.getRed() + rhs.getRed(),
               lhs.getGreen() + rhs.getGreen(),
               lhs.getBlue() + rhs.getBlue());
}

// Свободный оператор -
RGB operator-(const RGB& lhs, const RGB& rhs) {
    return RGB(lhs.getRed() - rhs.getRed(),
               lhs.getGreen() - rhs.getGreen(),
               lhs.getBlue() - rhs.getBlue());
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, const RGB& rgb) {
    os << "RGB(" << rgb.getRed() << ", " << rgb.getGreen() << ", " << rgb.getBlue() << ")";
    return os;
}