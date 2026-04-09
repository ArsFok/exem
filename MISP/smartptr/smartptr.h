#include <iostream>

template<typename T>
class SimpleSmartPtr {
private:
    T* ptr;           // Указатель на объект
    int* ref_count;   // Счетчик ссылок (храним в куче, чтобы все копии видели одно число)
    
public:
    // ========== 1. КОНСТРУКТОР С УКАЗАТЕЛЕМ ==========
    // Принимает сырой указатель на объект и начинает им управлять
    explicit SimpleSmartPtr(T* p = nullptr) {
        ptr = p;
        if (ptr != nullptr) {
            // Если указатель не пустой - создаем счетчик и ставим 1
            ref_count = new int(1);
        } else {
            // Для пустого указателя счетчик = 0
            ref_count = new int(0);
        }
    }
    
    // ========== 2. КОНСТРУКТОР КОПИРОВАНИЯ ==========
    // Создает новый умный указатель, который ссылается на тот же объект
    SimpleSmartPtr(const SimpleSmartPtr& other) {
        ptr = other.ptr;              // Копируем указатель на объект
        ref_count = other.ref_count;   // Копируем указатель на счетчик
        
        if (ref_count != nullptr && *ref_count > 0) {
            (*ref_count)++;  // Увеличиваем счетчик - появился еще один владелец
        }
    }
    
    // ========== 3. КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ ==========
    // Забирает владение у другого указателя, другой становится пустым
    SimpleSmartPtr(SimpleSmartPtr&& other) noexcept {
        ptr = other.ptr;               // Забираем указатель на объект
        ref_count = other.ref_count;    // Забираем указатель на счетчик
        
        // Других указатель больше не владеет объектом
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    
    // ========== 4. ДЕСТРУКТОР ==========
    // Уменьшает счетчик, если счетчик стал 0 - удаляет объект и счетчик
    ~SimpleSmartPtr() {
        if (ref_count != nullptr) {
            (*ref_count)--;  // Уменьшаем счетчик
            
            if (*ref_count == 0) {
                // Мы последние, кто владел объектом - удаляем всё
                delete ptr;
                delete ref_count;
            }
        }
    }
    
    // ========== 5. ОПЕРАТОР * (РАЗЫМЕНОВАНИЕ) ==========
    // Позволяет получить доступ к самому объекту: *ptr
    T& operator*() const {
        return *ptr;
    }
    
    // ========== 6. ОПЕРАТОР -> (ДОСТУП К ЧЛЕНАМ) ==========
    // Позволяет вызывать методы объекта: ptr->method()
    T* operator->() const {
        return ptr;
    }
    
    // ========== 7. ОПЕРАТОР BOOL ==========
    // Позволяет проверять, указывает ли указатель на что-то: if (ptr) {...}
    explicit operator bool() const {
        return ptr != nullptr;
    }
    
    // ========== 8. ФУНКЦИЯ GET ==========
    // Возвращает сырой указатель (для случаев, когда нужно передать его в старый код)
    T* get() const {
        return ptr;
    }
    
    // ========== 9. ФУНКЦИЯ USE_COUNT ==========
    // Возвращает количество умных указателей, ссылающихся на этот объект
    int use_count() const {
        return (ref_count != nullptr) ? *ref_count : 0;
    }
};