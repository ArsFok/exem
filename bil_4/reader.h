#ifndef READER_H
#define READER_H

#include <string>

class NumberReader {
private:
    std::string filename;
public: 
    NumberReader(const std::string& fname);
    int getNumber() const;
    void setNumber(int num);
};

#endif