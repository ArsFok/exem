// Реализуйте программу, которая измеряет время рекации пользователя. 
// Программа должна выводить сообщение, затем ждать, пока пользователь введет что-то с клавиатуры, 
// и измерять время между выводом сообщения и вводом пользователя. 
// Вывести полученное время в секундах, миллисекундах и микроссекундах   
#include <iostream>
#include <chrono>
#include <string>

int main() {
    std::cout << "Нажмите любую клавишу и Enter как можно быстрее..." << std::endl;
    
    // Ждём, пока пользователь нажмёт Enter для начала
    std::cin.ignore();
    
    // Запускаем таймер
    auto start = std::chrono::high_resolution_clock::now();
    
    std::cout << "БЫСТРО! Нажмите Enter: ";
    
    // Ждём ввода пользователя
    std::cin.ignore();
    
    // Останавливаем таймер
    auto end = std::chrono::high_resolution_clock::now();
    
    // Вычисляем разницу во времени
    auto duration = end - start;
    
    // Получаем время в различных единицах
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);

    std::cout << "\nВаше время реакции:" << std::endl;
    std::cout << "Секунды: " << seconds.count() << std::endl;
    std::cout << "Миллисекунды: " << milliseconds.count() << std::endl;
    std::cout << "Микросекунды: " << microseconds.count() << std::endl;
    
    return 0;
}