#include "comment_remover.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

bool CommentRemover::removeComments(const std::string& inputFilename) {
    // Проверяем существование входного файла
    if (!fileExists(inputFilename)) {
        std::cerr << "Ошибка: Файл '" << inputFilename << "' не существует или недоступен для чтения." << std::endl;
        return false;
    }

    // Генерируем имя выходного файла
    std::string outputFilename = generateOutputFilename(inputFilename);
    
    // Проверяем, не перезапишем ли мы существующий файл
    if (fileExists(outputFilename) && !checkOverwrite(outputFilename)) {
        return false;
    }

    // Открываем входной файл
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл '" << inputFilename << "' для чтения." << std::endl;
        return false;
    }

    // Открываем выходной файл
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл '" << outputFilename << "' для записи." << std::endl;
        inputFile.close();
        return false;
    }

    try {
        // Обрабатываем файл
        processFile(inputFile, outputFile);
        
        std::cout << "Успешно: Комментарии удалены. Результат записан в '" << outputFilename << "'" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка при обработке файла: " << e.what() << std::endl;
        inputFile.close();
        outputFile.close();
        return false;
    }

    inputFile.close();
    outputFile.close();
    return true;
}

std::string CommentRemover::generateOutputFilename(const std::string& inputFilename) {
    // Находим последнюю точку в имени файла
    size_t lastDot = inputFilename.find_last_of('.');
    size_t lastSlash = inputFilename.find_last_of("/\\");
    
    std::string name, ext;
    
    if (lastDot != std::string::npos && (lastSlash == std::string::npos || lastDot > lastSlash)) {
        // Есть расширение
        name = inputFilename.substr(0, lastDot);
        ext = inputFilename.substr(lastDot);
    } else {
        // Нет расширения
        name = inputFilename;
        ext = "";
    }
    
    return name + "_formatted" + ext;
}

bool CommentRemover::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

bool CommentRemover::checkOverwrite(const std::string& filename) {
    std::cout << "Внимание: Файл '" << filename << "' уже существует." << std::endl;
    std::cout << "Перезаписать его? (y/n): ";
    
    std::string response;
    std::getline(std::cin, response);
    
    return (response == "y" || response == "Y" || response == "yes" || response == "YES");
}

void CommentRemover::processFile(std::ifstream& input, std::ofstream& output) {
    char current, next;
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    bool inString = false;
    bool inChar = false;
    char stringDelimiter = '"';
    
    while (input.get(current)) {
        if (inSingleLineComment) {
            // В однострочном комментарии - пропускаем до конца строки
            if (current == '\n') {
                inSingleLineComment = false;
                output.put(current); // Сохраняем перевод строки
            }
            continue;
        }
        
        if (inMultiLineComment) {
            // В многострочном комментарии - ищем конец
            if (current == '*') {
                next = getNextChar(input);
                if (next == '/') {
                    inMultiLineComment = false;
                }
            }
            continue;
        }
        
        if (inString) {
            // В строковом литерале
            output.put(current);
            if (current == '\\') {
                // Экранированный символ - читаем следующий
                if (input.get(next)) {
                    output.put(next);
                }
            } else if (current == stringDelimiter) {
                inString = false;
            }
            continue;
        }
        
        if (inChar) {
            // В символьном литерале
            output.put(current);
            if (current == '\\') {
                // Экранированный символ - читаем следующий
                if (input.get(next)) {
                    output.put(next);
                }
            } else if (current == '\'') {
                inChar = false;
            }
            continue;
        }
        
        // Не в комментарии и не в строке/символе
        if (current == '/') {
            next = getNextChar(input);
            
            if (next == '/') {
                // Начало однострочного комментария
                inSingleLineComment = true;
            } else if (next == '*') {
                // Начало многострочного комментария
                inMultiLineComment = true;
            } else {
                // Это не комментарий, а оператор деления
                output.put(current);
                if (next != EOF) {
                    output.put(next);
                }
            }
        } else if (current == '"') {
            // Начало строкового литерала
            inString = true;
            stringDelimiter = '"';
            output.put(current);
        } else if (current == '\'') {
            // Начало символьного литерала
            inChar = true;
            output.put(current);
        } else {
            // Обычный символ - записываем
            output.put(current);
        }
    }
    
    // Проверяем, не остались ли мы в многострочном комментарии
    if (inMultiLineComment) {
        std::cerr << "Предупреждение: Незакрытый многострочный комментарий в файле." << std::endl;
    }
}

char CommentRemover::getNextChar(std::ifstream& input) {
    char ch;
    if (input.get(ch)) {
        return ch;
    }
    return EOF;
}