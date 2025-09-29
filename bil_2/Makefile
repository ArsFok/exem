.PHONY: all clean

all: book

book: main.o books.o
	g++ main.o books.o -o book
	rm -f *.o

main.o: main.cpp books.h
	g++ -Wall -Wextra -c main.cpp -o main.o

books.o: books.cpp books.h
	g++ -Wall -Wextra -c books.cpp -o books.o

clean:
	rm -rf book