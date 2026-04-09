#ifndef NUMBER_READER_H
#define NUMBER_READER_H

#include <string>

class NumberReader {
private:
    std::string filename;
    int number;

public:
    // Конструктор, принимающий имя файла
    explicit NumberReader(const std::string& filename);

    // Получение считанного числа
    int getNumber() const;

    // Перезапись числа в файле
    void setNumber(int newNumber);
};

#endif // NUMBER_READER_H