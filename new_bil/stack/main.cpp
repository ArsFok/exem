#include "stack.h"
#include <iostream>
#include <vector>

int main(){
    Stack<int> stack;
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << std::endl;
    std::cout << "Размер стека: " << stack.size() << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "После добавления 10, 20, 30:" << std::endl;
    std::cout << "Стек пуст? " << (stack.isEmpty() ? "Да" : "Нет") << std::endl;
    std::cout << "Размер стека: " << stack.size() << std::endl;
    std::cout << "Верхний элемент: " << stack.peek() << std::endl;

    std::cout << "\nСнимаем элементы:" << std::endl;
    while (!stack.isEmpty()) {
        std::cout << "Верхний элемент: " << stack.peek() << std::endl;
        stack.pop();
        std::cout << "Размер после pop: " << stack.size() << std::endl;
    }
    std::cout << "\nПроверка исключений:" << std::endl;
    Stack<double> doubleStack;
    try {
        std::cout << "Пытаемся вызвать pop() на пустом стеке..." << std::endl;
        doubleStack.pop();
    } catch (const std::runtime_error& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Пытаемся вызвать peek() на пустом стеке..." << std::endl;
        doubleStack.peek();
    } catch (const std::runtime_error& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }
    return 0;
}