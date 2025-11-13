#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include <vector>

template<typename T>
class Stack{
private:
    std::vector<T> data;
public:
    Stack() = default;

    void push(const T& value){
        data.push_back(value);
    }
    bool isEmpty() const{
        return data.empty(); // встроенная фукция в std::vector
    }
    void pop(){
        if(isEmpty()){
            throw std::runtime_error("Пустой стек!");
        }
        data.pop_back();
    }
    T& peek(){
        if(isEmpty()){
            throw std::runtime_error("Пустой стек!");
        }
        return data.back();
    }
    size_t size() const{
        return data.size();
    }
};

#endif