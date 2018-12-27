all: code
.PHONY : clean 
code: gtest.cpp
	g++ gtest.cpp -lgtest -lgtest_main -pthread
clean:
	rm -rf *.o *.out 
