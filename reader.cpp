#include "reader.h"
#include <fstream>
#include <iostream>

NumberReader::NumberReader(const std::string& fname) {
    filename = fname;
}

int NumberReader::getNumber() const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 0;
    }
    
    int num = 0;
    file >> num;
    
    if (file.fail()) {
        std::cerr << "Файл: " << filename << " не содержит число" << std::endl;
        file.close();
        return 0;
    }
    
    file.close();
    return num;
}

void NumberReader::setNumber(int num) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Файл: " << filename << " не удалось открыть для записи" << std::endl;
        return;
    }
    
    file << num;
    file.close();
}