#ifndef COPYFILE_H
#define COPYFILE_H

#include <exception>
#include <string>

class FileNotFound : public std::exception{
private:
    std::string message;
public:
    FileNotFound(const char* filename) 
        : message(std::string("File not found ") + filename){}
    virtual const char* what() const noexcept override{
        return message.c_str();
    }
};

class Overwriting : public std::exception{
private:
    std::string message;
public:
    Overwriting(const char* filename)
        : message(std::string("Overwriting protected file: ") + filename){}

    virtual const char* what() const noexcept override{
        return message.c_str();
    }
};

void copyFile(const char* sourse, const char* destination);

#endif