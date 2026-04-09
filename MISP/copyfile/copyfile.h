#ifndef COPYFILE_H
#define COPYFILE_H

#include <exception>
#include <string>

/**
 * Класс исключения, выбрасываемое когда исходный файл не найден
 */
class FileNotFound : public std::exception {
private:
    std::string message;  // Строка для хранения детального сообщения об ошибке
    
public:
    FileNotFound(const char* filename) 
        : message(std::string("File not found ") + filename) {}
    
    /**
     * Виртуальная функция what() возвращает сообщение об ошибке
     * noexcept гарантирует, что функция не выбрасывает исключений
     */
    virtual const char* what() const noexcept override {
        return message.c_str();  // Возвращаем C-строку с сообщением
    }
};

class Overwriting : public std::exception {
private:
    std::string message;  // Строка для хранения детального сообщения об ошибке
    
public:
    Overwriting(const char* filename)
        : message(std::string("Overwriting protected file: ") + filename) {}
    
    /**
     * Виртуальная функция what() возвращает сообщение об ошибке
     */
    virtual const char* what() const noexcept override {
        return message.c_str();  // Возвращаем C-строку с сообщением
    }
};

/**
 * Функция копирования файлов с защитой от перезаписи
 * @param source имя исходного файла (должен существовать)
 * @param destination имя файла назначения (не должен существовать)
 * @throws FileNotFound если исходный файл не существует
 * @throws Overwriting если файл назначения уже существует
 */
void copyFile(const char* source, const char* destination);

#endif // COPYFILE_H