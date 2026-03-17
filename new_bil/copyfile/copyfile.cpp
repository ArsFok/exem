#include "copyfile.h"
#include <fstream>
#include <iostream>

void copyFile(const char* sourse, const char* destination){
    std::ifstream src(sourse, std::ios::binary);
    if(!src.is_open()){
        throw FileNotFound(sourse);
    }
    std::ifstream dest_test(destination, std::ios::binary);
    if(dest_test.is_open()){
        dest_test.close();
        throw Overwriting(destination);
    }
    src.close();
    src.open(sourse, std::ios::binary);
    std::ofstream dst(destination, std::ios::binary);
    if(!dst.is_open()){
        throw FileNotFound(destination);
    }

    char buffer[4096];
    while(src.read(buffer, sizeof(buffer)) || src.gcount() > 0){
        dst.write(buffer, src.gcount());
    }

    src.close();
    dst.close();

    std::cout << "Файл скопирован успешно: " << sourse << "->" << destination << std::endl; 
}