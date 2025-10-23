#ifndef RGBA_H
#define RGBA_H

#include <iostream>

enum PrintType {
    E_RGBA,
    E_HEX,
    E_INT
};

class RGBA {
private:
    unsigned char m_red;
    unsigned char m_green;
    unsigned char m_blue;
    unsigned char m_alpha;

public:
    // Конструкторы
    RGBA(); // по умолчанию (черный цвет)
    RGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255); // с параметрами
    RGBA(const RGBA& other); // копирования

    // Функции установки цвета
    void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    void setColor();

    // Функции получения значений цветов
    unsigned char red() const;
    unsigned char green() const;
    unsigned char blue() const;
    unsigned char alpha() const;

    // Функция печати
    void print(PrintType type = E_RGBA) const;

    // Функция сложения
    RGBA sum(const RGBA& other) const;
};

#endif // RGBA_H