#include "RGB.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Конструктор по умолчанию (черный цвет)
RGB::RGB() 
    : m_red(0), m_green(0), m_blue(0) {}

// Конструктор с параметрами
RGB::RGB(unsigned char red, unsigned char green, unsigned char blue)
    : m_red(red), m_green(green), m_blue(blue) {}

// Конструктор копирования
RGB::RGB(const RGB& other)
    : m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue) {}

// Установка цвета с параметрами
void RGB::setColor(unsigned char red, unsigned char green, unsigned char blue) {
    m_red = red;
    m_green = green;
    m_blue = blue;
}

// Установка цвета без параметров (все значения 0)
void RGB::setColor() {
    m_red = 0;
    m_green = 0;
    m_blue = 0;
}

// Получение значения красного компонента
unsigned char RGB::red() const {
    return m_red;
}

// Получение значения зеленого компонента
unsigned char RGB::green() const {
    return m_green;
}

// Получение значения синего компонента
unsigned char RGB::blue() const {
    return m_blue;
}

// Печать цвета в различных форматах
void RGB::print(PrintType type) const {
    switch (type) {
        case E_RGB:
            std::cout << static_cast<int>(m_red) << " " 
                      << static_cast<int>(m_green) << " " 
                      << static_cast<int>(m_blue);
            break;
            
        case E_HEX:
            std::cout << "'#" 
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_red)
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_green)
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_blue)
                      << "'";
            break;
            
        case E_INT:
            unsigned int colorValue = (static_cast<unsigned int>(m_red) << 16) |
                                     (static_cast<unsigned int>(m_green) << 8) |
                                     static_cast<unsigned int>(m_blue);
            std::cout << colorValue;
            break;
    }
}

// Сложение цветов
RGB* RGB::sum(const RGB& other) const {
    unsigned char newRed = static_cast<unsigned char>(std::min(255, static_cast<int>(m_red) + static_cast<int>(other.m_red)));
    unsigned char newGreen = static_cast<unsigned char>(std::min(255, static_cast<int>(m_green) + static_cast<int>(other.m_green)));
    unsigned char newBlue = static_cast<unsigned char>(std::min(255, static_cast<int>(m_blue) + static_cast<int>(other.m_blue)));
    
    return new RGB(newRed, newGreen, newBlue);
}

// Клонирование объекта
RGB* RGB::clone() const {
    return new RGB(*this);
}