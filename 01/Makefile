CC=clang++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o task.o
	$(CC) main.o task.o $(FLAGS) -o main

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

task.o: task.cpp task.hpp
	$(CC) $(FLAGS) -c task.cpp

test: 
	./main

clean:
	rm -rf *.o my_prog