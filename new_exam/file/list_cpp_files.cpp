// Выводим все .cpp файлы в текущей директории
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            std::cout << entry.path().filename().string() << "\n";
        }
    }
    return 0;
}