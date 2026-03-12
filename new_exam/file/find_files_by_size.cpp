// Находим файлы > 1 КБ в текущей директории
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.file_size() > 1024) {
            std::cout << entry.path().filename().string() 
                      << " (" << entry.file_size() << " bytes)\n";
        }
    }
    return 0;
}