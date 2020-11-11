CC=clang++
FLAGS=-std=c++17 -Wall -pedantic -Wextra -Wno-unused-variable

all: main

main: main.o
	$(CC) main.o $(FLAGS) -o main

main.o: main.cpp serializer.hpp serializer.tpp deserializer.hpp deserializer.tpp data.hpp data.tpp error.hpp
	$(CC) $(FLAGS) -c main.cpp

test: 
	./main

clean:
	rm -rf *.o main