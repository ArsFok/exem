#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <iomanip>

namespace fs = std::filesystem;

// Структура для хранения информации о файле
struct FileInfo {
    fs::path path;
    uintmax_t size;
    
    // Конструктор
    FileInfo(const fs::path& p, uintmax_t s) : path(p), size(s) {}
};

// Функция для сравнения файлов по размеру (для сортировки по убыванию)
bool compareBySizeDesc(const FileInfo& a, const FileInfo& b) {
    return a.size > b.size;
}

// Функция для форматированного вывода размера файла
std::string formatFileSize(uintmax_t size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    double formattedSize = static_cast<double>(size);
    
    while (formattedSize >= 1024.0 && unitIndex < 4) {
        formattedSize /= 1024.0;
        unitIndex++;
    }
    
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << formattedSize << " " << units[unitIndex];
    return ss.str();
}

int main(int argc, char* argv[]) {
    // Проверяем наличие аргумента командной строки
    if (argc < 2) {
        std::cerr << "Использование: " << argv[0] << " <директория>" << std::endl;
        return 1;
    }
    
    std::string directoryPath = argv[1];
    fs::path dirPath(directoryPath);
    
    // Проверяем, существует ли директория
    if (!fs::exists(dirPath)) {
        std::cerr << "Ошибка: директория '" << directoryPath << "' не существует." << std::endl;
        return 1;
    }
    
    // Проверяем, является ли путь директорией
    if (!fs::is_directory(dirPath)) {
        std::cerr << "Ошибка: '" << directoryPath << "' не является директорией." << std::endl;
        return 1;
    }
    
    try {
        std::vector<FileInfo> files;
        
        // Собираем информацию о файлах в директории
        for (const auto& entry : fs::directory_iterator(dirPath)) {
            if (fs::is_regular_file(entry.status())) {
                try {
                    uintmax_t fileSize = fs::file_size(entry.path());
                    files.emplace_back(entry.path().filename(), fileSize);
                } catch (const fs::filesystem_error& e) {
                    std::cerr << "Ошибка при получении размера файла " 
                              << entry.path().filename() << ": " << e.what() << std::endl;
                }
            }
        }
        
        // Сортируем файлы по размеру в порядке убывания
        std::sort(files.begin(), files.end(), compareBySizeDesc);
        
        // Выводим результаты
        std::cout << "Файлы в директории '" << directoryPath << "' (по убыванию размера):" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << std::left << std::setw(40) << "Имя файла" 
                  << std::right << std::setw(20) << "Размер" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        
        for (const auto& fileInfo : files) {
            std::cout << std::left << std::setw(40) 
                      << (fileInfo.path.string().length() > 38 ? 
                          fileInfo.path.string().substr(0, 35) + "..." : 
                          fileInfo.path.string())
                      << std::right << std::setw(20) 
                      << formatFileSize(fileInfo.size) << std::endl;
        }
        
        std::cout << "============================================================" << std::endl;
        std::cout << "Всего файлов: " << files.size() << std::endl;
        
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка файловой системы: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}