#ifndef PAIR_CPP
#define PAIR_CPP

#include <iostream>
#include "pair.h"

// Конструктор по умолчанию
template<typename T1, typename T2>
Pair<T1, T2>::Pair() : first(), second() {}

// Конструктор с параметрами
template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& f, const T2& s) : first(f), second(s) {}

// Конструктор копирования
template<typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair& other) : first(other.first), second(other.second) {}

// Деструктор
template<typename T1, typename T2>
Pair<T1, T2>::~Pair() {}

// Оператор присваивания
template<typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

// Геттеры
template<typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const {
    return first;
}

template<typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const {
    return second;
}

// Сеттеры
template<typename T1, typename T2>
void Pair<T1, T2>::setFirst(const T1& value) {
    first = value;
}

template<typename T1, typename T2>
void Pair<T1, T2>::setSecond(const T2& value) {
    second = value;
}

// Оператор равенства
template<typename T1, typename T2>
bool Pair<T1, T2>::operator==(const Pair& other) const {
    return first == other.first && second == other.second;
}

// Оператор неравенства
template<typename T1, typename T2>
bool Pair<T1, T2>::operator!=(const Pair& other) const {
    return !(*this == other);
}

// Оператор меньше
template<typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair& other) const {
    if (first < other.first) return true;
    if (other.first < first) return false;
    return second < other.second;
}

// Оператор больше
template<typename T1, typename T2>
bool Pair<T1, T2>::operator>(const Pair& other) const {
    return other < *this;
}

// Оператор вывода
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& p) {
    os << "(" << p.getFirst() << ", " << p.getSecond() << ")";
    return os;
}

#endif // PAIR_CPP