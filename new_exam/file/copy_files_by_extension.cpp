// Копируем файлы с заданным расширением в другую папку
// Аргументы: <исходная_директория> <расширение файла> <куда> 
// Пример: ./a.out ../../bil_5 .h ./
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 4) return 1;
    
    std::string src_dir = argv[1], ext = argv[2], dst_dir = argv[3];
    if (!ext.empty() && ext[0] != '.') ext = "." + ext;
    
    fs::create_directories(dst_dir);
    for (const auto& entry : fs::directory_iterator(src_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ext) {
            fs::copy(entry.path(), fs::path(dst_dir) / entry.path().filename(),
                     fs::copy_options::overwrite_existing);
        }
    }
    return 0;
}