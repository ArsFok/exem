#include <iostream>
#include "books.h"

int main() {
    DBBooks db;
    
    // Создаем книги
    Book book1("Война и мир", "Лев Толстой", 1869);
    Book book2("Анна Каренина", "Лев Толстой", 1877);
    Book book3("Преступление и наказание", "Федор Достоевский", 1866);
    Book book4("Идиот", "Федор Достоевский", 1869);
    
    // Добавляем книги в базу данных
    std::cout << "Добавление книг:\n";
    std::cout << "Книга 1: " << (db.addBook(book1) ? "true" : "false") << "\n";
    std::cout << "Книга 2: " << (db.addBook(book2) ? "true" : "false") << "\n";
    std::cout << "Книга 3: " << (db.addBook(book3) ? "true" : "false") << "\n";
    std::cout << "Книга 4: " << (db.addBook(book4) ? "true" : "false") << "\n";
    
    // Пытаемся добавить дубликат
    Book book5("Война и мир", "Лев Толстой", 1869);
    std::cout << "Дубликат книги 1: " << (db.addBook(book5) ? "true" : "false") << "\n";
    
    // Сохраняем в файл
    if (db.save("books.txt")) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    
    std::cout << "Всего книг в базе: " << db.getBookCount() << "\n";
    
    return 0;
}