#include "copyfile.h"
#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    char sourse[256];
    char destination[256];

    if(argc == 3){
        std::strcpy(sourse, argv[1]);
        std::strcpy(destination, argv[2]);
    }else if(argc = 1){
        std::cout << "Введите название исходного файла: ";
        std::cin.getline(sourse, sizeof(sourse));
        std::cout << "Введите название конечного файла: ";
        std::cin.getline(destination, sizeof(destination)); 
    }else{
        std::cout << "Используйте: " << argv[0] << " <sourse> <destination>" << std::endl;
        std::cout << "Или запустите без аргументов в интерактивном режиме" << std::endl;
        return 1;
    }

    bool success = false;
    while(!success){
        try{
            copyFile(sourse, destination);
            success = true;
        }catch (const FileNotFound& e){
            std::cout << "ERROR: " << e.what() << std::endl;
            std::cout << "Пожалуйста введите корректный исходный файл: ";
            std::cin.getline(sourse, sizeof(sourse));
        }catch (const Overwriting& e){
            std::cout << "ERROR: " << e.what() << std::endl;
            char response;
            std::cout << "Ты хочешь перезаписать файл? (Y|N)";
            std::cin >> response;
            std::cin.ignore(); //очистка буфера, чтобы потом можно было спокойно ввести новую информацию

            if(response == 'y' || response == 'Y'){
                std::remove(destination);
            }else{
                std::cout << "Пожалуйста введите корректный конечный файл: ";
                std::cin.getline(destination, sizeof(destination));
            }
        }catch (const std::exception& e){
            std::cout << "Неизвестная ошибка: " << e.what() << std::endl;
            break;
        }
    }
    if(success){
        std::cout << "Файл скипирован успешно!" << std::endl;
    }
    return 0;
}