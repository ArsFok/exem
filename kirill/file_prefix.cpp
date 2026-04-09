#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // Проверяем аргументы командной строки
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <директория> <префикс>\n";
        std::cerr << "Пример: " << argv[0] << " ./my_folder \"new_\"\n";
        return 1;
    }

    fs::path dir_path = argv[1];
    std::string prefix = argv[2];

    // Проверяем, существует ли директория
    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        std::cerr << "Ошибка: указанный путь не существует или не является директорией.\n";
        return 1;
    }

    std::vector<fs::path> files_to_rename;

    // 1. Рекурсивно собираем пути ко всем обычным файлам
    try {
        for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
            if (entry.is_regular_file()) {
                files_to_rename.push_back(entry.path());
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Ошибка доступа к файловой системе: " << e.what() << "\n";
        return 1;
    }

    // 2. Переименовываем собранные файлы
    int renamed_count = 0;
    for (const auto& file_path : files_to_rename) {
        // Формируем новое имя: берем родительскую папку + префикс + старое имя
        fs::path new_path = file_path.parent_path() / (prefix + file_path.filename().string());
        
        try {
            fs::rename(file_path, new_path);
            std::cout << "Переименован: " << file_path.filename() << " -> " << new_path.filename() << "\n";
            renamed_count++;
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Ошибка переименования " << file_path << ": " << e.what() << "\n";
        }
    }

    std::cout << "\nГотово! Успешно переименовано файлов: " << renamed_count << "\n";

    return 0;
}