#создание класса

class class_name{
private:
    int a, b, c;
    //
    void error(std::string str){
        
    }
public:
    // дефолтный конструктор
    class_name() = default;
    // конструктор с параметрами
    class_name(int a, int b, int c) : a(a), b(b), c(c) {}
    // конструктор копирования
    class_name(const class_name& p) : a(p.a), b(p.b), c(p.c) {}
    //оператор копирования
    class_name& operator=(const class_name& other){
        if(&other != this){
            a = other.a;
            b = other.b;
            c = other.c;
        }
        return *this;
    }
    //перегрузка оператора сравнения
    friend bool operator==(const class_name& lhs, const class_name& rhs);
    //Геттеры
    int getA() const{
        return a;
    }
    int getB() const{
        return b;
    }
    int getC() const{
        return c;
    }
    //Сеттеры
    void setA(int _a){
        a = _a;
    }
    void setB(int _b){
        b = _b;
    }
    void setC(int _c){
        c = _c;
    }
    //Деструктор
    ~class_name() = default;
};
bool operator==(const class_name& lhs, const class_name& rhs){
    return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
}

#Библиотки ^_^

#include <iosteram> - поток ввода вывода
#include <fstream> - файлы
#include <string> - работа со строками
#include <vector> - работа с векторами
Функции: 
push_back(value) — добавляет элемент в конец вектора;
pop_back() — удаляет последний элемент;
size() — возвращает количество элементов;
resize(newSize) — изменяет размер вектора;
clear() — очищает вектор (удаляет все элементы);
at(index) — возвращает элемент по индексу с проверкой границ;
begin(), end — возвращают итераторы на начало и конец вектора.