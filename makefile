CXX = clang++-14
CXXFLAGS = -std=c++2a -g -Wall -O0

BOARD_OBJS = ./catanBoard/Board.o ./catanBoard/Vertex.o
DCARDS_OBJS = ./DCards/DevelopmentCard.o ./DCards/KnightCard.o ./DCards/MonopolyCard.o ./DCards/RoadBuildingCard.o ./DCards/YearOfPlentyCard.o ./DCards/VictoryPointCard.o 
CATAN_OBJS = Catan.o Trade.o main.o 


VALGRIND_FLAGS=--tool=memcheck -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

PROG = catan

all: $(PROG)

$(PROG): $(BOARD_OBJS) $(DCARDS_OBJS) $(CATAN_OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(BOARD_OBJS) $(DCARDS_OBJS) $(CATAN_OBJS)

Catan.o: Catan.cpp
	$(CXX) $(CXXFLAGS) -c Catan.cpp -o Catan.o

Trade.o: Trade.cpp
	$(CXX) $(CXXFLAGS) -c Trade.cpp -o Trade.o

test: tests.o $(BOARD_OBJS) $(DCARDS_OBJS) $(CATAN_OBJS)
	$(CXX) $(CXXFLAGS) -o test tests.o $(BOARD_OBJS) $(DCARDS_OBJS) Catan.o Trade.o
	./test

tests.o: tests.cpp
	$(CXX) $(CXXFLAGS) -c tests.cpp -o tests.o

.PHONY: clean run valgrind catanBoard DCards

run: $(PROG)
	./$(PROG)

valgrind: $(PROG)
	valgrind $(VALGRIND_FLAGS) ./$< 2>&1


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

catanBoard:
	make -C catanBoard

DCards:
	make -C DCards

clean:
	rm -f $(PROG) $(BOARD_OBJS) $(DCARDS_OBJS) $(CATAN_OBJS) tests.o test 