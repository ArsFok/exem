#include "RGBA.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Конструктор по умолчанию (черный цвет)
RGBA::RGBA() 
    : RGB(), m_alpha(255) {}

// Конструктор с параметрами
RGBA::RGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : RGB(red, green, blue), m_alpha(alpha) {}

// Конструктор копирования
RGBA::RGBA(const RGBA& other)
    : RGB(other), m_alpha(other.m_alpha) {}

// Конструктор конвертации из RGB
RGBA::RGBA(const RGB& other)
    : RGB(other), m_alpha(255) {}

// Установка цвета с альфа-каналом
void RGBA::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    RGB::setColor(red, green, blue);
    m_alpha = alpha;
}

// Переопределенная установка цвета (без альфа-канала)
void RGBA::setColor(unsigned char red, unsigned char green, unsigned char blue) {
    RGB::setColor(red, green, blue);
    m_alpha = 255; // Устанавливаем альфа по умолчанию
}

// Переопределенная установка цвета без параметров
void RGBA::setColor() {
    RGB::setColor();
    m_alpha = 0;
}

// Получение значения альфа-канала
unsigned char RGBA::alpha() const {
    return m_alpha;
}

// Переопределенная функция печати
void RGBA::print(PrintType type) const {
    switch (type) {
        case E_RGB:
            // Вызываем базовую версию для RGB формата
            RGB::print(type);
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

// Перегруженная функция сложения для RGBA
RGBA* RGBA::sum(const RGBA& other) const {
    unsigned char newRed = static_cast<unsigned char>(std::min(255, static_cast<int>(m_red) + static_cast<int>(other.m_red)));
    unsigned char newGreen = static_cast<unsigned char>(std::min(255, static_cast<int>(m_green) + static_cast<int>(other.m_green)));
    unsigned char newBlue = static_cast<unsigned char>(std::min(255, static_cast<int>(m_blue) + static_cast<int>(other.m_blue)));
    unsigned char newAlpha = static_cast<unsigned char>(std::min(255, static_cast<int>(m_alpha) + static_cast<int>(other.m_alpha)));
    
    return new RGBA(newRed, newGreen, newBlue, newAlpha);
}

// Переопределенная функция сложения
RGB* RGBA::sum(const RGB& other) const {
    // Если other тоже RGBA, используем перегруженную версию
    const RGBA* otherRGBA = dynamic_cast<const RGBA*>(&other);
    if (otherRGBA) {
        return this->sum(*otherRGBA);
    }
    
    // Иначе складываем только RGB компоненты
    unsigned char newRed = static_cast<unsigned char>(std::min(255, static_cast<int>(m_red) + static_cast<int>(other.red())));
    unsigned char newGreen = static_cast<unsigned char>(std::min(255, static_cast<int>(m_green) + static_cast<int>(other.green())));
    unsigned char newBlue = static_cast<unsigned char>(std::min(255, static_cast<int>(m_blue) + static_cast<int>(other.blue())));
    
    return new RGBA(newRed, newGreen, newBlue, m_alpha);
}

// Переопределенная функция клонирования
RGB* RGBA::clone() const {
    return new RGBA(*this);
}