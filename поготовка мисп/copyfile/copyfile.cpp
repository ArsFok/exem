#include "copyfile.h"
#include <fstream>
#include <iostream>

void copyFile(const char* source, const char* destination) {
    // Проверяем существование исходного файла
    std::ifstream sourceFile(source);
    if (!sourceFile.is_open()) {
        throw FileNotFound(source);  // Исходный файл не найден
    }
    
    // Проверяем, не существует ли уже файл назначения
    std::ifstream destCheck(destination);
    if (destCheck.is_open()) {
        destCheck.close();
        throw Overwriting(destination);  // Файл назначения уже существует
    }
    
    // Открываем файл назначения для записи
    std::ofstream destFile(destination);
    if (!destFile.is_open()) {
        throw std::runtime_error("Cannot create destination file");
    }
    
    // Копируем содержимое
    destFile << sourceFile.rdbuf();
    
    // Файлы автоматически закроются при выходе из функции
    // (деструкторы ifstream/ofstream вызываются автоматически)
}