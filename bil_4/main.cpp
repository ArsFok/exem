#include <iostream>
#include <locale.h>
#include "reader.h"

int main(){
    setlocale(LC_ALL, "rus");

    NumberReader file("test.txt");
    int num = file.getNumber();
    std::cout << num << std::endl;
    file.setNumber(42);
    num = file.getNumber();
    std::cout << num << std::endl;
    file.setNumber(100);
    num = file.getNumber();
    std::cout << num << std::endl;
    return 0;
}