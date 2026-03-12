// Выводим файлы, начинающиеся с заданного символа
// Аргумент: <символ>
#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    char start_char = argv[1][0];
    
    for (const auto& entry : fs::directory_iterator(".")) {
        std::string name = entry.path().filename().string();
        if (!name.empty() && name[0] == start_char) {
            std::cout << name << "\n";
        }
    }
    return 0;
}