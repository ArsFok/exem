#include "copyfile.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Проверяем, что переданы оба имени файлов
    if (argc != 3) {
        std::cout << "Ошибка: нужно указать два файла!" << std::endl;
        return 1;  // Возвращаем код ошибки
    }
    
    // Пытаемся скопировать файл
    try {
        copyFile(argv[1], argv[2]);
        return 0;  // Всё хорошо
    }
     catch (const FileNotFound& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
        std::cout << "Проверьте, существует ли исходный файл." << std::endl;
        return 2;  // Код ошибки: файл не найден    
    }
     catch (const Overwriting& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
        std::cout << "Файл назначения уже существует. Удалите его или выберите другое имя." << std::endl;
        return 3;  // Код ошибки: защита от перезаписи    
    } 
    catch (const std::exception& e) {
        // Ловим любые другие исключения
        std::cout << "НЕИЗВЕСТНАЯ ОШИБКА: " << e.what() << std::endl;
        return 4;
    }
}