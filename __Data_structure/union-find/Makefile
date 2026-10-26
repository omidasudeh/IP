# basic c++ make file for compiling and linking
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -g

all: unionFind

unionFind: unionFind.o
	$(CXX) -o unionFind unionFind.o

clean:
	rm -f unionFind unionFind.o
