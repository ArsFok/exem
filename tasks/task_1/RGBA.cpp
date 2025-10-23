#include "RGBA.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Конструктор по умолчанию (черный цвет)
RGBA::RGBA() 
    : m_red(0), m_green(0), m_blue(0), m_alpha(255) {}

// Конструктор с параметрами
RGBA::RGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

// Конструктор копирования
RGBA::RGBA(const RGBA& other)
    : m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue), m_alpha(other.m_alpha) {}

// Установка цвета с параметрами
void RGBA::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    m_red = red;
    m_green = green;
    m_blue = blue;
    m_alpha = alpha;
}

// Установка цвета без параметров (все значения 0)
void RGBA::setColor() {
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_alpha = 0;
}

// Получение значения красного компонента
unsigned char RGBA::red() const {
    return m_red;
}

// Получение значения зеленого компонента
unsigned char RGBA::green() const {
    return m_green;
}

// Получение значения синего компонента
unsigned char RGBA::blue() const {
    return m_blue;
}

// Получение значения альфа-канала
unsigned char RGBA::alpha() const {
    return m_alpha;
}

// Печать цвета в различных форматах
void RGBA::print(PrintType type) const {
    switch (type) {
        case E_RGBA:
            std::cout << static_cast<int>(m_red) << " " 
                      << static_cast<int>(m_green) << " " 
                      << static_cast<int>(m_blue) << " " 
                      << static_cast<int>(m_alpha);
            break;
            
        case E_HEX:
            std::cout << "'#" 
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_red)
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_green)
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_blue)
                      << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(m_alpha)
                      << "'";
            break;
            
        case E_INT:
            unsigned int colorValue = (static_cast<unsigned int>(m_red) << 24) |
                                     (static_cast<unsigned int>(m_green) << 16) |
                                     (static_cast<unsigned int>(m_blue) << 8) |
                                     static_cast<unsigned int>(m_alpha);
            std::cout << colorValue;
            break;
    }
}

// Сложение цветов
RGBA RGBA::sum(const RGBA& other) const {
    unsigned char newRed = static_cast<unsigned char>(std::min(255, static_cast<int>(m_red) + static_cast<int>(other.m_red)));
    unsigned char newGreen = static_cast<unsigned char>(std::min(255, static_cast<int>(m_green) + static_cast<int>(other.m_green)));
    unsigned char newBlue = static_cast<unsigned char>(std::min(255, static_cast<int>(m_blue) + static_cast<int>(other.m_blue)));
    unsigned char newAlpha = static_cast<unsigned char>(std::min(255, static_cast<int>(m_alpha) + static_cast<int>(other.m_alpha)));
    
    return RGBA(newRed, newGreen, newBlue, newAlpha);
}