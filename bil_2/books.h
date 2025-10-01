#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>

class Book{
public:
    std::string title;
    std::string author;
    unsigned publishYear;

    Book();
    Book(const std::string& title, const std::string& author, unsigned year);

    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned getYear() const;

    friend bool operator==(const Book& lhs, const Book& rhs);
    ~Book();
};
bool operator==(const Book& lhs, const Book& rhs);

class DBBooks{
private:
    std::vector<Book> books;
public:
    DBBooks();
    bool addBook(const Book& book);
    bool save(const std::string& fileName);

    size_t getBookCount() const;
};

#endif