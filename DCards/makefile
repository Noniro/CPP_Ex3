CXX = clang++-14
CXXFLAGS = -std=c++2a -g -Wall

OBJS = DevelopmentCard.o KnightCard.o MonopolyCard.o RoadBuildingCard.o YearOfPlentyCard.o VictoryPointCard.o 

all: $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS)