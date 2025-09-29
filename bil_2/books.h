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
    Book(std::string new_title, std::string new_author, unsigned new_publishYear);
    void print();
    std::string getTitle();
    std::string getAuthor();
    unsigned getYear();

    ~Book();
};
class DBBooks : public Book{
public:
    DBBooks(std::string title, std::string author, unsigned publishYear);
private:
    std::vector<Book> books;
};

#endif