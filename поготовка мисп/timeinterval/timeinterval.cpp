#include "timeinterval.h"
#include <iomanip>

void TimeInterval::normalize()
{
    // Переводим всё в секунды
    int total_seconds = hour * 3600 + min * 60 + sec;
    
    // Приводим к диапазону 0-86399 секунд (24 часа)
    total_seconds %= 86400;
    if (total_seconds < 0) {
        total_seconds += 86400;
    }
    
    // Обратное преобразование
    hour = total_seconds / 3600;
    total_seconds %= 3600;
    min = total_seconds / 60;
    sec = total_seconds % 60;
}

// Конструктор по умолчанию
TimeInterval::TimeInterval() : hour(0), min(0), sec(0) {}

// Конструктор с параметрами
TimeInterval::TimeInterval(int h, int m, int s) : hour(h), min(m), sec(s)
{
    normalize();
}

// Конструктор копирования
TimeInterval::TimeInterval(const TimeInterval& other)
    : hour(other.hour), min(other.min), sec(other.sec) {}

// Геттеры
int TimeInterval::getHour() const { return hour; }
int TimeInterval::getMin() const  { return min; }
int TimeInterval::getSec() const  { return sec; }

// Оператор +=
TimeInterval& TimeInterval::operator+=(const TimeInterval& other)
{
    hour += other.hour;
    min += other.min;
    sec += other.sec;
    normalize();
    return *this;
}

// Оператор -=
TimeInterval& TimeInterval::operator-=(const TimeInterval& other)
{
    hour -= other.hour;
    min -= other.min;
    sec -= other.sec;
    normalize();
    return *this;
}

// Оператор ==
bool TimeInterval::operator==(const TimeInterval& other) const
{
    // Сравниваем по количеству секунд от полуночи
    int this_seconds = hour * 3600 + min * 60 + sec;
    int other_seconds = other.hour * 3600 + other.min * 60 + other.sec;
    return this_seconds == other_seconds;
}

// Оператор !=
bool TimeInterval::operator!=(const TimeInterval& other) const
{
    return !(*this == other);
}

// Свободный оператор +
TimeInterval operator+(const TimeInterval& left, const TimeInterval& right)
{
    // Не используем operator+, создаём новый объект напрямую
    int total_h = left.getHour() + right.getHour();
    int total_m = left.getMin() + right.getMin();
    int total_s = left.getSec() + right.getSec();
    return TimeInterval(total_h, total_m, total_s);
}

// Свободный оператор -
TimeInterval operator-(const TimeInterval& left, const TimeInterval& right)
{
    // Не используем operator-, создаём новый объект напрямую
    int total_h = left.getHour() - right.getHour();
    int total_m = left.getMin() - right.getMin();
    int total_s = left.getSec() - right.getSec();
    return TimeInterval(total_h, total_m, total_s);
}

// Перегрузка оператора вывода <<
std::ostream& operator<<(std::ostream& os, const TimeInterval& ti)
{
    os << std::setfill('0')
       << std::setw(2) << ti.getHour() << ":"
       << std::setw(2) << ti.getMin() << ":"
       << std::setw(2) << ti.getSec();
    return os;
}