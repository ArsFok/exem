#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

#include <iostream>

class TimeInterval
{
private:
    int hour;   // 0-23
    int min;    // 0-59
    int sec;    // 0-59

    // Вспомогательный метод для нормализации времени
    void normalize();

public:
    // Конструктор по умолчанию (0:00:00)
    TimeInterval();

    // Конструктор с параметрами
    TimeInterval(int h, int m, int s);

    // Конструктор копирования
    TimeInterval(const TimeInterval& other);

    // Геттеры
    int getHour() const;
    int getMin() const;
    int getSec() const;

    // Операторы-методы класса
    TimeInterval& operator+=(const TimeInterval& other);
    TimeInterval& operator-=(const TimeInterval& other);
    bool operator==(const TimeInterval& other) const;
    bool operator!=(const TimeInterval& other) const;
};

// Свободные операторы
TimeInterval operator+(const TimeInterval& left, const TimeInterval& right);
TimeInterval operator-(const TimeInterval& left, const TimeInterval& right);
std::ostream& operator<<(std::ostream& os, const TimeInterval& ti);

#endif