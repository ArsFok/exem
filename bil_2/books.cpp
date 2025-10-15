#include "books.h"
#include <algorithm>
#include <fstream>

Book::Book() : title(""), author(""), publishYear(0){}

Book::Book(const std::string& title, const std::string& author, unsigned year) : title(title), author(author), publishYear(year){}

Book::~Book(){}

std::string Book::getTitle() const{
    return title;
}

std::string Book::getAuthor() const{
    return author;
}

unsigned Book::getYear() const{
    return publishYear;
}
bool operator==(const Book& lhs, const Book& rhs){
    return lhs.title == rhs.title && lhs.author ==  rhs.author && lhs.publishYear == rhs.publishYear;
}
DBBooks::DBBooks() = default; 

bool DBBooks::addBook(const Book& book){
    auto it = std::find(books.begin(), books.end(), book);
    if(it != books.end()){
        return false;
    }

    books.push_back(book);
    return true;
}

bool DBBooks::save(const std::string& fileName){
    std::ofstream file(fileName);
    if(!file.is_open()){
        return false;
    }
    std::vector<std::string> authors;
    for(const auto& book : books){
        if(std::find(authors.begin(), authors.end(), book.getAuthor()) == authors.end()){
            authors.push_back(book.getAuthor());
        }
    }
    for(const auto& author : authors){
        file << author << ":\n";
        for(const auto& book : books){
            if(book.getAuthor() == author){
                file << book.getTitle() << " " << book.getYear() << "\n";
            }
        }
        file << "\n";
    }
    file.close();
    return true;
}

size_t DBBooks::getBookCount() const{
    return books.size();
}
