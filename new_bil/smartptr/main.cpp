#include <iostream>
#include "smartptr.h"

// Тестовый класс
class TestClass {
public:
    int value;
    std::string name;
    
    TestClass(int v = 0, const std::string& n = "default") : value(v), name(n) {
        std::cout << "TestClass constructed: " << name << " (" << value << ")\n";
    }
    
    ~TestClass() {
        std::cout << "TestClass destroyed: " << name << " (" << value << ")\n";
    }
    
    void print() const {
        std::cout << "TestClass: " << name << " = " << value << "\n";
    }
};

int main() {
    // Тест 1: Создание умного указателя
    std::cout << "1. Создание умного указателя:\n";
    {
        SmartPtr<TestClass> ptr1(new TestClass(10, "first"));
        std::cout << "use_count: " << ptr1.use_count() << std::endl;
        ptr1->print();
        (*ptr1).value = 20;
        ptr1->print();
    }
    std::cout << "ptr1 вышел из области видимости - объект уничтожен\n\n";
    
    // Тест 2: Конструктор копирования и подсчет ссылок
    std::cout << "2. Конструктор копирования:\n";
    SmartPtr<TestClass> ptr2(new TestClass(30, "second"));
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    
    {
        SmartPtr<TestClass> ptr3 = ptr2; // Конструктор копирования
        std::cout << "После копирования:\n";
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
        std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;
        
        ptr3->value = 40;
        ptr2->print(); // Изменения видны в обоих указателях
        
        {
            SmartPtr<TestClass> ptr4(ptr3);
            std::cout << "После еще одного копирования:\n";
            std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
            std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;
            std::cout << "ptr4 use_count: " << ptr4.use_count() << std::endl;
        } // ptr4 уничтожается
        
        std::cout << "После уничтожения ptr4:\n";
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
        std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;
    } // ptr3 уничтожается
    
    std::cout << "После уничтожения ptr3:\n";
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    ptr2->print();
    std::cout << std::endl;
    
    // Тест 3: Оператор присваивания
    std::cout << "3. Оператор присваивания:\n";
    SmartPtr<TestClass> ptr5(new TestClass(50, "fifth"));
    SmartPtr<TestClass> ptr6(new TestClass(60, "sixth"));
    
    std::cout << "До присваивания:\n";
    std::cout << "ptr5 use_count: " << ptr5.use_count() << std::endl;
    std::cout << "ptr6 use_count: " << ptr6.use_count() << std::endl;
    
    ptr5 = ptr6; // Присваивание
    
    std::cout << "После присваивания:\n";
    std::cout << "ptr5 use_count: " << ptr5.use_count() << std::endl;
    std::cout << "ptr6 use_count: " << ptr6.use_count() << std::endl;
    std::cout << std::endl;
    
    // Тест 4: Оператор bool
    std::cout << "4. Оператор bool:\n";
    SmartPtr<TestClass> ptr7(new TestClass(70, "seventh"));
    SmartPtr<TestClass> ptr8(nullptr);
    
    if (ptr7) {
        std::cout << "ptr7 указывает на объект\n";
    }
    
    if (!ptr8) {
        std::cout << "ptr8 не указывает на объект\n";
    }
    std::cout << std::endl;
    
    // Тест 5: Функция get()
    std::cout << "5. Функция get():\n";
    SmartPtr<TestClass> ptr9(new TestClass(90, "ninth"));
    TestClass* raw_ptr = ptr9.get();
    std::cout << "Сырой указатель: " << raw_ptr << std::endl;
    raw_ptr->value = 95;
    ptr9->print();
    std::cout << std::endl;
    
    // Тест 6: Конструктор перемещения
    std::cout << "6. Конструктор перемещения:\n";
    SmartPtr<TestClass> ptr10(new TestClass(100, "tenth"));
    std::cout << "До перемещения: ptr10 use_count = " << ptr10.use_count() << std::endl;
    
    SmartPtr<TestClass> ptr11 = std::move(ptr10); // Перемещение
    std::cout << "После перемещения:\n";
    std::cout << "ptr10 use_count: " << ptr10.use_count() << std::endl;
    std::cout << "ptr11 use_count: " << ptr11.use_count() << std::endl;
    
    if (!ptr10) {
        std::cout << "ptr10 теперь пустой\n";
    }
    
    ptr11->print();
    
    std::cout << "\n=== Демонстрация завершена ===\n";
    
    return 0;
}