// Рекурсивно обойти диррикторию и вывести последний изменённый файл
// (полная версия с выводом времени)
#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
#include <ctime>

namespace fs = std::filesystem;

std::pair<fs::path, fs::file_time_type> findLastModifiedFile(const fs::path& directory) {
    std::pair<fs::path, fs::file_time_type> latestFile;
    bool first = true;
    
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (fs::is_regular_file(entry)) {
                auto lastWriteTime = entry.last_write_time();
                
                if (first || lastWriteTime > latestFile.second) {
                    latestFile = {entry.path(), lastWriteTime};
                    first = false;
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return {};
    }
    
    return latestFile;
}

int main(int argc, char* argv[]) {
    fs::path directory = (argc > 1) ? argv[1] : ".";
    
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Ошибка: '" << directory << "' не директория" << std::endl;
        return 1;
    }
    
    auto result = findLastModifiedFile(directory);
    
    if (!result.first.empty()) {
        std::cout << "Последний изменённый файл: " << result.first << std::endl;
        
        // Правильное преобразование времени
        auto sys_time = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            result.second - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
        );
        std::time_t time_t = std::chrono::system_clock::to_time_t(sys_time);
        
        std::cout << "Время: " << std::ctime(&time_t);
    } else {
        std::cout << "Файлы не найдены" << std::endl;
    }
    
    return 0;
}