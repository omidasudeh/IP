# basic c++ make file for compiling and linking
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -g

all: main

main: main.o
	$(CXX) -o main main.o

clean:
	rm -f main main.o
