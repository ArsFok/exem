#include <memory>
#include <stdexcept>
#include <iostream>

template<typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    std::unique_ptr<Node> head;

public:
    // Конструкторы
    ForwardList() = default;
    ~ForwardList() = default;
    
    // Запрещаем копирование (умные указатели не копируются по умолчанию)
    ForwardList(const ForwardList&) = delete;
    ForwardList& operator=(const ForwardList&) = delete;
    
    // Разрешаем перемещение
    ForwardList(ForwardList&&) = default;
    ForwardList& operator=(ForwardList&&) = default;

    // Добавление элемента в начало списка
    void pushFront(const T& value) {
        auto newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    // Удаление элемента из начала списка
    void popFront() {
        if (empty()) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        head = std::move(head->next);
    }

    // Проверка на пустоту списка
    bool empty() const {
        return head == nullptr;
    }

    // Получение ссылки на первый элемент
    const T& front() const {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    // Неконстантная версия front() для удобства
    T& front() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }
};

int main() {
    ForwardList<int> list;
    
    // Добавляем элементы
    list.pushFront(3);
    list.pushFront(2);
    list.pushFront(1);
    
    // Проверяем front
    std::cout << "Front: " << list.front() << std::endl; // 1
    
    // Удаляем элементы
    list.popFront();
    std::cout << "Front after pop: " << list.front() << std::endl; // 2
    
    // Проверяем пустоту
    std::cout << "Is empty: " << std::boolalpha << list.empty() << std::endl; // false
    
    return 0;
}