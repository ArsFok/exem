// Реализовать прошрамму, проверющую имеется ли в заданной директории
// хотя бы один файл начинающийся с заданного символа 
// (директория и символ задаются как аргументы командной строки)
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // Проверяем аргументы командной строки
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] 
                  << " <директория> <символ>" << std::endl;
        return 1;
    }
    
    std::string directory = argv[1];
    char symbol = argv[2][0];
    
    // Проверяем существование директории
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Ошибка: директория не существует или не является директорией" 
                  << std::endl;
        return 1;
    }
    
    bool found = false;
    
    try {
        // Перебираем все файлы в директории
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                std::string filename = entry.path().filename().string();
                
                // Проверяем, начинается ли файл с заданного символа
                if (!filename.empty() && filename[0] == symbol) {
                    std::cout << "Найден файл: " << filename << std::endl;
                    found = true;
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка при чтении директории: " << e.what() << std::endl;
        return 1;
    }
    
    if (found) {
        std::cout << "\nНайден хотя бы один файл, начинающийся с символа '" 
                  << symbol << "'" << std::endl;
    } else {
        std::cout << "\nФайлы, начинающиеся с символа '" << symbol 
                  << "', не найдены" << std::endl;
    }
    
    return 0;
}