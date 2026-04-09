#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    size_t current_size;
    size_t current_capacity;

    void resize() {
        size_t new_capacity = (current_capacity == 0) ? 1 : current_capacity * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < current_size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        current_capacity = new_capacity;
    }

public:
    Queue() : data(nullptr), current_size(0), current_capacity(0) {}

    ~Queue() {
        delete[] data;
    }

    void push(T& value) {
        if (current_size == current_capacity) {
            resize();
        }
        data[current_size] = value;
        ++current_size;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        // Сдвигаем все элементы влево
        for (size_t i = 0; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --current_size;
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[0];
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data[current_size - 1];
    }

    bool empty() const {
        return current_size == 0;
    }

    size_t size() const {
        return current_size;
    }
};

#endif // QUEUE_H