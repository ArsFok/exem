#include <iostream>
#include "books.h"

Book::Book() : title(""), author(""), publishYear(0){}

Book::Book(std::string new_title, std::string new_author, unsigned new_publishYear) : title(new_title), author(new_author), publishYear(new_publishYear){}

Book::~Book(){}

void Book::print() {
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Publish Year: " << publishYear << "\n";
    std::cout << "-------------------\n";
}

std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

unsigned Book::getYear(){
    return publishYear;
}

DBBooks::DBBooks(std::string title, std::string author, unsigned publishYear) : Book(title, author, publishYear){}
