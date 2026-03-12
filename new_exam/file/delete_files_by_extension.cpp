// Удаляем файлы с заданным расширением в директории
// Аргументы: <директория> <расширение файла>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 3) return 1;
    
    std::string dir = argv[1], ext = argv[2];
    if (!ext.empty() && ext[0] != '.') ext = "." + ext;
    
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ext) {
            std::cout << "Deleting: " << entry.path().filename() << "\n";
            fs::remove(entry.path());
        }
    }
    return 0;
}