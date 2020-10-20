CC=clang++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o parser.o
	$(CC) main.o parser.o $(FLAGS) -o main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

parser.o: parser.cpp parser.hpp
	$(CC) $(FLAGS) -c parser.cpp

test: 
	./main

clean:
	rm -rf *.o main