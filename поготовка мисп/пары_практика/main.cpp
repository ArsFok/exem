/*В файле построчно записаны значения вида:
<Фамилия_студента номер_студенческого средний_балл>. 
Считать данные в std::map, при чтении повторяющегося ключа значение 
не должно быть перезаписано. 
Удалить студентов из std::map у которых средний балл менее 3.0.
Вывести полученные значения на экран.
std::map<std::string, std::pair<int, double>> _map; */


#include <iostream>
#include <map>
#include <string>
#include <fstream>

int main() {
    std::map<std::string, std::pair<int, double>> students;
    std::ifstream file("students.txt");
    
    std::string surname;
    int id;
    double avg;
    
    // Чтение из файла
    while (file >> surname >> id >> avg) {
        // Проверяем, есть ли уже такой студент
        if (students.find(surname) == students.end()) {
            students[surname] = std::make_pair(id, avg);
        }
    }
    
    // Удаление студентов с баллом < 3.0
    for (auto it = students.begin(); it != students.end(); ) {
        if (it->second.second < 3.0) {
            it = students.erase(it);
        } else {
            ++it;
        }
    }
    
    // Вывод результатов (обычный способ)
    std::cout << "Результаты:" << std::endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        std::cout << it->first << " " 
                  << it->second.first << " " 
                  << it->second.second << std::endl;
    }
    
    return 0;
}