CXX = clang++-14
CXXFLAGS = -std=c++2a -g -Wall

OBJS = Board.o Vertex.o

all: $(OBJS)

Board.o: Board.cpp Board.hpp
    $(CXX) $(CXXFLAGS) -c Board.cpp

Vertex.o: Vertex.cpp Vertex.hpp
    $(CXX) $(CXXFLAGS) -c Vertex.cpp

clean:
    rm -f *.o