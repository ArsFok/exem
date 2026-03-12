// Файлы, изменённые за последние N дней и размером > M байт
// Аргументы: <директория> <дней> <мин_размер_байт>
#include <iostream>
#include <filesystem>
#include <chrono>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 4) return 1;
    
    std::string dir = argv[1];
    int days = std::stoi(argv[2]);
    uintmax_t min_size = std::stoull(argv[3]);
    
    auto now = fs::file_time_type::clock::now();
    auto threshold = now - std::chrono::hours(days * 24);
    
    for (const auto& entry : fs::recursive_directory_iterator(dir)) {
        if (entry.is_regular_file() && 
            entry.last_write_time() > threshold && 
            entry.file_size() > min_size) {
            std::cout << entry.path().string() << "\n";
        }
    }
    return 0;
}