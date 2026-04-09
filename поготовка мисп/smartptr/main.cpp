#include <iostream>
#include <string>
#include "smartptr.h"

class TestClass {
public:
    std::string name;
    int value;
    
    TestClass(const std::string& n, int v) : name(n), value(v) {
        std::cout << "🟢 Создан объект: " << name << " (" << value << ")\n";
    }
    
    ~TestClass() {
        std::cout << "🔴 Удален объект: " << name << "\n";
    }
    
    void print() const {
        std::cout << "   Объект " << name << ", value = " << value << "\n";
    }
};

int main() {
    std::cout << "========== ТЕСТ 1: Конструктор с указателем ==========\n";
    // 1. Конструктор с указателем
    SimpleSmartPtr<TestClass> p1(new TestClass("Первый", 100));
    std::cout << "use_count p1: " << p1.use_count() << "\n\n";
    
    std::cout << "========== ТЕСТ 2: Конструктор копирования ==========\n";
    // 2. Конструктор копирования
    SimpleSmartPtr<TestClass> p2 = p1;  // Копирование
    std::cout << "use_count p1: " << p1.use_count() << "\n";
    std::cout << "use_count p2: " << p2.use_count() << "\n\n";
    
    std::cout << "========== ТЕСТ 3: Операторы * и -> ==========\n";
    // 3. Операторы * и ->
    (*p1).print();        // Оператор *
    p2->print();          // Оператор ->
    std::cout << "Значение через *: " << (*p1).value << "\n";
    std::cout << "Значение через ->: " << p2->value << "\n\n";
    
    std::cout << "========== ТЕСТ 4: Оператор bool ==========\n";
    // 4. Оператор bool
    if (p1) {
        std::cout << "p1 не пустой\n";
    }
    
    SimpleSmartPtr<TestClass> p3;  // Пустой указатель
    if (!p3) {
        std::cout << "p3 пустой\n\n";
    }
    
    std::cout << "========== ТЕСТ 5: Функция get() ==========\n";
    // 5. Функция get()
    TestClass* raw_ptr = p1.get();
    std::cout << "Сырой указатель: " << raw_ptr << "\n";
    raw_ptr->print();  // Можно работать как с обычным указателем
    std::cout << "use_count после get(): " << p1.use_count() << " (не изменился)\n\n";
    
    std::cout << "========== ТЕСТ 6: Конструктор перемещения ==========\n";
    // 6. Конструктор перемещения
    SimpleSmartPtr<TestClass> p4 = std::move(p1);
    std::cout << "use_count p4: " << p4.use_count() << "\n";
    std::cout << "p1.use_count(): " << p1.use_count() << " (p1 теперь пуст)\n";
    std::cout << "p2.use_count(): " << p2.use_count() << " (p2 все еще указывает на объект)\n\n";
    
    std::cout << "========== ТЕСТ 7: Демонстрация автоматического удаления ==========\n";
    {
        SimpleSmartPtr<TestClass> p5(new TestClass("Временный", 500));
        std::cout << "Внутри блока, use_count p5: " << p5.use_count() << "\n";
    }  // Здесь p5 удалится, объект "Временный" должен удалиться
    std::cout << "Выход из блока - временный объект удален\n\n";
    
    std::cout << "========== ТЕСТ 8: Проверка use_count() ==========\n";
    std::cout << "Сейчас на объект 'Первый' ссылаются: " << p2.use_count() << " указателя\n";
    std::cout << "(p2 и p4, так как p1 стал пустым после перемещения)\n\n";
    
    std::cout << "========== КОНЕЦ ПРОГРАММЫ ==========\n";
    std::cout << "Сейчас должны удалиться p2 и p4, и объект 'Первый'\n";
    // Здесь p2 и p4 удалятся автоматически, объект "Первый" должен удалиться
    return 0;
}