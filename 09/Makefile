CC=clang++
FLAGS=-std=c++17 -pthread -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o sort.o
	$(CC) main.o sort.o $(FLAGS) -o main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

sort.o: sort.cpp sort.hpp
	$(CC) $(FLAGS) -c sort.cpp

test: 
	./main

clean:
	rm -rf *.o main