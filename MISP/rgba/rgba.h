#ifndef RGB_H
#define RGB_H

#include <iostream>
#include <string>

class RGB {
private:
    int red;
    int green;
    int blue;
    
    // Вспомогательная функция для ограничения значения в диапазоне [0, 255]
    int clamp(int value) const;

public:
    // Конструкторы
    RGB();                                    // конструктор по умолчанию
    RGB(int r, int g, int b);                 // конструктор с параметрами
    RGB(const RGB& other);                    // конструктор копирования
    
    // Оператор присваивания
    RGB& operator=(const RGB& other);
    
    // Операторы += и -= (методы класса)
    RGB& operator+=(const RGB& other);
    RGB& operator-=(const RGB& other);
    
    // Геттеры
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    
    // Сеттеры
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    
    // Преобразование в HEX
    std::string getHex() const;
};

// Свободные операторы + и -
RGB operator+(const RGB& lhs, const RGB& rhs);
RGB operator-(const RGB& lhs, const RGB& rhs);

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, const RGB& rgb);

#endif // RGB_H