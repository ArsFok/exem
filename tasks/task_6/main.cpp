#include <iostream>
#include <string>
#include "comment_remover.h"

void printUsage(const std::string& programName) {
    std::cout << "Использование: " << programName << " <filename>" << std::endl;
    std::cout << "  <filename> - путь к C/C++ файлу для обработки" << std::endl;
    std::cout << std::endl;
    std::cout << "Пример: " << programName << " main.cpp" << std::endl;
    std::cout << "Создаст файл: main_formatted.cpp" << std::endl;
}

int main(int argc, char* argv[]) {
    // Проверяем количество аргументов
    if (argc != 2) {
        std::cerr << "Ошибка: Неверное количество аргументов." << std::endl;
        printUsage(argv[0]);
        return 1;
    }
    
    std::string filename = argv[1];
    
    // Проверяем специальные случаи
    if (filename == "-h" || filename == "--help") {
        printUsage(argv[0]);
        return 0;
    }
    
    if (filename == "-v" || filename == "--version") {
        std::cout << "Comment Remover v1.0" << std::endl;
        std::cout << "Удаляет комментарии из C/C++ файлов" << std::endl;
        return 0;
    }
    
    // Обрабатываем файл
    bool success = CommentRemover::removeComments(filename);
    
    return success ? 0 : 1;
}