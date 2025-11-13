#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <cstddef>

template<typename T>
class SmartPtr{
private:
    T* ptr;
    size_t* ref_count;

    void release(){
        if(ref_count){
            (*ref_count)--;
            if(*ref_count == 0){
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }
        }
    }
public:
    //Конструктор
    explicit SmartPtr(T* p = nullptr) : ptr(p), ref_count(new size_t(1)){
        if(p == nullptr){
            *ref_count = 0;
        }
    }
    //Конструктор копирования
    SmartPtr(const SmartPtr& other) : ptr(other.ptr), ref_count(other.ref_count){
        if(ref_count && ptr){
            (*ref_count)++;
        }
    }
    //Конструктор перемещения
    SmartPtr(SmartPtr& other) noexcept : ptr(other.ptr), ref_count(other.ref_count){
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }
    //Деструктор
    ~SmartPtr(){
        release();
    }
    SmartPtr& operator=(const SmartPtr& other){
        if(this != &other){
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if(ref_count && ptr){
                (*ref_count)++;
            }
        }
        return *this;
    }
    SmartPtr& operator=(SmartPtr& other) noexcept{
        if(this != &other){
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }
    T& operator *() const {
        return *ptr;
    }
    T* operator ->() const {
        return ptr;
    }
    explicit operator bool () const{
        return ptr != nullptr;
    }
    T* get() const{
        return ptr;
    }
    size_t use_count() const{
        return ref_count ? *ref_count : 0;
    }
};

#endif