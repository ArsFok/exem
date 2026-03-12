// Обойти дирректорию и вывести файлы в порядке убывания размера
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <iomanip>

namespace fs = std::filesystem;

std::vector<std::pair<fs::path, uintmax_t>> getFilesSortedBySize(const fs::path& directory) {
    std::vector<std::pair<fs::path, uintmax_t>> files;
    
    try {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (fs::is_regular_file(entry)) {
                files.emplace_back(entry.path(), entry.file_size());
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка при чтении директории: " << e.what() << std::endl;
        return {};
    }
    
    // Сортируем по убыванию размера
    std::sort(files.begin(), files.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
    
    return files;
}

std::string formatSize(uintmax_t bytes) {
    const char* units[] = {"B", "KB", "MB", "GB"};
    int index = 0;
    double size = static_cast<double>(bytes);
    
    while (size >= 1024 && index < 3) {
        size /= 1024;
        index++;
    }
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << size << " " << units[index];
    return oss.str();
}

int main(int argc, char* argv[]) {
    fs::path directory = (argc > 1) ? argv[1] : ".";
    
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Ошибка: '" << directory << "' не является директорией" << std::endl;
        return 1;
    }
    
    auto files = getFilesSortedBySize(directory);
    
    std::cout << "Файлы в директории '" << directory << "' (по убыванию размера):\n" << std::endl;
    std::cout << std::left << std::setw(50) << "Имя файла" << std::right << std::setw(15) << "Размер" << std::endl;
    std::cout << std::string(66, '-') << std::endl;
    
    for (const auto& [path, size] : files) {
        std::cout << std::left << std::setw(50) << path.filename().string() 
                  << std::right << std::setw(15) << formatSize(size) << std::endl;
    }
    
    return 0;
}
