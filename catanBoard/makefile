CXX = clang++-14
CXXFLAGS = -std=c++2a -g -Wall

.PHONY: all clean

all: Board.o

Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

clean:
	rm -f *.o


