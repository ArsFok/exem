#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <stdexcept>

template <typename T>
class Optional {
private:
    T value;
    bool has_value;

public:
    // Конструктор по умолчанию
    Optional() : has_value(false) {}

    // Конструктор с параметром
    Optional(const T& val) : value(val), has_value(true) {}

    // Оператор *
    T& operator*() {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return value;
    }

    const T& operator*() const {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return value;
    }

    // Оператор ->
    T* operator->() {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return &value;
    }

    const T* operator->() const {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return &value;
    }

    // Оператор bool
    explicit operator bool() const {
        return has_value;
    }

    // Функция value()
    T& value() {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return value;
    }

    const T& value() const {
        if (!has_value) {
            throw std::runtime_error("Optional does not contain a value");
        }
        return value;
    }

    // Функция value_or
    T value_or(const T& defaultValue) const {
        if (has_value) {
            return value;
        }
        return defaultValue;
    }
};

#endif // OPTIONAL_H