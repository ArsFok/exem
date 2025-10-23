#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string input;
    
    std::cout << "Введите строку, разделенную точками с запятыми: ";
    std::getline(std::cin, input);
    
    // Удаляем начальные и конечные пробелы
    input.erase(0, input.find_first_not_of(" \t"));
    input.erase(input.find_last_not_of(" \t") + 1);
    
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string token;
    int counter = 0;
    
    while (std::getline(ss, token, ';')) {
        // Удаляем пробелы в начале и конце токена
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);
        
        // Пропускаем пустые токены
        if (token.empty()) {
            continue;
        }
        
        // Ищем последний символ '/'
        size_t last_slash_pos = token.find_last_of('/');
        std::string modified;
        
        if (last_slash_pos != std::string::npos && last_slash_pos + 1 < token.length()) {
            modified = token.substr(last_slash_pos + 1);
        } else if (last_slash_pos != std::string::npos && last_slash_pos + 1 == token.length()) {
            // Если '/' в конце строки - берем пустую строку
            modified = "";
        } else {
            modified = token;
        }
        
        result.push_back(modified);
    }
    
    // Вывод результата
    std::cout << "Результат:" << std::endl;
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << i << ": " << result[i] << std::endl;
    }
    
    return 0;
}
//Компиляция
//g++ -std=c++11 -o string_processor main.cpp

//Запуск
//./string_processor