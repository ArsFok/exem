#ifndef RGBA_H
#define RGBA_H

#include "RGB.h"

class RGBA : public RGB {
private:
    unsigned char m_alpha;

public:
    // Конструкторы
    RGBA(); // по умолчанию (черный цвет)
    RGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255); // с параметрами
    RGBA(const RGBA& other); // копирования
    RGBA(const RGB& other); // конвертация из RGB
    ~RGBA() override {}

    // Перегруженные функции установки цвета
    void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
    void setColor(unsigned char red, unsigned char green, unsigned char blue) override;
    void setColor() override;

    // Дополнительные функции получения значений
    unsigned char alpha() const;

    // Переопределенная функция печати
    void print(PrintType type = E_RGB) const override;

    // Перегруженная функция сложения
    RGBA* sum(const RGBA& other) const;
    RGB* sum(const RGB& other) const override;

    // Переопределенная функция клонирования
    RGB* clone() const override;
};

#endif // RGBA_H