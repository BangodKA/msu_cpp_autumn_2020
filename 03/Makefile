CC=clang++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o matrix.o
	$(CC) main.o matrix.o $(FLAGS) -o main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	$(CC) $(FLAGS) -c matrix.cpp

test: 
	./main

clean:
	rm -rf *.o main