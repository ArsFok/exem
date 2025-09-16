#include <iostream>
#include "books.h"

int main(){
    Book book1("War and Peace", "Leo Tolstoy", 1869);
    Book book2("Crime and Punishment", "Fyodor Dostoevsky", 1866);
    Book book3("Master and Margarita", "Mikhail Bulgakov", 1967);

    std::cout << "\nFirst book info:\n";
    std::cout << "Title: " << book1.getTitle() << "\n";
    std::cout << "Author: " << book1.getAuthor() << "\n";
    std::cout << "Year: " << book1.getYear() << "\n";
    return 0;
}