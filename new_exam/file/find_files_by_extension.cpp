// Выводим файлы с заданным расширением из директории
// Аргументы: <директория> <расширение файла>
#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 3) return 1;
    
    std::string dir = argv[1], ext = argv[2];
    if (!ext.empty() && ext[0] != '.') ext = "." + ext;
    
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ext) {
            std::cout << entry.path().filename().string() << "\n";
        }
    }
    return 0;
}