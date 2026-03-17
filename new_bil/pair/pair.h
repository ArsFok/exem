#ifndef PAIR_H
#define PAIR_H
#include "pair.cpp" 

template<typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
    
public:
    // Конструктор по умолчанию
    Pair();
    
    // Конструктор с параметрами
    Pair(const T1& f, const T2& s);
    
    // Конструктор копирования
    Pair(const Pair& other);
    
    // Деструктор
    ~Pair();
    
    // Оператор присваивания
    Pair& operator=(const Pair& other);
    
    // Геттеры
    T1 getFirst() const;
    T2 getSecond() const;
    
    // Сеттеры
    void setFirst(const T1& value);
    void setSecond(const T2& value);
    
    // Операторы сравнения
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator>(const Pair& other) const;
};

// Оператор вывода (не член класса)
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& p);


#endif // PAIR_H