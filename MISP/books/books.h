#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

class Book {
private:
    std::string title;
    std::string author;
    unsigned publishYear;

public:
    // Конструктор по умолчанию
    Book() : title(""), author(""), publishYear(0) {}

    // Конструктор с параметрами
    Book(const std::string& t, const std::string& a, unsigned year)
        : title(t), author(a), publishYear(year) {}

    // Геттеры
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    unsigned getYear() const { return publishYear; }
};

// Свободная функция перегрузки оператора ==
bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.getTitle() == rhs.getTitle() &&
           lhs.getAuthor() == rhs.getAuthor() &&
           lhs.getYear() == rhs.getYear();
}

class DBBooks {
private:
    std::vector<Book> books;

public:
    // Конструктор по умолчанию
    DBBooks() {}

    // Добавление книги
    bool addBook(const Book& book) {
        // Проверяем, есть ли уже такая книга
        auto it = std::find(books.begin(), books.end(), book);
        if (it != books.end()) {
            return false; // Книга уже существует
        }
        books.push_back(book);
        return true;
    }

    // Сохранение данных в файл по авторам
    bool save(const std::string& fileName) {
        std::ofstream outFile(fileName);
        if (!outFile.is_open()) {
            return false;
        }

        // Группируем книги по авторам
        std::map<std::string, std::vector<Book>> booksByAuthor;
        for (const auto& book : books) {
            booksByAuthor[book.getAuthor()].push_back(book);
        }

        // Записываем в файл
        for (const auto& pair : booksByAuthor) {
            outFile << pair.first << ":\n";
            for (const auto& book : pair.second) {
                outFile << book.getTitle() << " " << book.getYear() << "\n";
            }
        }

        outFile.close();
        return true;
    }
};

// Пример использования
int main() {
    DBBooks db;

    Book b1("Война и мир", "Толстой", 1869);
    Book b2("Анна Каренина", "Толстой", 1877);
    Book b3("Преступление и наказание", "Достоевский", 1866);
    Book b4("Война и мир", "Толстой", 1869); // дубликат

    std::cout << "Добавление b1: " << db.addBook(b1) << std::endl; // 1
    std::cout << "Добавление b2: " << db.addBook(b2) << std::endl; // 1
    std::cout << "Добавление b3: " << db.addBook(b3) << std::endl; // 1
    std::cout << "Добавление b4 (дубликат): " << db.addBook(b4) << std::endl; // 0

    if (db.save("books.txt")) {
        std::cout << "Сохранение выполнено успешно.\n";
    } else {
        std::cout << "Ошибка сохранения.\n";
    }

    return 0;
}