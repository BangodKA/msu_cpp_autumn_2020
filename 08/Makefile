CC=clang++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o
	$(CC) main.o $(FLAGS) -o main

main.o: main.cpp pool.hpp pool.tpp
	$(CC) $(FLAGS) -c main.cpp

test: 
	./main

clean:
	rm -rf *.o main