#ifndef RGB_H
#define RGB_H

#include <iostream>

enum PrintType {
    E_RGB,
    E_HEX,
    E_INT
};

class RGB {
protected:
    unsigned char m_red;
    unsigned char m_green;
    unsigned char m_blue;

public:
    // Конструкторы
    RGB(); // по умолчанию (черный цвет)
    RGB(unsigned char red, unsigned char green, unsigned char blue); // с параметрами
    RGB(const RGB& other); // копирования
    virtual ~RGB() {} // Виртуальный деструктор

    // Функции установки цвета
    virtual void setColor(unsigned char red, unsigned char green, unsigned char blue);
    virtual void setColor();

    // Функции получения значений цветов
    virtual unsigned char red() const;
    virtual unsigned char green() const;
    virtual unsigned char blue() const;

    // Виртуальная функция печати
    virtual void print(PrintType type = E_RGB) const;

    // Функция сложения
    virtual RGB* sum(const RGB& other) const;

    // Виртуальная функция для клонирования
    virtual RGB* clone() const;
};

#endif // RGB_H