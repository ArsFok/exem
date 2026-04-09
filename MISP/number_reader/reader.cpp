#include "reader.h"
#include <fstream>
#include <stdexcept>

NumberReader::NumberReader(const std::string& filename) : filename(filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::invalid_argument("File does not exist: " + filename);
    }
    
    if (!(file >> number)) {
        throw std::invalid_argument("Text in file is not a number: " + filename);
    }
}

int NumberReader::getNumber() const {
    return number;
}

void NumberReader::setNumber(int newNumber) {
    number = newNumber;
    
    std::ofstream file(filename);
    file << newNumber;
}